/*
 * file.h
 *
 *  Created on: Oct 23, 2015
 *      Author: steven
 */

#include "File.h"
#include <fstream>

int main(int argc, char* argv[]) {
	std::string pathInfo("/home/steven/Documents/aze.xml");
	std::ofstream ofs(pathInfo.c_str());

	const File file("/home/steven/Documents/aze");
	{
		boost::archive::xml_oarchive oa(ofs);
		oa << boost::serialization::make_nvp("option", file);
	}

	return 0;
}
