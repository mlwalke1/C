//----------------------------------------------------------------------------------------------------
//  IMPLEMENTATION FILE (ComputerType.cxx)
//----------------------------------------------------------------------------------------------------
#include "ComputerType.h"

ComputerType::ComputerType()
{
  invalid = 0;
  lapSum = 0;
  deskSum = 0;
  lapAvg = 0;
  deskAvg = 0;
  highest = 0;
  lowest = 999999;
  lapCount = 0;
  deskCount = 0;
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



string ComputerType::TypeConversion()
{
  if (computerType == "d")
	{
	  computerType = "Desktop";
	}
  if (computerType == "l")
	{
	  computerType = "Laptop";
	}

return computerType;
}


void ComputerType::ReadRd(ifstream& inFile)
{
  inFile >> idNumber >> processor >> RAMsize >> RAMbyte >> DiskSize >> DISKbyte >> computerType >> cost >> labLocation; 
}

void ComputerType::PrintHeader(ofstream& outFile)
{

  outFile << "*~<Computer Lab Report >~*" << endl;
  outFile << setfill(' ') << setw(12) << left << "IdNumber" ;
  outFile <<  setw(16) << left << "Processor" ;
  outFile <<  setw(10) << left << "RAM Size" ;
  outFile <<  setw(11) << left << "Disk Size" ;
  outFile <<  setw(15) << left << "Computer Type" ;
  outFile <<  setw(8)  << left << "Cost" ;
  outFile <<  setw(10) << left << "Location" << endl;
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

void ComputerType::sumCount()
{
  if (ComputerType::TypeConversion() == "Laptop")
    {
	  lapSum += cost;
	  lapCount ++;
    }
  if (ComputerType::TypeConversion() == "Desktop")
	{
	  deskSum += cost;
	  deskCount ++;
	}

}

void ComputerType::calcAvg()
{
  lapAvg = lapSum/lapCount;
  deskAvg = deskSum/deskCount;
}

void ComputerType::highLow()
{
  if(cost > highest)
	{
	  highest = cost;
	}
  if(cost < lowest)
	{
	  lowest = cost;
	}
}

void ComputerType::finalReport(ofstream& outFile)
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
  outFile << "*** " << invalid << " invalid record" << endl;
  outFile << " " << endl;
  outFile << "*~~~< end >~~~*" << endl;

}
