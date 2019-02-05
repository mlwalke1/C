//*********************************************************************************
//AUTHOR                            :Mathew Walker
//COURSE TITLE                      :Advanced Algorithm and Data Analysis
//COURSE NUMBER                     :CS316
//CLASS MEETS                       :MW/12:30-2:20
//PROF NAME                         :Dr. Rahman
//ASSIGNMENT NUMBER                 :#2
//DUE DATE                          :10-04-2017
//POSIBLE POINTS                    :35
//PURPOSE: User inputs integers separated by a space, the programs gets the line parses it converts to integer
//                inserts each integer into a binary tree, the prints the binary tree with several traversals   
//
//*********************************************************************************

#include "TreeType.h"

int main(){

//PRINT Header
cout << "<~~~ Binary Tree Report ~~~>" << endl;
cout << endl;
cout << "Enter integers: " << endl;

//Initialize variables
TreeType dataTree;
string line;
string delimiter = " ";

//Get user input
getline(cin,line);

size_t last = 0; 
size_t next = 0; 
while ((next = line.find(delimiter, last)) != string::npos) 
{ 
  string temp = line.substr(last, next-last);
  int info = atoi(temp.c_str());
  dataTree.InsertItem(info); 
  last = next + 1; 
} 

string temp;
temp = line.substr(last);
dataTree.InsertItem(atoi(temp.c_str()));

dataTree.Print();


return 0;

}

