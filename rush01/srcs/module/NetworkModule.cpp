/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NetworkModule.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:54:05 by ldedier           #+#    #+#             */
/*   Updated: 2019/10/27 15:28:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NetworkModule.hpp"
#include <array>

std::string NetworkModule::_titles[NB_ATTRIBUTES_NETWORK] = {
	"ip en0",
	"Packets in",
	"Packets out",
};


NetworkModule::NetworkModule(void) : AAttributeListMonitorModule("Network", NB_ATTRIBUTES_NETWORK, NetworkModule::_titles)
{
	
}

NetworkModule::NetworkModule(NetworkModule const &instance): AAttributeListMonitorModule(instance)
{
	
}

NetworkModule::~NetworkModule(void)
{
	
}

NetworkModule &	NetworkModule::operator=(NetworkModule const &rhs)
{
	static_cast<void>(rhs);
	return *this;
}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
	if (result[result.size()-1] == '\n')
		result = result.substr(0, result.size()-1);
    return result;
}

bool	NetworkModule::retrieveData(void)
{
	try {
		_attributes[0].setValue(exec("ipconfig getifaddr en0"));
		_attributes[1].setValue(exec("netstat -i | grep en0 | grep '.loc' | awk '{print $5}'"));
		_attributes[2].setValue(exec("netstat -i | grep en0 | grep '.loc' | awk '{print $7}'"));
	}
	catch (std::runtime_error &e) {
		_attributes[0].setValue("ERROR");
		_attributes[1].setValue("ERROR");
		_attributes[2].setValue("ERROR");
		return false;
	}
	return true;
}