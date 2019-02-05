//*********************************************************************************
//AUTHOR							:Mathew Walker
//COURSE TITLE						:Computer Programming II
//COURSE NUMBER						:CS216
//CLASS MEETS						:MW/8:30-10:20
//PROF NAME							:Moe Bidgoli
//ASSIGNMENT NUMBER					:#3
//DUE DATE							:09-30-2015
//POSIBLE POINTS					:20
//PURPOSE:
//	This program will read data from an input file organize it
//	into a chart and print it to an output file, also report
//  average cost, highest cost, lowest cost, and invalid records.
//*********************************************************************************

#include "UnsortedType.h"
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
  outFile << "*~< Lab Report >*" << endl;

  ComputerType item;
  UnsortedType itemList;
  char command;
  itemList.MakeEmpty(); // sets Length = 0

  inFile >> command;

  while(inFile)
  {
    switch(command)
    {

     case 'A':
       {
         item.ReadRd(inFile);
         if(item.validData())
           {
             item.labCount();
             item.TypeConversion();
             if(!itemList.IsFull())
               {
                 itemList.InsertItem(item);
                 break;
               }
             else
               {
                 outFile << "List is full! No Insert!" << endl;
                 outFile << "    " << endl;
                 break;
               }
            }
          else
            {
              item.PrintRd(outFile);
              break;
            }
        }

      case 'P':
        {
          if(itemList.LengthIs() != 0)
            {
              item.PrintHeader(outFile);
              itemList.PrintList(outFile);
              itemList.ResetList();
              item.PrintLabSummary(outFile);
              outFile << "    " << endl;
              break;
             }
          else
             {
               outFile << "List is Empty! No Print!" << endl;
               outFile << "    " << endl;
               break;
             }
        }

      case 'D':
        {
          if(itemList.LengthIs() != 0)
            {
               bool found = false;
               itemList.RetrieveItem(item, found);
               if(found)
                 {
                   itemList.DeleteItem(item);
                   break;
                 }
               else
                 {
                   outFile << "Item not Found! No Delete!" << endl;
                   outFile << "    " << endl;
                   break;
                 }
            }
           else
            {
              outFile << "List is Empty! No Delete!" << endl;
              outFile << "    " << endl;
              break;
            }
        }

      case 'L':
        {
          itemList.PrintLap(outFile);
          outFile << "    " << endl;
          break;
        }

      case 'K':
        {
          itemList.PrintDesk(outFile);
          outFile << "    " << endl;
          break;
        }

      case 'M':
        {
          itemList.PrintMax(outFile);
          outFile << "    "  << endl;
          break;
        }

    }//end of switch
   inFile >> command;
  }//end of while loop


  outFile << " >end<" << endl;
return 0;

}
