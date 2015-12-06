/*
 * Info.h
 *
 *  Created on: 28 oct. 2014
 *      Author: nicolas
 */

#ifndef INFO_H_
#define INFO_H_

#include <string>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace mycloud {
namespace model {
class info {
private:
	std::string addressMail;
	std::string pwd;
	friend class boost::serialization::access;
	template<class Archive> void serialize(Archive & ar, const unsigned int version) {
		ar & addressMail;
		ar & pwd;
	}
public:
	info()	{}
	~info() {}

	const std::string& getAddressMail() const {
		return addressMail;
	}

	void setAddressMail(const std::string& addressMail) {
		this->addressMail = addressMail;
	}

	const std::string& getPwd() const {
		return pwd;
	}

	void setPwd(const std::string& pwd) {
		this->pwd = pwd;
	}
};
}
}

#endif /* INFO_H_ */
