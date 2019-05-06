#include <iostream>
#include<string>
#include "createPGMfile.h"

using namespace std;

int main(int argc , char *argv[])
{
	if(argc != 3){
		cout << "Usage:"<<argv[0]<<" <fileName> <writeFileName>"<<endl;
		exit(-1);
	}
	
	fileOperation pgm(argv[1] , argv[2]);
	
	pgm.readFile();
	pgm.writeFile();
	
	return 0;
}
