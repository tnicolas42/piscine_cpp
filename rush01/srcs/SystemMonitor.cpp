/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SystemMonitor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:33:23 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 15:33:46 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SystemMonitor.hpp"
#include "TimeModule.hpp"
#include "OSInfoModule.hpp"
#include "NameModule.hpp"
#include "CPUModule.hpp"
#include "NetworkModule.hpp"
#include "RAMModule.hpp"
#include "FileModule.hpp"
#include "UptimeModule.hpp"
#include "SFMLMonitorDisplay.hpp"
#include "NcursesMonitorDisplay.hpp"
#include "CoutMonitorDisplay.hpp"
#include <unistd.h>
#include <time.h>
#include <chrono>
#include <fstream>

SystemMonitor::SystemMonitor(void) : _display(nullptr)
{
}

bool SystemMonitor::usage() const {
	std::cerr << "Usage: ./ft_gkrellm [type] [-f fileSettings] [-w width] [-h height]\n"
		<< "\t-g [-w width:" << DEFAULT_WIDTH << "] [-h height:"<< DEFAULT_HEIGHT << "]: init the graphical instance (SFML)\n"
		<< "\t-c: init the console instance (ncurses)\n"
		<< "\t-d: just dump information in console\n"
		<< std::endl;
	return false;
}

bool SystemMonitor::init(int argc, char **argv) {
	uint32_t width = DEFAULT_WIDTH;
	uint32_t height = DEFAULT_HEIGHT;
	std::string filename;
	_display = nullptr;
	int i=1;
	while (i < argc) {
		if (strcmp(argv[i], "-c") == 0) {
			if (_display != nullptr)
				return usage();
			_display = new NcursesMonitorDisplay;
		}
		else if (strcmp(argv[i], "-d") == 0) {
			if (_display != nullptr)
				return usage();
			_display = new CoutMonitorDisplay;
		}
		else if (strcmp(argv[i], "-g") == 0) {
			if (_display != nullptr)
				return usage();
			_display = new SFMLMonitorDisplay;
		}
		else if (strcmp(argv[i], "-w") == 0) {
			++i;
			if (i >= argc)
				return usage();
			width = atoi(argv[i]);
		}
		else if (strcmp(argv[i], "-h") == 0) {
			++i;
			if (i >= argc)
				return usage();
			height = atoi(argv[i]);
		}
		else if (strcmp(argv[i], "-f") == 0) {
			++i;
			if (i >= argc)
				return usage();
			filename = argv[i];
		}
		else
			return usage();
		++i;
	}
	if (_display == nullptr) {
		_display = new SFMLMonitorDisplay;
	}

	// init modules
	/*
	no spaces & all in lowercase
	*/
	_modules_list.insert(std::pair<std::string, AMonitorModule*>("hostname", new NameModule));
	_modules_list.insert(std::pair<std::string, AMonitorModule*>("os", new OSInfoModule));
	_modules_list.insert(std::pair<std::string, AMonitorModule*>("date", new TimeModule));
	_modules_list.insert(std::pair<std::string, AMonitorModule*>("cpu", new CPUModule));
	_modules_list.insert(std::pair<std::string, AMonitorModule*>("ram", new RAMModule));
	_modules_list.insert(std::pair<std::string, AMonitorModule*>("network", new NetworkModule));
	_modules_list.insert(std::pair<std::string, AMonitorModule*>("uptime", new UptimeModule));
	_modules_list.insert(std::pair<std::string, AMonitorModule*>("files", new FileModule));

	if (initModules(filename) == false) {
		return false;
	}

	// width and height are ignored in cout and ncurses display
	if (_display->init(width, height) == false)
		return false;

	return true;
}

bool SystemMonitor::initModules(std::string const &filename) {
	if (filename == "") {
		std::map<std::string, AMonitorModule*>::iterator it;
		for(it = _modules_list.begin(); it != _modules_list.end(); ++it) {
			_modules.push_back(it->second);
		}
		return true;
	}

    std::ifstream fileIn(filename);
    if (fileIn.fail()) {
        std::cerr << "error with settings file: " << strerror(errno) << std::endl;
        return false;
    }

	for (std::string line; std::getline(fileIn, line);) {
		std::string command = line;
		// lowercase line
		for (uint32_t i=0; i < command.length(); ++i) {
			command[i] = std::tolower(command[i]);
		}
		// remove whitespace
		command.erase(std::remove_if(command.begin(), command.end(), ::isspace), command.end());
		if (command.size() == 0 || command[0] == '#')
			continue;

		std::map<std::string, AMonitorModule*>::iterator it = _modules_list.find(command);
		if(it != _modules_list.end()) {
			_modules.push_back(it->second);
		}
		else {
			std::cerr << "invalid command in setting file: " << line << std::endl;
			std::cerr << "available commands:" << std::endl;
			std::map<std::string, AMonitorModule*>::iterator it2;
			for(it2 = _modules_list.begin(); it2 != _modules_list.end(); ++it2) {
				std::cerr << "\t" << it2->first << std::endl;
			}
			return false;
		}
    }
    fileIn.close();

	if (_modules.size() == 0) {
		std::cerr << "error: you need at least one command in settings file" << std::endl;
		return false;
	}
	return true;
}

SystemMonitor::SystemMonitor(SystemMonitor const &instance)
{
	*this = instance;
}

SystemMonitor::~SystemMonitor(void)
{
	delete _display;
	std::map<std::string, AMonitorModule*>::iterator it;
    for (it = _modules_list.begin(); it != _modules_list.end(); it++) {
        delete it->second;
    }
}

SystemMonitor &	SystemMonitor::operator=(SystemMonitor const &rhs)
{
	(void)rhs;
	return *this;
}

bool SystemMonitor::_displayAllMonitors()
{
	std::list<AMonitorModule *>::iterator it;
	AMonitorModule *module;
	it = _modules.begin();
	int i;
	bool res = true;
	i = 0;
	while (it != _modules.end())
	{
		module = *it;
		if (_display->isUnderScreen(MAX_SIZE_ELEMENT) == false) {
			if (_display->isUpperScreen())
				return res;
			if (_display->display(module, i, _modules.size()) == false)
				res = false;
		}
		i++;
		it++;
	}
	return res;
}

bool	SystemMonitor::run(void)
{
	std::chrono::milliseconds	time_start;

	while (_display->isQuit() == false)
	{
		time_start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());

		std::map<std::string, AMonitorModule*>::iterator it;
		for(it = _modules_list.begin(); it != _modules_list.end(); ++it) {
			it->second->retrieveData();
		}

		_display->beforeDisplay();
		_displayAllMonitors();
		_display->afterDisplay();

        std::chrono::milliseconds time_loop = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()) - time_start;
		if (time_loop.count() < LOOP_TIME)
			usleep((LOOP_TIME - time_loop.count()) * 1000);
	}
	return true;
}
