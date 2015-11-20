#include "SQLite.h"

SQLite::SQLite(const string & database)
{
    //ctor
    if( sqlite3_open(database.c_str(), &db) ){
		throw string("Impossible d'ouvrir la base de données.");
	}
}

SQLite::~SQLite()
{
    //dtor
    sqlite3_close(db);
}

const string SQLite::getUser(const string & login, const string & password)	{
	sqlite3_stmt *stmt;
	string query = "SELECT id FROM user WHERE login=? and password=?";

	if ( sqlite3_prepare(db, query.c_str(), query.size(), &stmt, NULL ) != SQLITE_OK) {
		throw string("Erreur lors de l'appel de la fonction sqlite3_prepare.");
	}

	if (sqlite3_bind_text(stmt, 1, login.c_str(), login.size(),0) != SQLITE_OK) {
		throw string("Erreur lors de l'appel de la fonction sqlite3_bind_text.");
	}

	if (sqlite3_bind_text(stmt, 2, password.c_str(), password.size(),0) != SQLITE_OK) {
		throw string("Erreur lors de l'appel de la fonction sqlite3_bind_text.");
	}

	sqlite3_step( stmt );

	string id = (char*) sqlite3_column_text( stmt, 0 );

	sqlite3_finalize(stmt);

	return id;
}
