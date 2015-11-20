//============================================================================
// Name        : MyCloud.cpp
// Author      : Alexandre Steven
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <LibPath.cpp>
#include <fstream>

int main(int argc, char* argv[]) {
	std::string pathInfo("/home/steven/Documents/aze.xml");
	std::ofstream ofs(pathInfo.c_str());

	const File file("/home/steven/Documents/azeaze");
	{
		boost::archive::xml_oarchive oa(ofs);
		oa << boost::serialization::make_nvp("option", file);
	}

	return 0;
}
