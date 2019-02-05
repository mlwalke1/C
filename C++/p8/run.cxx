
//******************************************************************************
//AUTHOR                            :Mathew Walker
//COURSE TITLE                      :Computer Programming II
//COURSE NUMBER                     :CS216
//CLASS MEETS                       :MW/8:30-10:20
//PROF NAME                         :Moe Bidgoli
//ASSIGNMENT NUMBER                 :#8
//DUE DATE                          :11-04-2015
//POSIBLE POINTS                    :30
//PURPOSE:
//  This program will read data from an input file organize it
//  into an array and print it to an output file, forwards and backwards
//  will also find sum, minimum, factorial, sum of digits, and binary.
//******************************************************************************



#include "recursion.h"

int main()
{

ifstream inFile;
ofstream outFile;
inFile.open("in.data");
outFile.open("out.data");

if (inFile.fail() || outFile.fail())
{
  outFile << "Check your input and output file!" << endl;
  return 1;
}

const int MAX_ITEMS = 10;
int intArray[MAX_ITEMS];
int first = 0;
int last = MAX_ITEMS - 1;
int length = 0;

//READ to array
while(inFile)
{
  ReadToArray(inFile,intArray, length);
  length++;
}

//PRINT array
outFile << "   1) Array: ";
printArray(outFile, intArray, first, last);
outFile << endl;

//REVERSE array
outFile << "   2) Array in reverse order: ";
printArrayRev(outFile, intArray, first, last);
int n = intArray[MAX_ITEMS - 1];
outFile << endl;

//MIN of array
length = MAX_ITEMS - 1;
outFile << "   3) MIN of array: " << minOfArray(intArray, length) << endl;

//SUM of INT
outFile << "   4) SUM of 1-" << n << ": " << sumOfInt(n) << endl;

//FACTORIAL
outFile <<  "   5) " << n << "!: " << fact(n) << endl;

//SUMMATION
int v = sumOfInt(n);
int s = 0;
outFile << "   6) Summation of digits for " << v << ": " << summation(s, v) << endl; 

//BINARY
int sum = sumOfInt(n);
outFile <<  "   7) Binary of " << sum << ": ";
binary(outFile,sum);
outFile << endl;

//PRINT end
outFile << " " << endl;
outFile << "<*~ end ~*>" << endl;

return 1;

}
