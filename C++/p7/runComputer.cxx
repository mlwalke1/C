//*********************************************************************************
//AUTHOR							:Mathew Walker
//COURSE TITLE						:Computer Programming II
//COURSE NUMBER						:CS216
//CLASS MEETS						:MW/8:30-10:20
//PROF NAME							:Moe Bidgoli
//ASSIGNMENT NUMBER					:#2
//DUE DATE							:09-23-2015
//POSIBLE POINTS					:20
//PURPOSE:
//	This program will read data from an input file organize it
//	into a chart and print it to an output file, also report
//  average cost, highest cost, lowest cost, and invalid records.
//*********************************************************************************

#include "ExtComputerType.h"


int main(){

ifstream inFile;
ofstream outFile;
inFile.open("in.data");
outFile.open("out.data");

if (inFile.fail() || outFile.fail())
{
  outFile << "Check your input and output file!" << endl;
  return 1;
}

ExtComputerType rd;
bool valid = 0;

rd.PrintHeader(outFile);
rd.ReadRd(inFile);

while(inFile)
{
  if(rd.validData())
  {
    rd.setStatus();
    rd.TypeConversion();
    rd.PrintRd(outFile);
    rd.sumCount();
    rd.highLow();
    valid = 1;
  }
  else
  {
    rd.TypeConversion();
    rd.PrintInvalid(outFile);
  }
  rd.ReadRd(inFile);
}

rd.calcAvg();

if(valid)
{
  rd.finalReport(outFile);
}

else
{
  outFile << "  " << endl;
  outFile << "~~~~No Valid Records~~~" << endl;
}

return 0;

}
