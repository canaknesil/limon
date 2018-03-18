#include <fileInterp.h>

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2) {
		cout << "Usage: kiss <source file>" << endl;
		return 1;
	}

    return interpTopFile(argv[1]);
    
    return 0;
}