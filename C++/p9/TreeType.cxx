//TreeType.cxx

#include "TreeType.h"

void Destroy(TreeNode* &tree);
void RetrieveHelper(TreeNode* tree, int &tempID, char& tempGrade, string& tempMajor, string& tempGender,  bool &found);
int NodeHelper(TreeNode* ptr,  int node);
void UpdateHelper(TreeNode* tree, int tempID, char tempGrade, string tempMajor, string tempGender);
void InsertHelper(TreeNode* &ptr, int, char, string, string);
void Delete(TreeNode* &tree, int tempID);
void DeleteNode(TreeNode* &tree);
void GetPredecessor(TreeNode* tree, int& id, char& gra, string& maj, string& gen);
void Inorder(TreeNode* tree, ofstream& outFile);
int HeightHelper(TreeNode* ptr);
void Inpreorder(TreeNode* tree, ofstream& outFile);
void Inpostorder(TreeNode* tree, ofstream& outFile);


struct TreeNode
{
  int studID;
  char grade;
  string major;
  string gender;
  TreeNode* left;
  TreeNode* right;
};

TreeType::TreeType()
//PURPOSE: Default constructor
//PRE:
//INPUT:
//POST: intializes class object
//OUTPUT:
//NOTE:
{
  root = NULL;
}

TreeType::~TreeType()
//PURPOSE: class destructor
//PRE:
//INPUT:
//POST: destroys class object
//OUTPUT:
//NOTE:

{
  Destroy(root);
}

void Destroy(TreeNode* &tree)
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}

bool TreeType::IsEmpty() const
//PURPOSE: observer function checks if tree is empty
//PRE:
//INPUT:
//POST: returns bool
//OUTPUT: bool
//NOTE:
{
  return (root == NULL);
}

bool TreeType::IsFull() const
//PURPOSE: observer function checks if tree is full
//PRE:
//INPUT:
//POST: returns bool
//OUTPUT: bool
//NOTE:
//TreeType.cxx
{
   TreeNode* ptr;

   ptr = new TreeNode;
   if(ptr == NULL)
     return true;
   else
   {
     delete ptr;
     return false;
   }
}

void TreeType::UpdateNode(int tempID, char tempGrade, string tempMajor, string tempGender)
//PURPOSE: to update existing nodes with new data
//PRE: node must exist, tree must not be empty
//INPUT: temp ID, tempGrade, tempMajor, tempGender
//POST:  node will be updated
//OUTPUT:
//NOTE:

{
  UpdateHelper(root, tempID, tempGrade, tempMajor, tempGender);
}

void UpdateHelper(TreeNode* tree, int tempID, char tempGrade, string tempMajor, string tempGender)
{
  if (tree->studID > tempID)
    UpdateHelper(tree->left, tempID, tempGrade, tempMajor, tempGender);    // Search left subtree.
  else if (tree->studID < tempID)
    UpdateHelper(tree->right, tempID, tempGrade, tempMajor, tempGender);   // Search right subtree.
  else
  {
    tree->studID = tempID;
    tree->grade = tempGrade;                           // item is found.
    tree->major = tempMajor;                           // item is found.
    tree->gender = tempGender;                           // item is found.
  }
}

void TreeType::RetrieveItem(int& tempID, char& tempGrade, string& tempMajor, string& tempGender, bool& found)
//PURPOSE:  finds item and reports data
//PRE:  tree must not be empty
//INPUT:  tempID, tempGrade, tempMajor, tempGender, found
//POST:  puts found values into variables
//OUTPUT:
//NOTE:

{
  RetrieveHelper(root, tempID, tempGrade, tempMajor, tempGender, found);
}

void RetrieveHelper(TreeNode* tree, int &tempID, char& tempGrade, string& tempMajor, string& tempGender,  bool &found)
{
  if (tree == NULL)
    found = false;                              // item is not found.
  else if (tree->studID > tempID)
    RetrieveHelper(tree->left, tempID, tempGrade, tempMajor, tempGender, found);    // Search left subtree.
  else if (tree->studID < tempID)
    RetrieveHelper(tree->right, tempID, tempGrade, tempMajor, tempGender, found);   // Search right subtree.
  else
  {
    tempID = tree->studID;
    tempGrade = tree->grade;                           // item is found.
    tempMajor = tree->major;                           // item is found.
    tempGender = tree->gender;                           // item is found.
    found = true;
  }
}

void TreeType::DataConversion(string& tempMajor, string& tempGender)
//PURPOSE: converts major and gender data to readable format
//PRE:  major and gender must have data
//INPUT: tempmajor, tempgender
//POST: data is converted
//OUTPUT:
//NOTE:
{
  if(tempMajor == "C")
    tempMajor = "Computer Science";
  if(tempMajor == "I")
    tempMajor = "Information System";
  if(tempGender == "M")
    tempGender = "Male";
  if(tempGender == "F")
    tempGender = "Female";
}
bool TreeType::CheckValid(int tempID, char tempGrade, string tempMajor, string tempGender)
//PURPOSE: checks if data is valid
//PRE: data must be initialized
//INPUT: tempID, tempGrade, tempMajor, tempGender
//POST: bool will be returned
//OUTPUT: bool
//NOTE:
{
  if(tempID < 111 || tempID > 999)
   return false;
  else if(tempGrade != 'A' && tempGrade != 'B' && tempGrade != 'C' && tempGrade != 'D' && tempGrade != 'F')
   return false;
  else if(tempMajor != "C" && tempMajor != "I")
   return false;
  else if(tempGender != "M" && tempGender != "F")
   return false;
  else return true;
}

int TreeType::NodeCounter()
//PURPOSE: To count nodes in the tree
//PRE: tree must not be empty
//INPUT:
//POST: returns number of nodes
//OUTPUT: int
//NOTE:
{
  int node = 0;
  return NodeHelper(root, node);
}

int NodeHelper(TreeNode* ptr, int node)
{
   if(ptr != NULL)
   {
     node = 1 +NodeHelper(ptr->right, node) + NodeHelper(ptr->left, node);
   }
   return node;
}

int TreeType::FindHeight()
//PURPOSE: to find height of tree
//PRE: tree must not be empty
//INPUT:
//POST: returns height of tree
//OUTPUT: int
//NOTE:

{
 int height = HeightHelper(root);
 return height;
}

int HeightHelper(TreeNode* ptr)
{
    if(ptr == 0)
      return -1;
    int lefth = HeightHelper(ptr->left);
    int righth = HeightHelper(ptr->right);

    if(lefth > righth)
        return lefth + 1;
    else
        return righth +1;
}

void TreeType::InsertItem(int tempID, char tempGrade, string tempMajor, string tempGender)
//PURPOSE: inserts item into the tree
//PRE: items must be valid
//INPUT: tempID, tempGrade, tempMajor, tempGender
//POST: items are inserted to tree
//OUTPUT:
//NOTE:

{
  InsertHelper(root, tempID, tempGrade, tempMajor, tempGender);
}


void InsertHelper(TreeNode* &ptr, int tempID, char tempGrade, string tempMajor,  string tempGender)
{
  if (ptr == NULL)
  {
     ptr =new TreeNode;
     ptr->right = NULL;
     ptr->left = NULL;
     ptr->studID = tempID;
     ptr->grade = tempGrade;
     ptr->major = tempMajor;
     ptr->gender = tempGender;
  }
  else if(tempID < ptr->studID)
          InsertHelper(ptr->left, tempID, tempGrade, tempMajor, tempGender);
  else if(tempID > ptr->studID)
          InsertHelper(ptr->right, tempID, tempGrade, tempMajor, tempGender);
}


void TreeType::DeleteItem(int tempID)
//PURPOSE: finds item and deletes from tree
//PRE: tree must not be empty
//INPUT: tempID
//POST: item will be deleted
//OUTPUT:
//NOTE:

{
    Delete(root, tempID);
}

void Delete(TreeNode* &tree, int tempID)
{
  if (tree->studID > tempID)
     Delete(tree->left, tempID);
  else
     if (tree->studID < tempID)
	Delete(tree->right, tempID);
     else
        DeleteNode(tree);
}


void DeleteNode(TreeNode* &tree)
{
  int id;
  char gra;
  string maj;
  string gen;
  TreeNode* tempPtr;
  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else
    if (tree->right == NULL)
    {
       tree = tree->left;
       delete tempPtr;
    }
    else
    {
       GetPredecessor(tree->left, id, gra, maj, gen);
       tree->studID = id;
       tree->grade = gra;
       tree->major = maj;
       tree->gender = gen;
       Delete(tree->left, id);    // Delete predecessor node.
    }
}

void GetPredecessor(TreeNode* tree, int& id, char& gra, string& maj, string& gen)
{
  while (tree->right != NULL)
    tree = tree->right;
  id = tree->studID;
  gra = tree->grade;
  maj = tree->major;
  gen = tree->gender;
}


void TreeType::PrintInorder(ofstream& outFile) const
//PURPOSE: prints tree in order
//PRE: tree must not be empty
//INPUT: outFile
//POST: data will be printed to outFile
//OUTPUT:
//NOTE:
{
  Inorder(root, outFile);
}

void Inorder(TreeNode* tree, ofstream& outFile)
{
  if (tree != NULL)
  {
    Inorder(tree->left, outFile);   // Print left subtree.
    outFile << tree->studID << " " << tree->grade << endl;
    Inorder(tree->right, outFile);  // Print right subtree.
  }
}

void TreeType::PrintInpreorder(ofstream& outFile) const
//PURPOSE: prints tree in preorder
//PRE: tree must not be empty
//INPUT: outFile
//POST: data will be printed to outFile
//OUTPUT:
//NOTE:
{
  Inpreorder(root, outFile);
}

void Inpreorder(TreeNode* tree, ofstream& outFile)
{
  if (tree != NULL)
  {
    outFile << tree->studID << " " << tree->grade << endl;
    Inorder(tree->left, outFile);   // Print left subtree.
    Inorder(tree->right, outFile);  // Print right subtree.
  }
}


void TreeType::PrintInpostorder(ofstream& outFile) const
//PURPOSE: prints tree in postorder
//PRE: tree must not be empty
//INPUT: outFile
//POST: data will be printed to outFile
//OUTPUT:
//NOTE:

{
  Inpostorder(root, outFile);
}

void Inpostorder(TreeNode* tree, ofstream& outFile)
{
  if (tree != NULL)
  {
    Inorder(tree->left, outFile);   // Print left subtree.
    Inorder(tree->right, outFile);  // Print right subtree.
    outFile << tree->studID << " " << tree->grade << endl;
  }
}

