#ifndef WRITE_IN_FILE_H_
#define WRITE_IN_FILE_H_

#include <iostream>
#include <fstream>
using namespace std;

void writeInFile(string comando)
{
	ofstream outputFile("output.txt");
	outputFile << comando << endl;
}


#endif	/* WRITE_IN_FILE_H_ */
