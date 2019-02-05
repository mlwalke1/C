#include  "ComputerType.h"

class  UnsortedType	
{			
 public :

   UnsortedType();
   void MakeEmpty();
   bool IsFull() const;              
   int LengthIs() const;  
   void RetrieveItem(ComputerType& item, bool& found);
   void InsertItem(ComputerType item); 	
   void DeleteItem(ComputerType item); 	
   void ResetList();
   void GetNextItem(ComputerType& item) ; 	 
   void PrintList(ofstream& outFile);
   void PrintLap(ofstream& outFile);
   void PrintDesk(ofstream& outFile);
   void PrintMax(ofstream& outFile);

 private :

  int length ;           
  ComputerType info[MAX_ITEMS] ;          
  int currentPos ;
} ;
