#ifndef MYSQL_H
#define MYSQL_H
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>
#include <string>
using namespace std;


class MySQL
{
    public:
        MySQL(const string & user, const string & password, const string & database);
        const string getUser(const string & nom, const string & password);
        const string getLastDateUser(const string & nom, const string & password);
        const string insertUser(const string & nom,const string & prenom,const string & pseudo,
                                const string & password, const string & ip,const string & adresseMail,
                                const string & tokenConf);
        virtual ~MySQL();
    protected:
    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
};

#endif // MYSQL_H
