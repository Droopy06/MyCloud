#ifndef SQLITE_H
#define SQLITE_H
#include <sqlite3.h>
#include <string>

using namespace std;

class SQLite
{
    public:
        SQLite(const string & database);
        const string getUser(const string & login, const string & password);
        virtual ~SQLite();
    protected:
    private:
        sqlite3 *db;
};

#endif // SQLITE_H
