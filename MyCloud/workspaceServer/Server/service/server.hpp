/*
*	server.hpp
 *
 *  Created on: 28 oct. 2014
 *      Author: nicolas
 */

#include <LibPath.hpp>
#include "DataBaseType.h"
#include "MySQl.h"
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include "connection.hpp" // serialisation
#include <boost/serialization/vector.hpp>
#include "../model/info.hpp"
#include <fstream>

namespace mycloud {
namespace service{

class server
{
public:
	// constucteur
	server(boost::asio::io_service& io_service, unsigned short port)
: acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
		// accepte une nouvelle connexion
		connection_ptr new_conn(new connection(acceptor_.get_io_service()));
		acceptor_.async_accept(new_conn->socket(), boost::bind(&server::handle_accept, this, boost::asio::placeholders::error, new_conn));
	}
	/// handle appelé après acceptation
	void handle_accept(const boost::system::error_code& e, connection_ptr conn)	{
		if (!e)	{	// acceptation réussie
			// lecture des informations
			conn->async_read(infos, boost::bind(&server::handle_read, this, boost::asio::placeholders::error, conn));
		}
		// démarrage d'une nouvelle connection
		connection_ptr new_conn(new connection(acceptor_.get_io_service()));
		acceptor_.async_accept(new_conn->socket(), boost::bind(&server::handle_accept, this, boost::asio::placeholders::error, new_conn));

	}
	// handle appelé après lecture
	void handle_read(const boost::system::error_code& e, connection_ptr conn)	{
		if (!e)	{	// lecture des informations
			db::DataBaseType<MySQL> dbMySQL("root", "", "mycloud") ;
			string idMySQL;

			for(model::info i : infos)	{
				idMySQL = dbMySQL.getUser(i.getAddressMail(), i.getPwd());
			}
			if(idMySQL == "1"){
				cout << "Connexion réussi" << endl;

				File file("/home/steven/server/",idMySQL);

				std::string path="/home/steven/server/" + idMySQL + "referencement.xml";
				std::ifstream input(path.c_str());
				std::stringstream data_in;
				data_in << input.rdbuf();
				input.close();

				conn->socket().send(boost::asio::buffer(data_in.str()));
			}else{
				cout << "Connexion échoué" << endl;
			}



		} else {
			std::cerr << e.message() << std::endl;
		}
	}
	string readMap(const string &filename)
	{
	    ifstream file (filename.c_str(), ios::in|ios::binary);
	    string reply;
	    char buf[4096];
	    while (file.read(buf, sizeof(buf)).gcount() > 0)
	        reply.append(buf, file.gcount());
	    return reply;
	}
	void handle_file(const boost::system::error_code& e, connection_ptr conn,string nameFile)	{
		if (!e)	{	// lecture des informations
			db::DataBaseType<MySQL> dbMySQL("root", "", "mycloud") ;
			string idMySQL;
			for(model::info i : infos)	{
				idMySQL = dbMySQL.getUser(i.getAddressMail(), i.getPwd());
			}
			File file("/home/steven/server/",idMySQL);
			std::string path="/home/steven/client/" + idMySQL + nameFile;
			std::stringstream data_in;
			data_in << readMap(path.c_str());
			conn->socket().send(boost::asio::buffer(data_in.str()));
		}
	}
	void handle_file_receive(const boost::system::error_code& e, connection_ptr conn){
		char buffer[4096]; long buffer2;
		// Reçois la taille du nom du fichier (4 octet ou 32 bits)
		/*int nombre_de_caractere=recv(,(char*)&buffer2,4,0);
		if (nombre_de_caractere==SOCKET_ERROR)
		{
			cout << "Erreur, je n'ai pas recu la taille du nom de fichier !\n\n";
			system("PAUSE");
		}
		// Reçois le nom du fichier
		char*nomdefichier=new char[buffer2+1];nomdefichier[0]=0;
		char*nomdefichier=new char[buffer2+1];nomdefichier[0]=0;
		    for (int i=0;i<buffer2;i+=nombre_de_caractere)
		    {
		        nombre_de_caractere=conn->async_read(infos, boost::bind(&server::handle_read, this, boost::asio::placeholders::error, conn));
		        if (nombre_de_caractere==-1)
		        {
		            cout << "Erreur, je n'ai pas recu le nom du fichier !\n\n";
		            system("PAUSE");
		        }
		        else
		        {
		            for (int y=0;y<nombre_de_caractere;y++)
		            {
		                nomdefichier[y+i]=buffer[y];
		                nomdefichier[y+i+1]=0;
		            }
		        }
		    }
		    cout << "Nom du fichier a recevoir : " << nomdefichier << "\n";

		    ofstream fichiers(nomdefichier,ios::out|ios::binary);
		    if (!fichiers)
		    {
		        cout << "Erreur, impossible de créer le fichier !\n\n";
		    }*/
	}
private:
	boost::asio::ip::tcp::acceptor acceptor_;
	std::vector<model::info> infos;

};

}
}
