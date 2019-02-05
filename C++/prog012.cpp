// filename: prog01.cpp

#include <fstream>    // For input and output file streams
#include <string>     // For string data types
#include <iomanip>    // for setw()
#include <iostream>   // for endl
using namespace std;  // to make code more readable (no "std::" prefix)

void printHeader (ofstream& outData);

int main()
{

    // Declare and open files
    ifstream inData;		    // declare infile object
    ofstream outData;		    // declare outfile object
    inData.open("in.data"); 	// open infile
    outData.open("out.data");   // open outfile
    string patientName, PosNeg = "";
    int patientID;
    float exam1, exam2, exam3, avg;
    bool valid = true;
    if (patientID < 1111 || patientID > 9999) valid = false; 
    if (exam1 < 0 || exam1 > 100) valid = false; 
    if (exam2 < 0 || exam2 > 100) valid = false; 
    if (exam3 < 0 || exam3 > 100) valid = false; 
    avg = (exam1 + exam2 + exam3) / 3;
    if (valid)
    {
	if (avg > 70)
	  {
		if (avg > 97) PosNeg = "Pos / RISK";
		else          PosNeg = "Pos";
	  }
	else PosNeg = "Neg";


    }

    inData >> patientName >> patientID >> exam1 >> exam2 >> exam3;

    printHeader(outData);

    outData << patientName << "\t" << patientID << "\t" << exam1 << "\t" << exam2 << "\t" << exam3 << "\t";
    if(valid) outData << avg << "\t" << PosNeg;
    else outData << "~~ Invalid data~~";
    outData << endl << endl;
    outData << "*< End of Report >*" << endl;
}

void printHeader (ofstream& outData)
{
  outData << "*~~< Patient Exam Report >~~*" << endl;
  outData << "Name\tPatientID\tExam1\tExam2\tExam3\tAvg\tPos/Neg" << endl;
  outData << "----\t---------\t-----\t-----\t-----\t---\t-------" << endl;

}

