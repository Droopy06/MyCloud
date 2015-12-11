//============================================================================
// Name        : LibLog.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Generate log info or error
//============================================================================

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <string>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>

class Log {

public:

	void info(const std::string & data) {
		std::cout << get_time_log() << " [ info ] : " << data << std::endl;
	}

	void error(const std::string & data) {
		std::cout << get_time_log() << " [ error ] : " << data << std::endl;
	}

private:

	const boost::posix_time::ptime get_time_log(){
		using namespace boost::posix_time;
		ptime const date_time = microsec_clock::local_time();
		return date_time;
	}
};
