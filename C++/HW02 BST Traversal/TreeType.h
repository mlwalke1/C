#include <iostream>
#include <stddef.h>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

struct TreeNode;

class TreeType
{

 public:

  TreeType();
    //PURPOSE: Default constructor
    //PRE:
    //INPUT:
    //POST: intializes class object
    //OUTPUT: 
    //NOTE:
  ~TreeType();
    //PURPOSE: class destructor
    //PRE: 
    //INPUT:
    //POST: destroys class object
    //OUTPUT:
    //NOTE:
  bool IsEmpty() const;
    //PURPOSE: observer function checks if tree is empty
    //PRE:
    //INPUT:
    //POST: returns bool
    //OUTPUT: bool
    //NOTE:
  bool IsFull() const;
    //PURPOSE: observer function checks if tree is full
    //PRE:
    //INPUT:
    //POST: returns bool
    //OUTPUT: bool
    //NOTE:

  void InsertItem(int info);
    //PURPOSE: inserts item into the tree
    //PRE: i
    //INPUT: info
    //POST: info  inserted to tree
    //OUTPUT:
    //NOTE:
	
	void Print() const;
    //PURPOSE: prints tree traversals
    //PRE: tree must not be empty
    //INPUT: 
    //POST: data will be printed to cout
    //OUTPUT:
    //NOTE:


 private:

  TreeNode* root;
};

