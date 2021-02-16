#include <algorithm>
#include <cstdint>
#include <iostream>
#include <mutex>
#include <string>

#ifndef LUCERNE_LOGGER_HPP
#define LUCERNE_LOGGER_HPP

namespace logger {
    enum class LogType {
        ERROR = 0,
        WARNING,
        INFO,
        DEBUG,
    };

    std::string Log(LogType logtype, std::string name, std::string message);

    class Logger {
        static std::once_flag env_set;
        static LogType env_log;
        std::string name;
        bool is_filelogging;
    private:
    public:
        Logger(std::string logname = "<NONAME>") {
            if (logname.empty()) {
                this->name = "<NONAME>";
            }
            this->name = logname;
            this->is_filelogging = false;
        }
        void Debug(std::string message);
        void Info(std::string message);
        void Warn(std::string message);
        void Error(std::string message);
    };
}

#endif