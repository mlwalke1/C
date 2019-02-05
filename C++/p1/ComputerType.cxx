//----------------------------------------------------------------------------------------------------
//  IMPLEMENTATION FILE (ComputerType.cxx)
//----------------------------------------------------------------------------------------------------
#include "ComputerType.h"

ComputerType::ComputerType()
{

}

ComputerType::ComputerType(int idNumber, string processor, int RAMSize, string RAMbyte, int DiskSize, string DISKbyte, string computerType, float cost, string labLocation)
{
	idNumber = 99999;
	processor = "wrong";
	RAMSize = 999999;
	RAMbyte = "wrong";
	DiskSize = 99999;
	DISKbyte = "wrong";
	computerType = "wrong";
	cost = 99999;
	labLocation = "wrong";
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


void ComputerType::SetComputer(int ID, string Proc, int RAM, int DISK)
{

 idNumber = ID;
 processor = Proc;
 RAMsize = RAM;
 DiskSize = DISK;
}

string ComputerType::ProcessorIs()
{
return processor;
}

string ComputerType::LocationIs()
{
return labLocation;
}

void ComputerType::ReadRd(ifstream& inFile)
{
	inFile >> idNumber >> processor >> RAMsize >> RAMbyte >> DiskSize >> DISKbyte >> computerType >> cost >> labLocation; 
}

void ComputerType::PrintRd(ofstream& outFile)
{

	outFile << "*~<Computer Lab Report >~*" << endl;
	outFile << setfill(' ') << setw(12) << left << "IdNumber" ;
	outFile <<  setw(16) << left << "Processor" ;
	outFile <<  setw(10) << left << "RAM Size" ;
	outFile <<  setw(11) << left << "Disk Size" ;
	outFile <<  setw(15) << left << "Computer Type" ;
	outFile <<  setw(8)  << left << "Cost" ;
	outFile <<  setw(10) << left << "Location" << endl;

	outFile <<  setw(9)  << left << idNumber;
	outFile <<  setw(22) << left << processor;
	outFile <<  setw(3)  << left << RAMsize;
	outFile <<  setw(4)  << left << RAMbyte;
	outFile <<  setw(3)  << left << DiskSize;
	outFile <<  setw(8)  << left << DISKbyte;
	outFile <<  setw(15) << left << computerType;
	outFile <<  setw(3)  << left << cost;
	outFile <<  setw(5)  << left << ".00";
	outFile <<  setw(10) << left << labLocation << endl;

	outFile << "*< end >*" << endl;

}

