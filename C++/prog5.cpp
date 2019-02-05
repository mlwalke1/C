//***********************************************************************
//
//   PROGRAM FIVE
//   NAME:        Mathew Walker
//   DATE:        11/12/14
//   CLASS:       CS105
//   PROFESSOR:   Nancy A Samolewski
//   PROGRAM DEF:
//
//   This program reads an unknown number of student ids and
//   exam scores from an input file and writes them into an
//   output file.
//
//************************************************************************

#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

   ifstream inFile;
   ofstream outFile;

   inFile.open("input5.dat");
   outFile.open("output5.dat");

   outFile.setf(ios::fixed);
   outFile.precision(2);

   int id, score;

   outFile << "*** Exam Report *** " << endl;
   outFile << endl;
   outFile << "Student Id" << setw(10) << "Exam" << endl;
   outFile << "----------" << setw(10) << "----" << endl;

   inFile >> id >> score;
   while (inFile)
   {
      outFile << id << setw(15) << score << endl;
      inFile >> id >> score;
   }
   outFile << endl;
   outFile << setw(13) << "< end >" << endl;

   return 0;
}

