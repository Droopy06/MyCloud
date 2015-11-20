#include <iostream>
#include <string.h>
#include "DataBaseType.h"
#include "MySQL.h"
#include "SQLite.h"
using namespace std;
int main()
{
    cout << "Hello world!" << endl;
    db::DataBaseType<MySQL> dbMySQL("mycloud", "mycloud", "mycloud") ;
    string idMySQL = dbMySQL.getUser("root", "");
    cout << "Test MySQL" << endl << "idMySQL : " << idMySQL << endl;

    /*db::DataBaseType<SQLite> dbSQLite("/home/web2014/temp/mycloud.sqlite3") ;
    string idSQLite = dbSQLite.getUser("root", "");
    cout << "Test SQLite" << endl << "idSQLite : " << idSQLite << endl;*/
    return 0;
}
