#ifndef CREATEPGMFILE_H
#define CREATEPGMFILE_H

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class fileOperation{
	
	public:
	fileOperation(char* inputFileName ,char* outputFileName);
	
	void readFile();
	void writeFile();
	
	int getRow();
	int getCol();
	int getMaxBitValue();
	
	void setInputFileName(char* inputFileName);
	void setOutputFileName(char* outputFileName);
	
	
	private:
	
	int row_;
	int col_;
	int maxBitValue_;
	char* inputFileName_;
	char* outputFileName_;
	vector<vector<int> > tempMatrix_;
	
	
	
};

#endif 
