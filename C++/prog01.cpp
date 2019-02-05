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

    inData >> patientName >> patientID >> exam1 >> exam2 >> exam3;
   
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
		if (avg >= 97) PosNeg = "Pos / RISK";
		else          PosNeg = "Pos";
	  }
	else PosNeg = "Neg";


    }


    // print header
    printHeader(outData);

    // spacing from gpcorser prog01.cpp
    outData << setprecision(2) << fixed;
    outData << setfill(' ') << setw(15) << left << patientName;
    outData << setw(12) << left << patientID;
    outData << setw(7) << left << exam1;
    outData << setw(7) << left << exam2;
    outData << setw(7) << left << exam3;
    if(valid)
    {
	outData << setw(10) << left << avg;
	outData << setw(10) << left << PosNeg;
    }
    else outData << "~~ Invalid data~~";
    outData << endl;
    
    outData << "*< End of Report >*" << endl;


	inData.close();
	outData.close();
}

void printHeader (ofstream& outData)
{
  outData << "*~~< Patient Exam Report >~~*" << endl;
  outData << setfill(' ') << setw(15) << left << "Name";
  outData << setw(12) << left << "Patient Id";
  outData << setw(7) << left << "Exam1";
  outData << setw(7) << left << "Exam2";
  outData << setw(7) << left << "Exam3";
  outData << setw(10) << left << "AVG";
  outData << setw(10) << left << "Pos/Neg";
  outData << endl;

  outData << setfill(' ') << setw(15) << left << "----";
  outData << setw(12) << left << "--------";
  outData << setw(7) << left << "-----";
  outData << setw(7) << left << "-----";
  outData << setw(7) << left << "-----";
  outData << setw(10) << left << "-----";
  outData << setw(10) << left << "-------";
  outData << endl;
  
}

