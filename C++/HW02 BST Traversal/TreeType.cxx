//TreeType.cxx

#include "TreeType.h"
void Destroy(TreeNode* &tree);
void InsertHelper(TreeNode* &ptr, int);
void LVR(TreeNode* tree);
void RVL(TreeNode* tree);
void VLR(TreeNode* tree);
void VRL(TreeNode* tree);
void LRV(TreeNode* tree);
void RLV(TreeNode* tree);


struct TreeNode
{
  int info;
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


void TreeType::InsertItem(int info)
//PURPOSE: inserts item into the tree
//PRE: 
//INPUT: 
//POST: info  inserted to tree
//OUTPUT:
//NOTE:

{
  InsertHelper(root, info);
}


void InsertHelper(TreeNode* &ptr, int info)
{
  if (ptr == NULL)
  {
     ptr =new TreeNode;
     ptr->right = NULL;
     ptr->left = NULL;
     ptr->info = info;
  }
  else if(info < ptr->info)
          InsertHelper(ptr->left, info);
  else if(info > ptr->info)
          InsertHelper(ptr->right, info);
}

void TreeType::Print() const
//PURPOSE: prints tree in order
//PRE: tree must not be empty
//INPUT: outFile
//POST: data will be printed to outFile
//OUTPUT:
//NOTE:
{
  cout << "Depth First Traversal: Inorder, LVR -> " ;
  LVR(root);
  cout << endl;
  cout << "Depth First Traversal: Inorder, RVL -> " ;
  RVL(root);
  cout << endl;
  cout << "Depth First Traversal: Inorder, VLR -> " ;
  VLR(root);
  cout << endl;
  cout << "Depth First Traversal: Inorder, VRL -> " ;
  VRL(root);
  cout << endl;
  cout << "Depth First Traversal: Inorder, LRV -> " ;
  LRV(root);
  cout << endl;
  cout << "Depth First Traversal: Inorder, RLV -> " ;
  RLV(root);
  cout << endl;
  
}

void LVR(TreeNode* tree)
{
  if (tree != NULL)
  {
    LVR(tree->left);   // Print left subtree.
    cout << tree->info <<  " ";
    LVR(tree->right);  // Print right subtree.
  }
}



void VLR(TreeNode* tree)
{
  if (tree != NULL)
  {
    cout << tree->info << " ";
    VLR(tree->left);   // Print left subtree.
    VLR(tree->right);  // Print right subtree.
  }
}



void RVL(TreeNode* tree)
{
  if (tree != NULL)
  {
    RVL(tree->right);   // Print left subtree.
	cout << tree->info << " ";
    RVL(tree->left);  // Print right subtree.

  }
}


void VRL(TreeNode* tree)
{
  if (tree != NULL)
  {
	cout << tree->info << " ";
    VRL(tree->right);   // Print left subtree.
    VRL(tree->left);  // Print right subtree.

  }
}

void LRV(TreeNode* tree)
{
  if (tree != NULL)
  {
    LRV(tree->left);   // Print left subtree.
    LRV(tree->right);  // Print right subtree.
    cout << tree->info << " ";
  }
}

void RLV(TreeNode* tree)
{
  if (tree != NULL)
  {
    RLV(tree->right);   // Print left subtree.
    RLV(tree->left);  // Print right subtree.
	cout << tree->info << " ";

  }
}


