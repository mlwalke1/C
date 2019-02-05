//*********************************************************************************
//AUTHOR                            :Mathew Walker
//COURSE TITLE                      :Computer Programming II
//COURSE NUMBER                     :CS216
//CLASS MEETS                       :MW/8:30-10:20
//PROF NAME                         :Moe Bidgoli
//ASSIGNMENT NUMBER                 :#11
//DUE DATE                          :12-03-2015
//POSIBLE POINTS                    :30
//PURPOSE:
//  This program will read ID numbers organize them into an
//  array in 4 different ways, measure the average number
//  of probes per search method and report it to an out file .
//*********************************************************************************

#include "search.h"


int main(){

ifstream inFile;
ofstream outFile;
inFile.open("in.data");
outFile.open("out.data");

if (inFile.fail() || outFile.fail())
  {
    outFile << "Check your input and output file!" << endl;
    return 1;
  }


search item(inFile);

int data = 0;
float num = 0;
static const int tableSize = 20;

// 1) Successful Sequential Search
inFile.close();
inFile.open("in.data");

outFile << "<<<***Successful Sequential Search***>>>" << endl;
outFile << "ID   " << "Number of Comparison" << endl;
outFile << "---  " << "--------------------" << endl;

inFile >> data;
for(int i = 0; i < tableSize; i++) // Successful Sequencial Search
{
  item.seqSearch(outFile, data, num);
  inFile >> data;
}
outFile << " " << endl;
outFile << "Average Number of Probes: " << num/tableSize << endl;
outFile << " " << endl;
num = 0;


// 2) Unsuccessful Sequential Search
outFile << "<<<***Unsuccessful Sequential Search***>>>" << endl;
outFile << "ID   " << "Number of Comparison" << endl;
outFile << "---  " << "--------------------" << endl;


for(int i = 0; i < tableSize; i++) // Unsuccessful Sequencial Search
{
  item.seqSearch(outFile, data, num);
  inFile >> data;
}

outFile << " " << endl;
outFile << "Average Number of Probes: " << num/tableSize << endl;
outFile << " " << endl;
num = 0;

// 3) Successful Binary Search
inFile.close();
inFile.open("in.data");

item.QuickSort();

outFile << "<<<***Successful Binary Search***>>>" << endl;
outFile << "ID   " << "Number of Comparison" << endl;
outFile << "---  " << "--------------------" << endl;

inFile >> data;
for(int i = 0; i < tableSize; i++) // Successful Binary Search
{
  item.binSearch(outFile, data, num);
  inFile >> data;
}
outFile << " " << endl;
outFile << "Average Number of Probes: " << num/tableSize << endl;
outFile << " " << endl;
num = 0;

// 4) Unsuccessful Binary Search
outFile << "<<<***Successful Binary Search***>>>" << endl;
outFile << "ID   " << "Number of Comparison" << endl;
outFile << "---  " << "--------------------" << endl;

for(int i = 0; i < tableSize; i++) // Unsuccessful Binary Search
{
  item.binSearch(outFile, data, num);
  inFile >> data;
}

outFile << " " << endl;
outFile << "Average Number of Probes: " << num/tableSize << endl;
outFile << " " << endl;
num = 0;

// 5) Successful Hash Search
inFile.close();
inFile.open("in.data");

inFile >> data;
for(int i = 0; i < tableSize; i++)
{
  item.hashSort(data);
  inFile >> data;
}

outFile << "<<<***Successful Hash Method Search***>>>" << endl;
outFile << "ID   " << "Number of Comparison" << endl;
outFile << "---  " << "--------------------" << endl;


inFile.close();
inFile.open("in.data");

inFile >> data;
for(int i = 0; i < tableSize; i++)
{
  item.hashSearch(outFile,data,num);
  inFile >> data;
}

outFile << " " << endl;
outFile << "Average Number of Probes: " << num/tableSize << endl;
outFile << " " << endl;
num = 0;


outFile << "<<<***Unsuccessful Hash Method Search***>>>" << endl;
outFile << "ID   " << "Number of Comparison" << endl;
outFile << "---  " << "--------------------" << endl;

inFile >> data;
for(int i = 0; i < tableSize; i++)
{
  item.hashSearch(outFile,data,num);
  inFile >> data;
}

outFile << " " << endl;
outFile << "Average Number of Probes: " << num/tableSize << endl;
outFile << " " << endl;
num = 0;



inFile.close();
inFile.open("in.data");

search item2(inFile);


inFile.close();
inFile.open("in.data");

// 7) Successful Double Hash Search

inFile >> data;
for(int i = 0; i < tableSize; i++)
{
  item2.doubHashSort(data);
  inFile >> data;
}

outFile << "<<<***Successful Double Hash Search***>>>" << endl;
outFile << "ID   " << "Number of Comparison" << endl;
outFile << "---  " << "--------------------" << endl;


inFile.close();
inFile.open("in.data");

inFile >> data;
for(int i = 0; i < tableSize; i++)
{
  item2.doubHashSearch(outFile, data, num);
  inFile >> data;
}

outFile << " " << endl;
outFile << "Average Number of Probes: " << num/tableSize << endl;
outFile << " " << endl;
num = 0;


outFile << "<<<***Unsuccessful Double Hash Search***>>>" << endl;
outFile << "ID   " << "Number of Comparison" << endl;
outFile << "---  " << "--------------------" << endl;

inFile >> data;
for(int i = 0; i < tableSize; i++)
{
  item2.doubHashSearch(outFile, data, num);
  inFile >> data;
}

outFile << " " << endl;
outFile << "Average Number of Probes: " << num/tableSize << endl;
outFile << " " << endl;
num = 0;


return 0;
}
