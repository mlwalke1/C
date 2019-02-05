#include <fstream>
#include <stddef.h>
#include <iomanip>
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
void UpdateNode(int tempID, char tempGrade, string tempMajor, string tempGender);
    //PURPOSE: to update existing nodes with new data
    //PRE: node must exist, tree must not be empty
    //INPUT: temp ID, tempGrade, tempMajor, tempGender
    //POST:  node will be updated
    //OUTPUT:
    //NOTE:
  void RetrieveItem(int& tempID, char& tempGrade, string& tempMajor, string& tempGender, bool& found);
    //PURPOSE:  finds item and reports data
    //PRE:  tree must not be empty
    //INPUT:  tempID, tempGrade, tempMajor, tempGender, found
    //POST:  puts found values into variables
    //OUTPUT: 
    //NOTE:
  int NodeCounter();
    //PURPOSE: To count nodes in the tree
    //PRE: tree must not be empty
    //INPUT: 
    //POST: returns number of nodes
    //OUTPUT: int
    //NOTE:
  int FindHeight();
    //PURPOSE: to find the height of the tree
    //PRE: tree must not be empty
    //INPUT: 
    //POST: returns height of tree
    //OUTPUT: int
    //NOTE:
  void DataConversion(string& tempMajor, string& tempGender);
    //PURPOSE: converts major and gender data to readable format
    //PRE:  major and gender must have data
    //INPUT: tempmajor, tempgender
    //POST: data is converted
    //OUTPUT:
    //NOTE:
  bool CheckValid(int tempID, char tempGrade, string tempMajor, string tempGender);
    //PURPOSE: checks if data is valid
    //PRE: data must be initialized
    //INPUT: tempID, tempGrade, tempMajor, tempGender
    //POST: bool will be returned
    //OUTPUT: bool
    //NOTE:
  void InsertItem(int tempID, char tempGrade, string tempMajor, string tempGender);
    //PURPOSE: inserts item into the tree
    //PRE: items must be valid
    //INPUT: tempID, tempGrade, tempMajor, tempGender
    //POST: items are inserted to tree
    //OUTPUT:
    //NOTE:
  void DeleteItem(int tempID);
    //PURPOSE: finds item and deletes from tree
    //PRE: tree must not be empty
    //INPUT: tempID
    //POST: item will be deleted
    //OUTPUT:
    //NOTE:
  void PrintInorder(ofstream& outFile) const;
    //PURPOSE: prints tree in order
    //PRE: tree must not be empty
    //INPUT: outFile
    //POST: data will be printed to outFile
    //OUTPUT:
    //NOTE:
  void PrintInpreorder(ofstream& outFile)const;
    //PURPOSE: prints tree in preorder
    //PRE: tree must not be empty
    //INPUT: outFile
    //POST: data will be printed to outFile
    //OUTPUT:
    //NOTE:
  void PrintInpostorder(ofstream& outFile)const;
    //PURPOSE: prints tree in postorder
    //PRE: tree must not be empty
    //INPUT: outFile
    //POST: data will be printed to outFile
    //OUTPUT:
    //NOTE:

 private:

  TreeNode* root;
};
