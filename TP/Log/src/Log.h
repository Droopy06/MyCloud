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
		std::cout << "/!\\ alerte /!\\: " << data << std::endl;
	}
};

class ManagerFileSystem {

public:
	typedef boost::signals2::signal<void(const std::string & data)> signal_t;

	ManagerFileSystem(Log log) :
		m_log(log) {
		m_connection = connect(boost::bind(&Log::alerte, log, _1));
		m_sig("Connect");
	}

	~ManagerFileSystem() {
		m_connection.disconnect();

	}

	boost::signals2::connection connect(const signal_t::slot_type &subcriber) {
		return m_sig.connect(subcriber);
	}

	void readFile() {
		m_sig("read file");
	}
private:
	Log & m_log;
	signal_t m_sig;
	boost::signals2::connection m_connection;
};

