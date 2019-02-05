//----------------------------------------------------------------------------------------------------
//  IMPLEMENTATION FILE (ComputerType.cxx)
//----------------------------------------------------------------------------------------------------
#include "ComputerType.h"

ComputerType::ComputerType()
{
  invalid = 0;
  onethreefive = 0;
  onethreesix = 0;
  onefourfive = 0;
  labSum=0;
}

RelationType ComputerType::ComparedTo(ComputerType otherItem) const
{
 if(idNumber < otherItem.idNumber)
      return LESS;
 else if(idNumber > otherItem.idNumber)
      return GREATER;
 else return EQUAL;
}


bool ComputerType::validData()
{
  if (idNumber < 1111 || idNumber > 9999)
	{
	  invalid ++;
	  return 0;
	}
  if (RAMsize != 4 &&  RAMsize != 8 && RAMsize != 16 && RAMsize != 32)
	{
	  invalid ++;
	  return 0;
	}
  if (DiskSize != 500 && DiskSize != 1 && DiskSize != 2)
	{
	  invalid ++;
	  return 0;
	}
  if (computerType != "d" && computerType != "l")
	{
	  invalid ++;
	  return 0;
	}
  if (cost < 0 || cost > 1500)
	{
	  invalid ++;
	  return 0;
	}
  if (labLocation != "SE145" && labLocation != "SE135" && labLocation != "SE136")
	{
	  invalid ++;
	  return 0;
	}
  return true;
}

void ComputerType::TypeConversion()
{
  if (computerType == "d")
    computerType = "Desktop";
  if (computerType == "l")
    computerType = "Laptop";
}

void ComputerType::ReadRd(ifstream& inFile)
{
  inFile >> idNumber >> processor >> RAMsize >> RAMbyte >> DiskSize >> DISKbyte >> computerType >> cost >> labLocation;
}



void ComputerType::PrintHeader(ofstream& outFile)
{
  outFile << setfill(' ') << setw(12) << left << "IdNumber" ;
  outFile <<  setw(16) << left << "Processor" ;
  outFile <<  setw(10) << left << "RAM Size" ;
  outFile <<  setw(11) << left << "Disk Size" ;
  outFile <<  setw(15) << left << "Computer Type" ;
  outFile <<  setw(8)  << left << "Cost" ;
  outFile <<  setw(10) << left << "Location" << endl;

  outFile << setfill(' ') << setw(12) << left << "--------" ;
  outFile <<  setw(16) << left << "---------" ;
  outFile <<  setw(10) << left << "--------" ;
  outFile <<  setw(11) << left << "---------" ;
  outFile <<  setw(15) << left << "-------------" ;
  outFile <<  setw(8)  << left << "----" ;
  outFile <<  setw(10) << left << "--------" << endl;
}

void ComputerType::PrintLabSummary(ofstream& outFile)
{
  outFile << "   " << endl;
  outFile << "SE135:   %" << (onethreefive/labSum) * 100 << endl;
  outFile << "SE136:   %" << (onethreesix/labSum) * 100 << endl;
  outFile << "SE145:   %" << (onefourfive/labSum) * 100 << endl;
  outFile << "   " << endl;
  outFile << "*** " << invalid << " invalid record(s)" << endl;

}

void ComputerType::PrintRd(ofstream& outFile)
{
  outFile <<  setw(9)  << left << idNumber;
  outFile <<  setw(22) << left << processor;
  outFile <<  setw(3)  << left << RAMsize;
  outFile <<  setw(4)  << left << RAMbyte;
  outFile <<  setw(3)  << left << DiskSize;
  outFile <<  setw(8)  << left << DISKbyte;
  outFile <<  setw(15) << left << computerType;
  outFile << fixed;
  outFile <<  setw(8)  << left << setprecision(2) << cost;
  outFile <<  setw(10) << left << labLocation << endl;
}

void ComputerType::labCount()
{
        if(labLocation == "SE135")
         {
          onethreefive ++;
          labSum ++;
         }
        if(labLocation == "SE145")
         {
          onefourfive++;
          labSum++;
         }
        if(labLocation == "SE136")
         {
          onethreesix++;
          labSum++;
         }
}


bool ComputerType::lapYes(ComputerType item)
{
  return (computerType == "Laptop");
}

bool ComputerType::deskYes(ComputerType item)
{
  return (computerType == "Desktop");
}

bool ComputerType::maxYes(ComputerType item)
{
  return (RAMsize == 16 && DiskSize == 2);
}

