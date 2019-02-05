//***********************************************************************
//
//   PROGRAM FOUR
//   NAME:        Mathew Walker
//   DATE:        11/5/2014
//   CLASS:       CS105
//   PROFESSOR:   Nancy A Samolewski
//   PROGRAM DEF:
//
//       This program will in three numbers from an input text file.
//       It will finds MAX and AVG of three integer numbers
//       and display them into a output text file.
//
//************************************************************************

#include <fstream>

using namespace std;

int main()
{

   ifstream inFile;
   ofstream outFile;

   inFile.open("input4.dat");
   outFile.open("output4.dat");

   outFile.setf(ios::fixed);
   outFile.precision(2);

   int num1, num2, num3, max;
   float avg;

   inFile >> num1 >> num2 >> num3;
   avg = float(num1 + num2 + num3) / 3;

   if (num1 > num2)
       if (num1 > num3)
           max = num1;
       else
		  max = num3;
   else
       if (num2 > num3)
           max = num2;
       else
		  max = num3;

   outFile << "*** MAX & AVG of Three Numbers ***" << endl;
   outFile << endl;
   outFile << "Number 1: " << num1 << endl;
   outFile << "Number 2: " << num2 << endl;
   outFile << "Number 3: " << num3 << endl;
   outFile << endl;
   outFile << "Maximum: " << max << endl;
   outFile << "Average: " << avg << endl;
   outFile << endl;
   outFile << "*> end <*" << endl;

return 0;
}

