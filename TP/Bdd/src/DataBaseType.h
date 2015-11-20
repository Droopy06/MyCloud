#ifndef DATABASETYPE_H
#define DATABASETYPE_H
#include <string>
using namespace std;
namespace db{
    template<typename _DataBaseType>
    class DataBaseType
    {
        public:
            DataBaseType(const string & database);
            DataBaseType(const string & user, const string & password, const string & database);
            const string getUser(const string & login, const string & password){
                    return db->getUser(login, password);
            }
            virtual ~DataBaseType();
        protected:
        private:
            _DataBaseType * db;
    };
    template<typename _DataBaseType>
    DataBaseType<_DataBaseType>::DataBaseType(const string & database)
    {
        //ctor
        db = new _DataBaseType(database);
    }

    template<typename _DataBaseType>
    DataBaseType<_DataBaseType>::DataBaseType(const string & user, const string & password, const string & database)	{
        db = new _DataBaseType(user, password, database);
    }

    template<typename _DataBaseType>
    DataBaseType<_DataBaseType>::~DataBaseType()
    {
        //dtor
        delete db;
    }
}


#endif // DATABASETYPE_H
