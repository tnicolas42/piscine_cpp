#pragma once

#include <string>
#include <fstream>

class Logger {
    public:
        Logger(const std::string filename);
        ~Logger();

        void log(const std::string &dest, const std::string &msg);
    protected:
    private:
        std::ofstream _fileOut;

        void logConsoleAndFile(const std::string &msg);
        void logToFile(const std::string &msg);
        void logToConsole(const std::string &msg);
        std::string makeLogEntry(const std::string &msg) const;


        typedef void (Logger::*logFunc)(const std::string &msg);
        struct Logging {
            std::string name;
            logFunc f;
        };
};