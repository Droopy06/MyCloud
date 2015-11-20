#include "MySQL.h"
#include "sha256.h"

MySQL::MySQL(const string & user, const string & password, const string & database)
{
    //ctor
    driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://vps132557.ovh.net:3306", user, password);
	con->setSchema(database);
}

MySQL::~MySQL()
{
    //dtor
    delete con;
}

const string MySQL::getUser(const string & login, const string & password)	{
	sql::PreparedStatement *pstmt;
	pstmt = con->prepareStatement("SELECT id FROM user WHERE login=? and mdp=?");
	pstmt->setString(1, login);
	pstmt->setString(2, sha256(password));
	sql::ResultSet * res = pstmt->executeQuery();
	string id = "";
	if (res->next())	{
		id = res->getString(1);
	}
	delete res;
	delete pstmt;
	return id;
}

const string MySQL::getLastDateUser(const string & login, const string & password)	{
	sql::PreparedStatement *pstmt;
	pstmt = con->prepareStatement("SELECT dateSyn FROM user WHERE login=? and mdp=?");
	pstmt->setString(1, login);
	pstmt->setString(2, sha256(password));
	sql::ResultSet * res = pstmt->executeQuery();
	string date = "";
	if (res->next())	{
		date = res->getString(1);
	}
	delete res;
	delete pstmt;
	return date;
}

const string MySQL::insertUser(const string & nom,const string & prenom,const string & pseudo, const string & password, const string & ip,const string & adresseMail,const string & tokenConf)	{
	sql::PreparedStatement *pstmt;
	pstmt = con->prepareStatement("INSERT INTO User(nom, prenom, pseudo, mdp, ip, adresseMail, tokenConf) VALUES (?,?,?,?,?,?,?");
	pstmt->setString(1, nom);
	pstmt->setString(2, prenom);
	pstmt->setString(3, pseudo);
	pstmt->setString(4, sha256(password));
	pstmt->setString(5, ip);
	pstmt->setString(6, adresseMail);
	pstmt->setString(7, tokenConf);
	sql::ResultSet * res = pstmt->executeQuery();
	string date = "";
	if (res->next())	{
		date = res->getString(1);
	}
	delete res;
	delete pstmt;
	return date;
}
