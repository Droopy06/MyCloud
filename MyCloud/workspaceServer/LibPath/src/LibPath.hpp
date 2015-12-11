/*
 * file.h
 *
 *  Created on: Oct 23, 2015
 *      Author: steven
 */

#include <sstream>

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <LibLog.hpp>
#include <vector>
#include <fstream>


using namespace boost::filesystem;

class File {
private:
	int size_of_file;
	std::string type_of_file;
	std::string date_update;
	Log log;

	friend class boost::serialization::access;
	template<class Archive> void serialize(Archive & ar,
			const unsigned int version) {
		ar & boost::serialization::make_nvp("options", size_of_file);
		ar & boost::serialization::make_nvp("options", type_of_file);
		ar & boost::serialization::make_nvp("options", date_update);
	}

public:

	File(const std::string& path) {
		all_set(path);
	}

	File(const std::string& path,const std::string& idUser){
		checkPathServer(path, idUser);
	}

	void checkPathServer(const std::string& path, const std::string& idUser){
		if(!boost::filesystem::exists(path)){
			boost::filesystem::create_directories(path);
		}
		if(!boost::filesystem::exists(path + idUser + "/")){
			boost::filesystem::create_directories(path + idUser + "/");
		}
		if(!boost::filesystem::exists(path + idUser + "/referencement.xml")){
			std::string pathInfo(path + idUser + "/referencement.xml");
			std::ofstream ofs(pathInfo.c_str());
		}
	}

	void all_set(const std::string& path) {
		if (exists(path)) {
			set_type(path);
			set_size(path);
			set_date(path);
		} else {
			log.error("un problème est survenu le dossier/fichier/autre n'existe pas");
		}

	}

	void set_type(const std::string& path) {
		if (is_regular_file(path)) {
			type_of_file = "file";
		}
		if (is_directory(path)) {
			type_of_file = "directory";
		}
		if (is_other(path)) {
			type_of_file = "other";
		}
	}

	const std::string get_type() {
		return type_of_file;
	}

	void set_size(const std::string& path) {
		size_of_file = file_size(path);
	}

	const int get_size() {
		return size_of_file;
	}

	void set_date(const std::string& path) {
		time_t t = last_write_time(path);
		date_update = std::ctime(&t);
	}

	const std::string get_date() {
		return date_update;
	}

	void view(const std::string& p) {
		std::cout << "info : " << p << std::endl;
	}

};
