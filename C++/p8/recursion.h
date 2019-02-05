#include <fstream>
using namespace std;

void ReadToArray(ifstream& inFile, int intArray[], int length);
//PURPOSE: Reads from input file into an array
//INPUT: inFile, intArray, length
//PRE: infile must be open and ok, array and length init
//OUTPUT: none
//POST: array of length has value
//NOTE:

void printArray(ofstream& outFile, int intArray[], int first, int last);
//PURPOSE: prints array to outfile
//INPUT: outfile, intArray, first, last
//PRE: outfile must be ok, intArray must have values
//OUTPUT: void function prints to outfile
//POST: values in intArray will be printed
//NOTE:


void printArrayRev(ofstream& outFile, int intArray[], int first, int last);
//PURPOSE: prints array in reverse order
//INPUT: outfile, intArray, first, last
//PRE: outfile must be ok, intArray must have values
//OUTPUT: void function prints to outfile
//POST: values in intArray will be printed in reverse
//NOTE:

int sumOfInt(int n);
//PURPOSE: gets the sum of 1 through n
//INPUT: n
//PRE: n must have value
//OUTPUT: int
//POST: int will be returned
//NOTE:

int minOfArray(int intArray[], int length);
//PURPOSE: finds the minimum number of array
//INPUT: intArray, length
//PRE: intArray must have values
//OUTPUT: int
//POST: returns smallest value
//NOTE:

int fact(int n);
//PURPOSE: calculates n factorial
//INPUT: n
//PRE: n must have value
//OUTPUT: int
//POST: returns n factorial
//NOTE:

int summation(int s, int v);
//PURPOSE: adds digits of value
//INPUT: s, v
//PRE: s and v must be initialized
//OUTPUT: int
//POST: returns sum of digits
//NOTE:

void binary(ofstream& outFile, int sum);
//PURPOSE: finds binary value of an int
//INPUT: outfile, sum
//PRE: outfile must be ok, sum must be init
//OUTPUT: prints to outfile
//POST: binary number will be printed
//NOTE:

