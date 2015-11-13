#include "Log.h"

int main(int argc, char* argv[]){
	Log log;
	ManagerFileSystem managerFileSystem(log);
	managerFileSystem.readFile();
	return 0;
}
