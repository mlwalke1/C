#include  "UnsortedType.h"

UnsortedType::UnsortedType()
{
  length = 0;
  currentPos = 0;
}

void UnsortedType::MakeEmpty ( )
{
   length = 0 ;
}

bool UnsortedType::IsFull () const
{
   return (length == MAX_ITEMS);
}

int UnsortedType::LengthIs() const
{
   return length ;
}

void UnsortedType::RetrieveItem(ComputerType& item, bool& found)  
{    bool moreToSearch;
     int location = 0;

     found = false;
	moreToSearch = (location < length);
	while (moreToSearch  &&  found != true)
	{ switch (item.ComparedTo(info[location]))
      {   case  LESS	:
		  case  GREATER : location++;
				          moreToSearch = (location < length);
                          break ;
		  case  EQUAL	: found = true;
				          item = info[location] ;
				          break ;
   	  }
    }
}


void UnsortedType::InsertItem(ComputerType item)
{
	info[length] = item ;
	length++ ;
    
}


void UnsortedType::DeleteItem(ComputerType item) 
{
    int location = 0;

    while (item.ComparedTo(info[location]) != EQUAL)
	location++;

	info[location] = info[length - 1] ;
	length-- ;
}


void UnsortedType::ResetList()  
{    
   currentPos = -1;
}

void  UnsortedType::GetNextItem(ComputerType& item)  
{
   currentPos++;
   item = info[currentPos];
}
void UnsortedType::PrintList(ofstream& outFile)
{
  ComputerType item;
  ResetList();
  for(int i = 0; i<length; i++)
  {
     GetNextItem(item);
     item.PrintRd(outFile);
  }
}

void UnsortedType::PrintLap(ofstream& outFile)
{
  ComputerType item;
  ResetList();
  for(int i = 0; i<length; i++)
  {
     GetNextItem(item);
     if(item.lapYes(item))
     {
       outFile << "List Of Laptop" << endl;
       outFile << "--------------" << endl;
       item.PrintHeader(outFile);
       item.PrintRd(outFile);
     }
     else
     {
       outFile << "List is Empty! No Laptop List!" << endl;
     }
  }
}


void UnsortedType::PrintDesk(ofstream& outFile)
{
  ComputerType item;
  ResetList();
  for(int i = 0; i<length; i++)
  {
     GetNextItem(item);
     if(item.deskYes(item))
     {
       outFile << "List Of Desktop" << endl;
       outFile << "---------------" << endl;
       item.PrintHeader(outFile);
       item.PrintRd(outFile);
     }
     else
     {
       outFile << "List is Empty! No Desktop List!" << endl;
     }
  }
}

void UnsortedType::PrintMax(ofstream& outFile)
{
  ComputerType item;
  ResetList();
  for(int i = 0; i<length; i++)
  {
     GetNextItem(item);
     if(item.maxYes(item))
     {
       outFile << "List High RAM & Disk" << endl;
       outFile << "--------------------" << endl;
       item.PrintHeader(outFile);
       item.PrintRd(outFile);
     }
     else
     {
       outFile << "List is Empty! No Desktop List!" << endl;
     }
  }
}

