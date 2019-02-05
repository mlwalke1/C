//------------------------------------------------------------------------------------------
//  SPECIFICATION FILE (ComputerType.h)
//----------------------------------------------------------------------------------------- 
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_ITEMS = 5;
enum RelationType {LESS, EQUAL, GREATER};

class ComputerType{
public:

ComputerType();
// PURPOSE: Default constructor initializes member members for new class object.
// INPUT: NONE
// PRE: NONE
// OUTPUT: NONE
// POST: Members of new class object have been initialized.
// NOTE:

RelationType ComparedTo(ComputerType) const;

bool validData();
// PURPOSE: This function checks the validity of record data.
// INPUT: NONE
// PRE: Data must be read into variables to to tested.
// OUTPUT: NONE
// POST: The record data has been tested.
// NOTE:

void TypeConversion();
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

void PrintLabSummary(ofstream& outFile);
// PURPOSE: Prints percentages of lab to output file
// INPUT: outfile
// PRE: Outfile must be opened and ok
// OUTPUT: prints summary of labs
// POST: Lab summary will be printed to output file
//


void PrintRd(ofstream& outFile);
// PURPOSE: Prints data from private variables to output file.
// INPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// PRE: Variables are initialized with the proper data and fstream is open to creat output file.
// OUTPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// POST: Data has been printed to output file.
//

void labCount();
// PURPOSE: This function keeps track of lab locations
// INPUT: NONE.
// PRE: variables must be intialized to hold counts.
// OUTPUT: NONE
// POST: counts will exist for lab locations
// NOTE: variables must be intialized at 0 to get the proper output


bool lapYes(ComputerType item);
// PURPOSE: This functions finds if item has laptop
// INPUT: item
// PRE: item has been created and computerType has a value
// OUTPUT: bool
// POST: function returns bool value
// NOTE: 


bool deskYes(ComputerType item);
// PURPOSE: This functions finds if item has desktop
// INPUT: item
// PRE: item has been created and computerType has a value
// OUTPUT: bool
// POST: function returns bool value
// NOTE:

bool maxYes(ComputerType item);
// PURPOSE: This functions finds if item has highest RAM and DiskSize
// INPUT: item
// PRE: item has been created and RAMsize and DiskSize have a value
// OUTPUT: bool
// POST: function returns bool value
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
char command;
int onethreefive;
int onethreesix;
int onefourfive;
int labSum;
};
