#include "createPGMfile.h"


fileOperation::fileOperation(char* inputFileName , char* outputFileName)
{	
	this->inputFileName_ = inputFileName;
	this->outputFileName_= outputFileName;
	
	this->row_ =0;
	this->col_=0;
	this->maxBitValue_=0;
	
}

void fileOperation::setInputFileName(char* inputFileName)
{
	this->inputFileName_ = inputFileName;
}

void fileOperation::setOutputFileName(char *outputFileName)
{
	this-> outputFileName_ = outputFileName;
}


int fileOperation::getRow()
{
	return this->row_;
}

int fileOperation::getCol()
{
	return this->col_;
}

int fileOperation::getMaxBitValue()
{
	return this->maxBitValue_;
	
}

void fileOperation::readFile()
{
	ifstream tempFile;
	tempFile.open(this->inputFileName_);
	
	char first,second;
	
	if(!tempFile.is_open())
	{
		cout << "File is not opened !!" <<endl;
		exit(-1);
	}
	
	tempFile >> first;
	tempFile >> second;
	
	if(first == 'P' && second == '5'){	
		string tempLine;
		getline(tempFile, tempLine);				//unusage Line;
		getline(tempFile, tempLine);				// '#' comment line (it's unusage)
		tempFile >> col_;
		cout << col_ << endl;
		tempFile >> row_;
		cout <<row_<< endl;
		tempFile >>maxBitValue_;
		getline(tempFile, tempLine);				//unusage Line;	
	}
	else{
		cout << "Wrong File Format !!";
		exit(-2);
	}
	
	vector <int> tempVec;
	char pikselValue;
	
	for(int i= 0; i<row_;i++){
		
		for(int j=0; j<col_ ; j++){
			tempFile >>pikselValue;
			tempVec.push_back(static_cast<int>(pikselValue));
		}
		tempMatrix_.push_back(tempVec);	
		tempVec.clear();
	}
	
	tempFile.close();		
}

void fileOperation::writeFile()
{
	ofstream outputFile;
	outputFile.open(this->outputFileName_);
	
	outputFile << "P5"<< std::endl;
	outputFile << "# This image created by Ismail Can BUYUKTEPE"<< endl;
	outputFile << this->col_ <<' '<<this->row_<<endl;
	outputFile << this->maxBitValue_<<endl;
	
	for (int i =0 ; i< row_ ; i++){
		for(int j=0 ; j<col_ ; j++){
			if(i<100 && j < 100){
				outputFile << static_cast <char>(10);
			}
			else{
				outputFile << static_cast <char>(tempMatrix_[i][j]);
			}
		}
	
	}
	
	outputFile.close();
}

