#include "ComputerType.h"

class ExtComputerType : public ComputerType
{
  public:
   ExtComputerType();
   // PURPOSE: Constructor for class
   // INPUT: NONE
   // PRE: NONE
   // OUTPUT: NONE
   // POST: Values are initialized at 0
   //

   void setStatus();
   // PURPOSE: Sets status of computer to go or keep
   // INPUT: NONE
   // PRE: status must be initialized and computertype has the right value
   // OUTPUT: NONE
   // POST: status variable has the proper value
   //

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

   void PrintInvalid(ofstream& outFile);
   // PURPOSE: Prints data from private variables to output file.
   // INPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
   // PRE: Variables are initialized with the proper data and fstream is open to creat output file.
   // OUTPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
   // POST: Data has been printed to output file.
   //

   void finalReport(ofstream& outFile);
   // PURPOSE: Prints the final report of average cost, highest and lowest cost, and invalid records.
   // INPUT: NONE
   // PRE: average, highest, and lowest must be calculated.
   // OUTPUT: NONE
   // POST: average cost, highest and lowest cost, and invalid data will be printed to output file.
   // NOTE:


  private:
    string status;
    int DeskToGo;
    int DeskToKeep;
    int LapToGo;
    int LapToKeep;
};
