#include "search.h"

void QuickSortHelper(int idList[],int start,int end);
int partition(int idList[], int start, int end);

// Constructor
search::search(ifstream& inFile)
{
  for(int i = 0; i < tableSize; i++)
   inFile >> idList[i];

  for(int i = 0; i < hashTableSize; i++)
   hashList[i] = -1;
}

void search::PrintArray(ofstream& outFile)
{
 for(int i = 0; i < hashTableSize; i++)
   outFile << hashList[i] << endl;
}

// Sequential Search
void search::seqSearch(ofstream& outFile, int data, float& num)
{
  int count = 0;
  for(int i = 0; i < tableSize; i++)
  {
    count++;
    if(data == idList[i])
     break;
  }
  outFile << data  << "     " << count << endl;
  num += count;
}


// Quick Sort
void search::QuickSort()
{
  int start = 0;
  int end = tableSize;
  QuickSortHelper(idList, start, end);
}

void QuickSortHelper(int idList[],int start,int end)
{
  if(start >= end)return;
  int pIndex = partition(idList,start,end);
  QuickSortHelper(idList,start,pIndex - 1);
  QuickSortHelper(idList,pIndex + 1, end);
}

int partition(int idList[], int start, int end)
{
  int pivot = idList[end];
  int pIndex = start;
  for(int i = start; i <= (end - 1); i++)
  {
    if(idList[i]<= pivot)
    {
      int temp = idList[i];
      idList[i] = idList[pIndex];
      idList[pIndex] = temp;
      pIndex = pIndex +1;
    }
  }
  int temp = idList[pIndex];
  idList[pIndex] = idList[end];
  idList[end] = temp;
  return pIndex;
}

void search::binSearch(ofstream& outFile, int data, float& num)
{
  int first = 0;
  int last = tableSize -1;
  int middle = 0;
  bool found = false;
  int count = 0;
  while(last >= first && !found)
  {
    middle = (first + last) /2;
    if(data < idList[middle])
    {
      last = middle - 1;
      count ++;
    }
    else if (data > idList[middle])
    {
      first = middle + 1;
      count ++;
    }
    else
    {
      found = true;
      count++;
    }
  }
  outFile << data << "    " << count << endl;
  num += count;
}

void search::hashSort(int data)
{
  int key = data % 37;
  for(int i = 0; i < hashTableSize; i++)
  {
    if(hashList[key] == -1)
    {
     hashList[key] = data;
     break;
    }
    else
     key++;
  }
}

void search::hashSearch(ofstream& outFile, int data, float& num)
{
  int key = data % 37;
  int count = 1;
  for(int i = 0; i < hashTableSize; i++)
  {
    if(hashList[key] == data)
    {
     outFile << hashList[key] << "    " << count << endl;
     num += count;
     break;
    }
    else
    {
     count++;
     key++;
    }
  }
}

void search::doubHashSort(int data)
{
  int key = data % 37;
  int col = 0;
  for(int i = 0; i < hashTableSize; i++)
  {
    if(hashList[key] == -1)
    {
     hashList[key] = data;
     break;
    }
    else
     col++;
     key += ((col*((data%36)+1))%37);
  }
}

void search::doubHashSearch(ofstream& outFile, int data, float& num)
{
  int key = data % 37;
  int count = 1;
  int col = 0;
  for(int i = 0; i < hashTableSize; i++)
  {
    if(hashList[key] == data)
    {
     outFile << hashList[key] << "    " << count << endl;
     num += count;
     break;
    }
    else
     count++;
     col++;
     key += ((col*((data%36)+1))%37);
  }
}


