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
// PURPOSE: Default constructor initializes member varialbes for new class object.
// INPUT: NONE
// PRE: 
// OUTPUT: NONE
// POST: Member variables of new object have been initialized.
// NOTE:
ComputerType(int idNumber, string processor, int RAMsize, string RAMbyte, int DiskSize, string DISKbyte, string computerType, float cost, string labLocation);
// PURPOSE: Initializer constructor initializes member variables with values.
// INPUT: NONE
// PRE:
// OUTPUT:NONE
// POST:
// NOTE:

string TypeConversion();
// PURPOSE: To convert computer type data into a more readable format(desktop or laptop).
// INPUT: NONE
// PRE:  computerType variable has a d or l assigned from input file.
// OUTPUT: NONE
// POST: computerType has either "Desktop" or "Laptop" assinged to it.
// NOTE:

void SetComputer(int ID, string PROC, int RAM, int DISK);
// PURPOSE: Function allows you to manually set private data values.
// INPUT: Values you want to put into variables.
// PRE: variables must be initialized.
// OUTPUT: NONE
// POST: Private variables have been assigned new values.x
//

string ProcessorIs();
// PURPOSE: Returns processor value.
// INPUT: NONE
// PRE: processor is initialized with a value.
// OUTPUT: Returns processor value.
// POST: NONE
// NOTE:

string LocationIs();
// PURPOSE: Returns labLocation value.
// INPUT: NONE
// PRE: labLocation is intialized with a value.
// OUTPUT: Returns labLocation value.
// POST: NONE
// NOTE:

void ReadRd(ifstream& inFile);
// PURPOSE: Reads data from an input file and assigns values to private variables.
// INPUT: input is data from inFile
// PRE: ifstream is open, variables are initialized, and inFile exists with the proper data,
// OUTPUT: NONE
// POST: Data from input file has been assigned to private variables.
// NOTE:

void PrintRd(ofstream& outFile);
// PURPOSE: Prints data from private variables to output file.
// INPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// PRE: Variables are initialized with the proper data and fstream is open to creat output file.
// OUTPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// POST: Data has been printed to output file.
//



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


};
