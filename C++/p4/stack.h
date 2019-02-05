#include <iostream>
#include <fstream>
#include <iomanip>
#include "ItemType.h"
#include "stdlib.h"
using namespace std;

const int MAX_ITEMS = 5;
class FullStack
{};
class EmptyStack
{};
class zero
{};

template <typename ItemType> //template to use multiple itemtypes
class StackType
{
public:
  StackType( );
    //PURPOSE: Default Constructor
    //PRE: None
    //INPUT: None
    //POST: Stack is created and empty
    //OUTPUT: None
    //NOTE:

  void MakeEmpty( );
    //PURPOSE: Empties stack
    //PRE: None
    //INPUT: None
    //POST: Stack is empty
    //OUTPUT: None
    //NOTE:

  bool IsEmpty( ) const;
    //PURPOSE: Reports if stack is empty
    //PRE: Stack has been initialized
    //INPUT: None
    //POST: bool value is returned
    //OUTPUT: bool value
    //NOTE:

  bool IsFull( ) const;
    //PURPOSE: Reports if stack is full
    //PRE:  Stack has been initialized
    //INPUT:  None
    //POST:  bool value is returned
    //OUTPUT:
    //NOTE:

  void Push(ItemType);
    //PURPOSE:  Adds item to top of stack
    //PRE:  Stack must be initialized and not full
    //INPUT:  Itemtype
    //POST:  Item has been pushed onto stack
    //OUTPUT:  None
    //NOTE:

  ItemType Evaluate(int, int, char, ItemType);
    //PURPOSE:  Evaluates expressions removed from stack
    //PRE:  Variables must be initialized and have values
    //INPUT:  item1, item2, op, newItem
    //POST:  values will have been evaluated
    //OUTPUT:  returns itemtype
    //NOTE:

  ItemType Pop();
    //PURPOSE: Pops item from top of the stack and assigns to variable
    //PRE:  Stack must be initialized and not be empty
    //INPUT:  None
    //POST:  top will be decremented and item removed from stack
    //OUTPUT:  returns itemtype
    //NOTE:

  void Print(ofstream& outFile, string line);
    //PURPOSE: Prints the final report if no special cases are thrown
    //PRE:  items must have been evaluated and outFile must be open
    //INPUT:  line
    //POST:  Final report will be printed
    //OUTPUT: Final report will be printed to outFile 
    //NOTE:

private:
  int top;
  ItemType item;
  ItemType items[MAX_ITEMS];	// array of ItemType 
};


template <typename ItemType>
    //PURPOSE: Default Constructor
    //PRE: None
    //INPUT: None
    //POST: Stack is created and empty
    //OUTPUT: None
    //NOTE:

StackType<ItemType>::StackType( )
{
  top = -1;
}

template <typename ItemType>
void StackType<ItemType>::MakeEmpty( )
    //PURPOSE: Empties stack
    //PRE: None
    //INPUT: None
    //POST: Stack is empty
    //OUTPUT: None
    //NOTE:

{
  top = -1;
}

template <typename ItemType>
bool StackType<ItemType>::IsEmpty( ) const
    //PURPOSE: Reports if stack is empty
    //PRE: Stack has been initialized
    //INPUT: None
    //POST: bool value is returned
    //OUTPUT: bool value
    //NOTE:

{
  return ( top == -1 );
}

template <typename ItemType>
bool StackType<ItemType>::IsFull( ) const
    //PURPOSE: Reports if stack is full
    //PRE:  Stack has been initialized
    //INPUT:  None
    //POST:  bool value is returned
    //OUTPUT:
    //NOTE:

{
  return  ( top == MAX_ITEMS-1);
}

template <typename ItemType>
void StackType<ItemType>::Push(ItemType newItem)
    //PURPOSE:  Adds item to top of stack
    //PRE:  Stack must be initialized and not full
    //INPUT:  Itemtype
    //POST:  Item has been pushed onto stack
    //OUTPUT:  None
    //NOTE:

{

  if(IsFull())
    throw FullStack();
  top++;
  items[top] = newItem;
}


template <typename ItemType>
ItemType StackType<ItemType>::Pop()
    //PURPOSE: Pops item from top of the stack and assigns to variable
    //PRE:  Stack must be initialized and not be empty
    //INPUT:  None
    //POST:  top will be decremented and item removed from stack
    //OUTPUT:  returns itemtype
    //NOTE:

{
   if(IsEmpty())
    throw EmptyStack();
   item = items[top];
   top--;
  return item;
}

template <typename ItemType>
ItemType StackType<ItemType>::Evaluate(int item1, int item2, char op, ItemType newItem)
    //PURPOSE:  Evaluates expressions removed from stack
    //PRE:  Variables must be initialized and have values
    //INPUT:  item1, item2, op, newItem
    //POST:  values will have been evaluated
    //OUTPUT:  returns itemtype
    //NOTE:

{
  if(op == '+')
    newItem = item1 + item2;
  if(op == '-')
    newItem = item1 - item2;
  if(op == '*')
    newItem = item1 * item2;
  if(op == '/')
    if (item2 != 0)
      newItem = item1 / item2;
    else
      throw zero();
  if(op == '%')
    newItem = item1 % item2;

return newItem;
}

template <typename ItemType>
void StackType<ItemType>::Print(ofstream& outFile, string line)
    //PURPOSE: Prints the final report if no special cases are thrown
    //PRE:  items must have been evaluated and outFile must be open
    //INPUT:  line
    //POST:  Final report will be printed
    //OUTPUT: Final report will be printed to outFile
    //NOTE:

{
  outFile << line << "~is OK!" << endl;
  outFile << " " << endl;
  outFile << "~~ Evaluation result: " << items[top]  << endl;
  outFile << " " << endl;
  outFile << "< end > " << endl;

}

