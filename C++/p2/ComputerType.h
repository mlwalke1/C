//------------------------------------------------------------------------------------------
//  SPECIFICATION FILE (ComputerType.h)
//----------------------------------------------------------------------------------------- 
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class ComputerType{
public:

ComputerType();
// PURPOSE: Default constructor initializes member members for new class object.
// INPUT: NONE
// PRE: NONE
// OUTPUT: NONE
// POST: Members of new class object have been initialized.
// NOTE:

bool validData();
// PURPOSE: This function checks the validity of record data.
// INPUT: NONE
// PRE: Data must be read into variables to to tested.
// OUTPUT: NONE
// POST: The record data has been tested.
// NOTE:

string TypeConversion();
// PURPOSE: To convert computer type data into a more readable format(desktop or laptop).
// INPUT: NONE
// PRE:  computerType variable has a d or l assigned from input file.
// OUTPUT: NONE
// POST: computerType has either "Desktop" or "Laptop" assinged to it.
// NOTE:


void ReadRd(ifstream& inFile);
// PURPOSE: Reads data from an input file and assigns values to private variables.
// INPUT: input is data from inFile
// PRE: ifstream is open, variables are initialized, and inFile exists with the proper data,
// OUTPUT: NONE
// POST: Data from input file has been assigned to private variables.
// NOTE:

void PrintHeader(ofstream& outFile);
// PURPOSE: Prints headers to output file
// INPUT: NONE
// PRE: Outfile must be opened and ok
// OUTPUT: NONE:
// POST: Headers are printed to output file
//

void PrintRd(ofstream& outFile);
// PURPOSE: Prints data from private variables to output file.
// INPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// PRE: Variables are initialized with the proper data and fstream is open to creat output file.
// OUTPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// POST: Data has been printed to output file.
//

void sumCount();
// PURPOSE: This function totals the costs and keeps track of counts.
// INPUT: NONE.
// PRE: variables must be intialized to hold sums and counts.
// OUTPUT: NONE
// POST: average cost of desktop will exist.
// NOTE: variables must be intialized at 0 to get the proper output

void highLow();
// PURPOSE: This function keeps track of the highest and lowest costs of computers.
// INPUT: NONE
// PRE: lowest cost variable and highest must be initialized
// OUTPUT: NONE
// POST: Highest and lowest costs of computers will have been determined.
// NOTE: lowest cost variable must be set high or else it won't work

void calcAvg();
// PURPOSE: calculates the average of both laptop computers and desktop computers.
// INPUT: NONE
// PRE: the sums and totals of both computers must be calculated.
// OUTPUT: NONE
// POST: the average will have been calculated.
//

void finalReport(ofstream& outFile);
// PURPOSE: Prints the final report of average cost, highest and lowest cost, and invalid records.
// INPUT: NONE
// PRE: average, highest, and lowest must be calculated.
// OUTPUT: NONE
// POST: average cost, highest and lowest cost, and invalid data will be printed to output file.
// NOTE:

private:



int idNumber;
string processor;
int RAMsize;
string RAMbyte;
int DiskSize;
string DISKbyte;
string computerType;
float cost;
string labLocation;
int invalid;
float lapSum;
float deskSum;
float lapAvg;
float deskAvg;
float highest;
float lowest;
int lapCount;
int deskCount;
};
