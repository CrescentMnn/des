#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {

private:
	static bool verbose;

public:
	static void setVerbose(bool v);
	static void log(const std::string& msg);
};

#endif
