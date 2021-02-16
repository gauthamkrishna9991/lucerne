// include to provide defs for "Logger.hpp"
#include "Logger.hpp"

void cli_log(logger::LogType logtype, std::string name, std::string message) {
    std::cout << logger::Log(logtype, name, message) << std::endl;
}

static const char* error_msg = "ERROR";
static const char* warning_msg = "WARN";
static const char* info_msg =  "INFO";
static const char* debug_msg = "DEBUG";

std::string logger::Log(logger::LogType logtype,std::string name, std::string message) {
    std::string logstring = "";
    switch (logtype) {
        case LogType::ERROR:
            logstring += error_msg;
            break;
        case LogType::WARNING:
            logstring += warning_msg;
            break;
        case LogType::INFO:
            logstring += info_msg;
            break;
        case LogType::DEBUG:
            logstring += debug_msg;
            break;
        default:
            logstring += error_msg;
    }
    return logstring + " @ " + name + ": " + message;
}

//  Logger Class:

//  - Logger Functions:

// Debug function
void logger::Logger::Debug(std::string message) {
    cli_log(logger::LogType::DEBUG,this->name,message);
}

//    - Info
void logger::Logger::Info(std::string message) {
    cli_log(logger::LogType::INFO, this->name, message);
}

//    - Warn
void logger::Logger::Warn(std::string message) {
    cli_log(logger::LogType::WARNING, this->name, message);
}

//    - Error
void logger::Logger::Error(std::string message) {
    cli_log(logger::LogType::ERROR, this->name, message);
}
