#include "SortedLinkedList.h"

// SortedType.cxx
SortedType::SortedType()  // Class constructor
  //PURPOSE: Constructer for initializing values
  //PRE: none
  //INPUT: none
  //POST: values are initialized
  //OUTPUT: none
  //NOTE:
{
  length = 0;
  listData = NULL;
}

SortedType::~SortedType()
  //PURPOSE: Destructor for destroying list
  //PRE: list must exist
  //INPUT: none
  //POST: list is destroyed
  //OUTPUT: none
  //NOTE:
{
  MakeEmpty();
}

SortedType::SortedType(const SortedType& otherList)
  //PURPOSE: copy constructor
  //PRE: none
  //INPUT: none
  //POST: list is created as duplicate of other list
  //OUTPUT: none
  //NOTE:
{
    NodeType* fromPtr;  // Pointer into list being copied from
    NodeType* toPtr;    // Pointer into new list being built
    if(otherList.listData == NULL)
    {
        listData = NULL;
        return;
    }
    // Copy first node
    fromPtr = otherList.listData;
    listData = new NodeType;
    listData->info = fromPtr->info;

    // Copy remaining nodes

    toPtr = listData;
    fromPtr = fromPtr->next;
    while (fromPtr != NULL)
    {
        toPtr->next = new NodeType;
        toPtr = toPtr->next;
        toPtr->info = fromPtr->info;
        fromPtr = fromPtr->next;
    }
    toPtr->next = NULL;
}

bool SortedType::IsFull() const
  //PURPOSE: to check if the list is full
  //PRE: a list must exist
  //INPUT: none
  //POST: returns true or false if there is room in the list
  //OUTPUT: bool
  //NOTE:
{
  NodeType* ptr;

  ptr = new NodeType;
  if (ptr == NULL)
    return true;
  else
  {
    delete ptr;
    return false;
  }
}

int SortedType::LengthIs() const
  //PURPOSE: to find the length of the list
  //PRE: list must exist
  //INPUT: none
  //POST: returns the length of the list
  //OUTPUT: int
  //NOTE:
{
  return length;
}

void SortedType::MakeEmpty()
  //PURPOSE: empties the list
  //PRE: list must exist and have values
  //INPUT: none
  //POST: list is emptied
  //OUTPUT: none
  //NOTE:
{
  NodeType* tempPtr;
  while (listData != NULL) // traverse list, deallocating each node in turn
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
}

void SortedType::DeleteItem(int item)
  //PURPOSE: deletes item from the list
  //PRE: item must exist in list
  //INPUT: item
  //POST: item will be deleted
  //OUTPUT: none
  //NOTE:
{
  NodeType* location = listData;
  NodeType* tempLocation;

  // Locate node to be deleted.
  if (item == listData->info)
  {
    tempLocation = location;
    listData = listData->next;      // Delete first node.
  }
  else
  {
    while (!(item==(location->next)->info))
       location = location->next;

     tempLocation = location->next;
     location->next = (location->next)->next;
  }
  delete tempLocation;
  length--;
}

void SortedType::ResetList()
  //PURPOSE: resets pointer to beginning of list
  //PRE: none
  //INPUT: none
  //POST: pointer is reset to beginning of list
  //OUTPUT: none
  //NOTE:
{
  currentPos = NULL;
}


void SortedType::RetrieveItem(int& item, float& gpa, bool &found)
  //PURPOSE: finds an item within the list
  //PRE: list must exist and have data
  //INPUT: item, gpa, and found
  //POST: item and gpa are found
  //OUTPUT: none
  //NOTE:
{
 bool moreToSearch;
 NodeType* location;

 location = listData;
 found = false;
 moreToSearch = (location != NULL);

 while (moreToSearch && !found)
 {
  if(location->info < item)
  {
   location = location->next;
   moreToSearch = (location != NULL);
  }
  else
  {
    if(item == location->info)
    {
      found = true;
      item = location->info;
      gpa = location->gpa;
    }
    else
     moreToSearch = false;
  }
 }
}

void SortedType::InsertItem(int item, float gpa)
  //PURPOSE: inserts item into a list
  //PRE: list must exist
  //INPUT: item and gpa
  //POST: item and gpa are added to the list
  //OUTPUT: none
  //NOTE:
{
  NodeType* newNode;  // pointer to node being inserted
  NodeType* predLoc;  // trailing pointer
  NodeType* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if(location->info < item)
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType;
  newNode->info = item;
  newNode->gpa = gpa;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}

void SortedType::GetNextItem(int& item)
  //PURPOSE: gets the next element in the list
  //PRE: list must exist with data
  //INPUT: item
  //POST: if the current position is at end it returns to front of lis
  //      advances the current position and item is copy of current item
  //OUTPUT: none
  //NOTE:
{

  if (currentPos == NULL) //Wrap at end of list
    currentPos = listData;

  item = currentPos->info;
  currentPos = currentPos->next;
}

void SortedType::Print(ofstream& outFile, int invalid)
  //PURPOSE: to print the list
  //PRE: list must not be empty
  //INPUT: invalid
  //POST: list and summary are printed
  //OUTPUT: list printed to outfile
  //NOTE:
{
   currentPos = listData;
   outFile << "*" << currentPos->info << "(" << setprecision(2) << fixed << currentPos->gpa << ")";
   currentPos = currentPos->next;


   while(currentPos != NULL)
   {
       outFile  << " -> " << currentPos->info << "(" << setprecision(2)<< fixed << currentPos->gpa << ")";
       currentPos = currentPos->next;
   }
   outFile << endl;
   outFile << ">>> Number Of Item(s) In The List:" << length << endl;
   outFile << ">>> Number Of Invalid Data:" << invalid << endl;
   outFile << " " << endl;
}

bool SortedType::checkValid(int item, float gpa)
  //PURPOSE: to check if data is valid
  //PRE: item and gpa must exist
  //INPUT: item and gpa
  //POST: item and gpa are checked for validity
  //OUTPUT: bool
  //NOTE:
{
 bool valid = true;
 if(item >= 111 && item <= 999)
   valid = true;
 else return false;


 if(gpa >= 0.00 && gpa <= 4.00)
   valid = true;
 else return false;
 return valid;
}



