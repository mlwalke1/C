#include <fstream>
#include <stddef.h>
#include <iomanip>

using namespace std;


struct NodeType
{
  int info;
  float gpa;
  NodeType* next;
};

// SortedType.h
class SortedType
{
 public:
  SortedType();
  //PURPOSE: Constructer for initializing values
  //PRE: none
  //INPUT: none
  //POST: values are initialized
  //OUTPUT: none
  //NOTE:
  ~SortedType();
  //PURPOSE: Destructor for destroying list
  //PRE: list must exist
  //INPUT: none
  //POST: list is destroyed
  //OUTPUT: none
  //NOTE:
  SortedType(const SortedType& otherList);
  //PURPOSE: copy constructor
  //PRE: none
  //INPUT: none
  //POST: list is created as duplicate of other list
  //OUTPUT: none
  //NOTE:

  bool IsFull() const;
  //PURPOSE: to check if the list is full
  //PRE: a list must exist
  //INPUT: none
  //POST: returns true or false if there is room in the list
  //OUTPUT: bool
  //NOTE:

  int  LengthIs() const;
  //PURPOSE: to find the length of the list
  //PRE: list must exist
  //INPUT: none
  //POST: returns the length of the list
  //OUTPUT: int
  //NOTE:

  void MakeEmpty();
  //PURPOSE: empties the list
  //PRE: list must exist and have values
  //INPUT: none
  //POST: list is emptied
  //OUTPUT: none
  //NOTE:

  void RetrieveItem(int& item, float& gpa, bool& found);
  //PURPOSE: finds an item within the list
  //PRE: list must exist and have data
  //INPUT: item, gpa, and found
  //POST: item and gpa are found
  //OUTPUT: none
  //NOTE:

  void InsertItem(int item, float gpa);
  //PURPOSE: inserts item into a list
  //PRE: list must exist
  //INPUT: item and gpa
  //POST: item and gpa are added to the list
  //OUTPUT: none
  //NOTE:

  void DeleteItem(int item);
  //PURPOSE: deletes item from the list
  //PRE: item must exist in list
  //INPUT: item
  //POST: item will be deleted
  //OUTPUT: none
  //NOTE:

  void ResetList();
  //PURPOSE: resets pointer to beginning of list
  //PRE: none
  //INPUT: none
  //POST: pointer is reset to beginning of list
  //OUTPUT: none
  //NOTE:

  void GetNextItem(int& item);
  //PURPOSE: gets the next element in the list
  //PRE: list must exist with data
  //INPUT: item
  //POST: if the current position is at end it returns to front of lis
  //      advances the current position and item is copy of current item
  //OUTPUT: none
  //NOTE:

  void Print(ofstream& outFile, int invalid);
  //PURPOSE: to print the list
  //PRE: list must not be empty
  //INPUT: invalid
  //POST: list and summary are printed
  //OUTPUT: list printed to outfile
  //NOTE:

  bool checkValid(int item, float gpa);
  //PURPOSE: to check if data is valid
  //PRE: item and gpa must exist
  //INPUT: item and gpa
  //POST: item and gpa are checked for validity
  //OUTPUT: bool
  //NOTE:

 private:
  NodeType* listData;
  int length;
  NodeType* currentPos;
};
