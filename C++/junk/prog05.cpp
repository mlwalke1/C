// Filename:     prog05.cpp
// Author:       Mathew Walker, CS116, Winter 2015
// Description:  This program processes numbers from an input file and prints them to an output file.
//               The process puts numbers into an array, adds one to the even numbers and adds two to
//               the numbers with an odd index in the array. The process determines the minimum, maximum,
//               average, and numbers greather than 100, and sorts the numbers, while printing all the information
//               to an output file.
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void getData(ifstream& inData, int numbArray[] [10], int& i, int& j);
void addOne(int numbArray[] [10], int &i, int &j);
void addToOddIndex(int numbArray[] [10], int& i, int& j);
void printData(ofstream& outData, int numbArray[] [10], int& i, int &j);
void findMaxMin(int numbArray[] [10], int& max, int& min, int& i, int& j);
float findAvg(float& avg, float& total);
void printMaxMinAvg(ofstream& outData, int& max, int& min, float& avg, float& total);
void findPrintMoreThan100(ofstream& outData, int numbArray[] [10], int& i, int& j);
void BubbleSort(int numbArray[] [10]);
void selSort(int numbArray[] [10], int sortArray[] [10]);
void printSortData(ofstream& outData, int sortArray[] [10], int& i, int &j);

int main(){
    
    ifstream inData;
    ofstream outData;
    outData.open("out.data");
    int i = 0;
    int j = 0;
    int max;
    int min = 99999;
    float avg = 0;
    float total = 0;
    int numbArray [10] [10];
    int sortArray [10] [10];
    
    while (j < 10){
        i = 0;
        inData.open("1.data");
        while (i < 10){
            getData(inData, numbArray, i, j);
            addOne(numbArray, i, j);
            addToOddIndex(numbArray, i, j);
            findMaxMin(numbArray, max, min, i, j);
            total = numbArray [i] [j] + total;
            i++;

        }
        j++;
        inData.close();
    }
    
    printData(outData, numbArray, i, j);
    printMaxMinAvg(outData, max, min, avg, total);
    findPrintMoreThan100(outData, numbArray, i, j);
    BubbleSort(numbArray);
    printData(outData, numbArray, i, j);
   // selSort(numbArray, sortArray);
    //printSortData(outData, sortArray, i, j);


    
    return 0;
}

void getData(ifstream& inData, int numbArray[] [10], int& i, int& j){
    inData >> numbArray [i] [j];
}

void addOne(int numbArray[] [10], int& i, int& j){
    if (numbArray [i] [j] % 2 == 0){
        numbArray [i] [j] += 1;
    }
    
}

void addToOddIndex(int numbArray[] [10], int& i, int& j){
    if (i % 2 > 0){
        numbArray [i] [j] += 2;
    }
}

void printData(ofstream& outData, int numbArray[] [10], int& i, int &j){
        i=0;
        j=0;
        while (i < 10){
            outData << endl;
            j = 0;
            while (j < 10){
                outData << setw(4) << left << numbArray [i] [j];
                j++;
            }
            i++;
        }
}

void findMaxMin(int numbArray[] [10], int& max, int& min, int& i, int& j){
    if (numbArray [i] [j] > max){
        max = numbArray [i] [j];
    }
    if (numbArray [i] [j] < min){
        min = numbArray [i] [j];
    }
        
}

float findAvg(float& avg, float& total){
    avg = total / 100;
    
    return avg;
}

void printMaxMinAvg(ofstream& outData, int& max, int& min, float& avg, float& total){
    outData << endl;
    outData << "Max: " << max << endl;
    outData << "Min: " << min << endl;
    outData << "Avg: " << findAvg(avg, total) << endl;
}

void findPrintMoreThan100(ofstream& outData, int numbArray[] [10], int& i, int& j){
    outData << "*--<Values greater than 100>--*" << endl;
    j = 0;
    i = 0;
    while (i < 10){
        if (numbArray [i] [j] > 100){
            outData << numbArray [i] [j] << endl;   
        }
        i++;
    }

    
}

void BubbleSort(int numbArray[] [10]){
      int i, j, flag = 1;    // set flag to 1 to start first pass
      int temp;             // holding variable
      int numLength = 10; 
      for(i = 1; (i <= numLength) && flag; i++)
     {
          flag = 0;
          for (j=0; j < (numLength -1); j++)
         {
               if (numbArray[j+1] [0] < numbArray[j] [0])      // ascending order simply changes to <
              { 
                    temp = numbArray[j] [0];             // swap elements
                    numbArray[j] [0] = numbArray[j+1] [0];
                    numbArray[j+1] [0] = temp;
                    flag = 1;               // indicates that a swap occurred.
               }
          }
     }
     return;   //arrays are passed to functions by address; nothing is returned
}

void selSort(int numbArray[] [10], int sortArray[] [10]){
    int j = 10;
    int i = 0;
    while (i < 10){
        j = 10;
        while (j > 0){
            sortArray [i] [j] = numbArray [j] [i];
            j--;
        }
        i++;
    }
}

void printSortData(ofstream& outData, int sortArray[] [10], int& i, int &j){
        i=0;
        j=0;
        while (i < 10){
            outData << endl;
            j = 0;
            while (j < 10){
                outData << setw(4) << left << sortArray [i] [j];
                j++;
            }
            i++;
        }
}