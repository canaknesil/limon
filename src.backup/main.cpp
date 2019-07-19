#include <kissInterpreter.h>

#include <iostream>
#include <string>

using namespace std;

void printUsage()
{
	cout << "Usage:" << endl;
	cout << "\tkiss            : From command line" << endl;
	cout << "\tkiss <filename> : From file" << endl;
}

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printUsage();
		return 1;
	}
	
	return KissInterpreter::interpretTopFile(argv[1]);
}
