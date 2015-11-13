#include <iostream>
#include <string>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>

class Log {
public:
	Log() {
	}
	void info(const std::string & data) const {
		std::cout << "info : " << data << std::endl;
	}
	void alerte(const std::string & data) const {
		std::cout << "/!\\ alerte /!\\ : " << data << std::endl;
	}
};
