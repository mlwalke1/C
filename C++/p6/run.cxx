//*********************************************************************************
//AUTHOR							:Mathew Walker
//COURSE TITLE						:Computer Programming II
//COURSE NUMBER						:CS216
//CLASS MEETS						:MW/8:30-10:20
//PROF NAME							:Moe Bidgoli
//ASSIGNMENT NUMBER					:#6
//DUE DATE							:10-26-2015
//POSIBLE POINTS					:30
//PURPOSE:
//	This program will read commands along with student ID and gpa
//	and add them to a linked list and process if they are valid
//  and print them, delete them, et.c, based on the command.
//*********************************************************************************

#include "SortedLinkedList.h"

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

//PRINT Header
outFile << "<* Linked List of Students *>" << endl;
outFile << " " << endl;

//Initialize variables
SortedType sort;
sort.MakeEmpty();

char command;
int item = 0;
float gpa = 0.00;
int invalid = 0;

//Read and carry out commands
inFile >> command;

while(inFile)
{
  if(command == 'I')
  {
    inFile >> item >> gpa;
    if(!sort.IsFull())
    {
      if(sort.checkValid(item,gpa))
      {
        sort.InsertItem(item, gpa);
      }
      else
      {
       outFile << item << " " << setprecision(2) << fixed << gpa << " ~~~ Invalid data" << endl;
       outFile << " " << endl;
       invalid ++;
      }
    }
    else
    {
      outFile << "List is full, you can not insert!" << endl;
      outFile << " " << endl;
    }
  }

  if(command == 'P')
  {
    if(sort.LengthIs() > 0)
      sort.Print(outFile,invalid);
    else
    {
      outFile << "List is empty, you can not print!" << endl;
      outFile << " " << endl;
    }
 }

  if(command == 'E')
  {
   sort.MakeEmpty();
   outFile << "List is empty!" << endl;;
   outFile << "" << endl;
  }

  if(command == 'D')
  {
   inFile >> item;
   if(sort.LengthIs() > 0)
   {
     sort.DeleteItem(item);
   }
   else
   {
    outFile << "List is empty, you can not delete!" << endl;
    outFile << " " << endl;
   }
}

  if(command == 'R')
  {
   inFile >> item;
   if(sort.LengthIs() > 0)
   {
     bool found;
     sort.RetrieveItem(item, gpa, found);
     if(found)
       outFile << "*Student " << item << " has GPA: " << gpa << endl;
     else
     {
       outFile << "*" << item << " Not Found!" << endl;
       outFile << " " << endl;
     }
  }
   else
   {
    outFile << "List is empty, you can not search!" << endl;
    outFile << " " << endl;
   }
}

 inFile >> command;

}

outFile << "~~~(end)~~~" << endl;

return 0;
}
