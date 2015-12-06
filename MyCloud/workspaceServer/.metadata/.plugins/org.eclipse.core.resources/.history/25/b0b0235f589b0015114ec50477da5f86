/*
 * main.cpp
 *
 *  Created on: 28 oct. 2014
 *      Author: nicolas
 */

#include <string.h>
#include <iostream>

#include <boost/lexical_cast.hpp>

#include "../model/info.hpp"
#include "../service/server.hpp"
#include <vector>
#include <fstream>

namespace mycloud {

int run_server() {
	try {
		unsigned short port = boost::lexical_cast<unsigned short>(5554);
		boost::asio::io_service io_service;
		service::server server(io_service, port);
		io_service.run();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
}

int main(int argc, char ** argv) {
	std::cout << "server" << std::endl;
	mycloud::run_server();

	return 0;
}
