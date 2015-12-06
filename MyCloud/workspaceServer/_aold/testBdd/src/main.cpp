#include <iostream>
#include <string.h>
#include "DataBaseType.h"
#include "MySQl.h"

using namespace std;

int main()
{
    db::DataBaseType<MySQL> dbMySQL("root", "123456", "mycloud") ;
    string idMySQL = dbMySQL.getUser("root", "123456");
    //string dateMySQL = dbMySQL.getLastDateUser("root", "");
    cout << "Test MySQL" << endl << "idMySQL : " << idMySQL << endl;
    //cout << "Test MySQL" << endl << "dateMySQL : " << dateMySQL << endl;
    return 0;
}
