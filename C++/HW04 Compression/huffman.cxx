using namespace std;
#include <iostream>
#include <string>
#include <queue>

#include "huffman.h"

void LVR(TreeType*, string);
string maxCode = "";

int main() {
	
	//1. get characters from user input
	string characters;
	cout << "Enter Characters to be Compressed: " << endl;
	cin >> characters;
	cout << "You Entered: " << characters << endl;

	//2. calculate character frequencies and organize with priority queue
	priority_queue<TreeType_wsk, vector<TreeType_wsk>,MyComparator> freq;
	
	for (int i=0; characters.length() > i; i++)
	{
		char data = characters[i];
		int value = 1;
		for (int j = i+1; characters.length() > j; j++) {
			if(characters[i] == characters[j]) {
				value++;
				characters.erase(j,1);
				j--;
			}
		}
		TreeType *temp = new TreeType;
		temp->value = value;
		temp->data = data;
		freq.push(temp);
	}
	
	//3. empty queue into BST tree for compression code
	
	TreeType * root;
	
	while(!freq.empty())
	{
		if(freq.size() >= 2)
		{
			TreeType *tempNode1 = new TreeType;
			tempNode1->left = freq.top();
			freq.pop();
			tempNode1->right = freq.top();
			freq.pop();
			tempNode1->value = tempNode1->left->value + tempNode1->right->value;
			tempNode1->data = ' ';
			freq.push(tempNode1);
			
		}
		else if (freq.size() == 1)
		{
			root = freq.top();
			freq.pop();
		}
	}
	
	//traverse tree to print values and binary code
	string binCode = "";
	LVR(root, binCode);
	cout << "Compression Ratio = " << maxCode.length() <<  "/" << (root->value * 8)  <<endl;
	return 0;
}


void LVR(TreeType* tree, string binCode)
{
  if (tree != NULL)
  {
	LVR(tree->left, (binCode+= "1"));  
	if (tree->data != ' ')
	{
		maxCode += binCode;
		cout << tree->data <<  " : " << tree->value << " Code - " << binCode << endl;
	}
    LVR(tree->right, (binCode += "0"));   
  } 
}