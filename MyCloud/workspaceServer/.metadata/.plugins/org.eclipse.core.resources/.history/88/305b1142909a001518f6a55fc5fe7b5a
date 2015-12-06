#include <iostream>
#include <string.h>
#include "DataBaseType.h"
#include "MySQl.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    db::DataBaseType<MySQL> dbMySQL("root", "", "mycloud") ;
    string idMySQL = dbMySQL.getUser("root", "");
    string dateMySQL = dbMySQL.getLastDateUser("root", "");
    cout << "Test MySQL" << endl << "idMySQL : " << idMySQL << endl;
    cout << "Test MySQL" << endl << "dateMySQL : " << dateMySQL << endl;
    return 0;
}
