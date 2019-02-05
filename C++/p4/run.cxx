//*********************************************************************************
//AUTHOR							:Mathew Walker
//COURSE TITLE						:Computer Programming II
//COURSE NUMBER						:CS216
//CLASS MEETS						:MW/8:30-10:20
//PROF NAME							:Moe Bidgoli
//ASSIGNMENT NUMBER					:#4
//DUE DATE							:10-07-2015
//POSIBLE POINTS					:20
//PURPOSE:
//	This program will read parenthesized characters from an input file
//	and evaluate expressions within and if the data is properly
//  organized within the parenthisis. Then it will print the results.
//*********************************************************************************

#include "stack.h"

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

string line;
getline(inFile, line);

StackType<char> command;
StackType<int> item;

inFile.close();
inFile.open("in.data");

outFile << "*** Fully Parenthesized Arithmetic Infix Expression ***" << endl;
outFile << "  " << endl;

char newItem;
float item1 = 0;
float item2 = 0;
char op;

command.MakeEmpty();
item.MakeEmpty();
inFile >> newItem;

while(inFile && newItem != ';')
{
try
 {

  if(newItem >= '(' && newItem <= '/')
    {
      command.Push(newItem);
      if(newItem == ')')
      {
        command.Pop();
        item1 = item.Pop();
        item2 = item.Pop();
        op = command.Pop();
        float result = item.Evaluate(item1, item2, op, newItem);
        command.Pop();
        item.Push(result);
      }
    }
  if ( newItem >= '0' && newItem <= '9')
  {
    float representative = newItem - 48;
    item.Push(representative);
  }
 }
catch(FullStack exceptionObject)
 {
   outFile << line << " ~~~Stack Overflow!" << endl;
   outFile << " " << endl;
   outFile << "< end >" << endl;
   exit(1);
 }

catch(EmptyStack exceptionObject)
 {
   outFile << line << " ~~~Stack Underflow!" << endl;
   outFile << " " << endl;
   outFile << "< end >" << endl;
   exit(1);
 }

catch (zero exceptionObject)
 {
   outFile << line << " ~Cannot Divide by Zero!" << endl;
   outFile << " " << endl;
   outFile << "< end >" << endl;
   exit(1);

 }
  inFile >> newItem;
}// end while loop

item.Print(outFile, line);

return 0;
}
