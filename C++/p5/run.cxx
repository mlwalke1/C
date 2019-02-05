//*********************************************************************************
//AUTHOR							:Mathew Walker
//COURSE TITLE						:Computer Programming II
//COURSE NUMBER						:CS216
//CLASS MEETS						:MW/8:30-10:20
//PROF NAME							:Moe Bidgoli
//ASSIGNMENT NUMBER					:#5
//DUE DATE							:10-19-2015
//POSIBLE POINTS					:30
//PURPOSE:
//	This program will read male and female names from an input file
//	and add them to seperate queues and match dates according
//  to a first in first out basis, and print them to an output file.
//*********************************************************************************

#include "queue.h"
#include <iostream>
#include <fstream>

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
outFile << "~<* ACM dancing partners *>~" << endl;

//Initialize variables
Queue male;
Queue female;
char sex;
string name;
int m = 0;
int f = 0;

//READ first values
inFile >> sex >> name;

//Add names to queues
while(inFile)
  {
    if(sex == 'M')
      {
        if(!male.IsFull())
        {
          male.Enqueue(name);
          m++;
        }
        else
        {
         outFile << "" << endl;
         outFile << "~~~ Queue Overflow! No Enqueue!" << endl;
         outFile << "" << endl;
         outFile << "~* end *~" << endl;
         return 0;
        }
      }
    if(sex == 'F')
      {
        if(!female.IsFull())
        {
          female.Enqueue(name);
          f++;
        }
        else
        {
         outFile << "" << endl;
         outFile << "~~~ Queue Overflow! No Enqueue!" << endl;
         outFile << "" << endl;
         outFile << "~* end *~" << endl;
         return 0;
        }
      }

    inFile >> sex >> name;
  }

//Check for errors
if(m==0 && f==0)
{
  outFile << "" << endl;
  outFile << "~** Dance cannot be start! No male or female show up so far!**~ " << endl;
  outFile << "" << endl;
  outFile << "~* end *~" << endl;
  return 0;

}
if(m==0)
{
  outFile << "" << endl;
  outFile << "*** No male! No Dance!" << endl;
  outFile << "" << endl;
  outFile << "~* end *~" << endl;
  return 0;

}
if(f==0)
{
  outFile << "" << endl;
  outFile << "*** No Female! No Dance!" << endl;
  outFile << "" << endl;
  outFile << "~* end *~" << endl;
  return 0;


}

//Empty queues
while(!male.IsEmpty() && !female.IsEmpty())
  {
    male.Dequeue(name);
    outFile << name << " + "; 
    female.Dequeue(name); 
    outFile << name << endl;
    m--;
    f--;
  }

outFile << " " << endl;

if(m > 0)
  {
    outFile << "*** There are " << m << " men waiting for the next round." << endl;
    male.Dequeue(name);
    outFile << "*** "<< name << " will be the first to get a partner." << endl; 
  }

if(f > 0)
  {
    outFile << "*** There are " << f << " women waiting for the next round." << endl;
    female.Dequeue(name);
    outFile << "*** "<< name << " will be the first to get a partner." << endl;
  }

//Print end
outFile << " " << endl;
outFile << "~* end *~" << endl;

return 0;
}
