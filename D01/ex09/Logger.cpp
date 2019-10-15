#include "Logger.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

Logger::Logger(const std::string filename) :
_fileOut(filename, std::fstream::out | std::fstream::app) {
    if (_fileOut.fail()) {
        std::cout << "Error: " << strerror(errno) << std::endl;
        exit(1);
    }
}

Logger::~Logger() {
    _fileOut.close();
}

std::string Logger::makeLogEntry(const std::string &msg) const {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::string out = "[" + std::to_string(1900 + ltm->tm_year) +
        ((ltm->tm_mon < 10) ? "0" : "") + std::to_string(ltm->tm_mon) +
        std::to_string(ltm->tm_mday) + "_" +
        ((ltm->tm_hour < 10) ? "0" : "") + std::to_string(ltm->tm_hour) +
        ((ltm->tm_min < 10) ? "0" : "") + std::to_string(ltm->tm_min) +
        ((ltm->tm_sec < 10) ? "0" : "") + std::to_string(ltm->tm_sec) + "]";
    out += "[INFO]: " + msg;
    return out;
}

void Logger::logToFile(const std::string &msg) {
    _fileOut << makeLogEntry(msg) << std::endl;
}

void Logger::logToConsole(const std::string &msg) {
    std::cout << makeLogEntry(msg) << std::endl;
}

void Logger::logConsoleAndFile(const std::string &msg) {
    logToFile(msg);
    logToConsole(msg);
}

void Logger::log(const std::string &dest, const std::string &msg) {
    static struct Logging logsFunc[] = {
        {"file", &Logger::logToFile},
        {"logToFile", &Logger::logToFile},
        {"console", &Logger::logToConsole},
        {"out", &Logger::logToConsole},
        {"both", &Logger::logConsoleAndFile},
        {"", &Logger::logConsoleAndFile}  // default is both
    };
    static uint32_t sz = sizeof(logsFunc) / sizeof(logsFunc[0]);

    for (uint32_t i=0; i < sz; i++) {
        if (dest == logsFunc[i].name) {
            ((*this).*(logsFunc[i].f))(msg);
            return;
        }
    }
    std::cout << "invalid log output" << std::endl;
}