#include "ExtComputerType.h"


ExtComputerType::ExtComputerType()
// PURPOSE: Constructor for class
// INPUT: NONE
// PRE: NONE
// OUTPUT: NONE
// POST: Values are initialized at 0
//
{
  status = "";
  DeskToKeep = 0;
  DeskToGo = 0;
  LapToKeep = 0;
  LapToGo = 0;
}


void ExtComputerType::setStatus()
// PURPOSE: Sets status of computer to go or keep
// INPUT: NONE
// PRE: status must be initialized and computertype has the right value
// OUTPUT: NONE
// POST: status variable has the proper value
//

{
  if(computerType == "d")
  {
    if(RAMsize >= 16 && DISKbyte == "TB" )
    {
      status = "ToKeep!";
      DeskToKeep++;
    }
    else
    {
      status = "ToGo!";
      DeskToGo++;
    }
  }

  if(computerType == "l")
  {
    if(RAMsize >= 16 && DISKbyte == "TB" )
    {
      status = "ToKeep!";
      LapToKeep++;
    }
    else
    {
      status = "ToGo!";
      LapToGo++;
    }

  }
}


void ExtComputerType::PrintHeader(ofstream& outFile)
// PURPOSE: Prints headers to output file
// INPUT: NONE
// PRE: Outfile must be opened and ok
// OUTPUT: NONE:
// POST: Headers are printed to output file
//
{
  outFile << "*~<Computer Lab Report >~*" << endl;
  outFile << setfill(' ') << setw(10) << left << "IdNumber" ;
  outFile <<  setw(18) << left << "Processor" ;
  outFile <<  setw(10) << left << "RAM Size" ;
  outFile <<  setw(10) << left << "Disk Size" ;
  outFile <<  setw(13) << left << "Computer Type" ;
  outFile <<  setw(8)  << left << "Cost" ;
  outFile <<  setw(27) << left << "Location";
  outFile <<  setw(7) << left << "Status" << endl;
}

void ExtComputerType::PrintRd(ofstream& outFile)
// PURPOSE: Prints data from private variables to output file.
// INPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// PRE: Variables are initialized with the proper data and fstream is open to creat output file.
// OUTPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// POST: Data has been printed to output file.
//
{
  outFile <<  setw(10)  << left << idNumber;
  outFile <<  setw(18) << left << processor;
  outFile <<  setw(3)  << left << RAMsize;
  outFile <<  setw(7)  << left << RAMbyte;
  outFile <<  setw(3)  << left << DiskSize;
  outFile <<  setw(7)  << left << DISKbyte;
  outFile <<  setw(13) << left << computerType;
  outFile << fixed;
  outFile <<  setw(8)  << left << setprecision(2) << cost;
  outFile <<  setw(27) << left << labLocation;
  outFile << setw(7) << left << status << endl;
}

void ExtComputerType::PrintInvalid(ofstream& outFile)
// PURPOSE: Prints data from private variables to output file.
// INPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// PRE: Variables are initialized with the proper data and fstream is open to creat output file.
// OUTPUT: idNumber, processor, RAMsize, DiskSize, computerType, cost, labLocation.
// POST: Data has been printed to output file.
//
{
  outFile <<  setw(10)  << left << idNumber;
  outFile <<  setw(18) << left << processor;
  outFile <<  setw(3)  << left << RAMsize;
  outFile <<  setw(7)  << left << RAMbyte;
  outFile <<  setw(3)  << left << DiskSize;
  outFile <<  setw(7)  << left << DISKbyte;
  outFile <<  setw(13) << left << computerType;
  outFile << fixed;
  outFile <<  setw(8)  << left << setprecision(2) << cost;
  outFile <<  setw(5) << left << labLocation << "***Invalid data" << endl;
}

void ExtComputerType::finalReport(ofstream& outFile)
// PURPOSE: Prints the final report of average cost, highest and lowest cost, and invalid records.
// INPUT: NONE
// PRE: average, highest, and lowest must be calculated.
// OUTPUT: NONE
// POST: average cost, highest and lowest cost, and invalid data will be printed to output file.
// NOTE:
{
  outFile << " " << endl;
  outFile << " " << endl;
  outFile << fixed;
  if(deskSum > 0)
    {
      outFile << "Average cost of Desktop: $" << setprecision(2) << deskAvg << endl;
    }
  if(lapSum > 0)
    {
      outFile << "Average cost of Laptop: $" << setprecision(2)<< lapAvg << endl;
    }
  outFile << "High Price: $" << setprecision(2) << highest << endl;
  outFile << "Low Price: $" << setprecision(2) << lowest << endl;
  outFile << " " << endl;
  outFile << "DESK TOP" << endl;
  outFile << "--------" << endl;
  outFile << "Num Of ToKeep =" << DeskToKeep << endl; 
  outFile << "Num Of ToGo =" << DeskToGo << endl; 
  outFile << " " << endl;
  outFile << "LAP TOP" << endl;
  outFile << "--------" << endl;
  outFile << "Num Of ToKeep =" << LapToKeep << endl;
  outFile << "Num Of ToGo =" << LapToGo << endl;
  outFile << " " << endl;
  outFile << "*** " << invalid << " invalid record" << endl;
  outFile << " " << endl;
  outFile << "*~~~< end >~~~*" << endl;

}

