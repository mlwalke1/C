//*********************************************************************************
//AUTHOR							:Mathew Walker
//COURSE TITLE						:Computer Programming II
//COURSE NUMBER						:CS216
//CLASS MEETS						:MW/8:30-10:20
//PROF NAME							:Moe Bidgoli
//ASSIGNMENT NUMBER					:#1
//DUE DATE							:09-16-2015
//POSIBLE POINTS					:20
//PURPOSE:
//	This program will read data from an input file organize it
//	into a chart and print it to an output file, using a class
//  interface to organize objects into public and private categories.
//*********************************************************************************

#include "ComputerType.h"


int main(){

	ifstream inFile;
	ofstream outFile;
	inFile.open("in.data");
	outFile.open("out.data");

	if (inFile.fail() || outFile.fail())
	{
		outFile << "Check your input and/or output file!" << endl;
		return 1;
	}

	ComputerType ComputerRecord;

	ComputerRecord.ReadRd(inFile);
	ComputerRecord.TypeConversion();
	ComputerRecord.PrintRd(outFile);


return 0;

}
