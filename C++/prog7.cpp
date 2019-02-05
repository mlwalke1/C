//***********************************************************************
//
//   PROGRAM SEVEN
//   NAME:        Mathew Walker
//   DATE:        11/24/2014
//   CLASS:       CS105
//   PROFESSOR:   Nancy A Samolewski
//   PROGRAM DEF:
//
//   This program will output a multiplication table from 1 to 9.
//
//************************************************************************

// The next line tell the compiler to include a library.
#include<iostream>

// This line will define the word MAX as nine.
#define MAX 9

using namespace std;

main()

{
   int row; 
   int col;

   // Some people may want to write this program using an array.
   // This declares an integer array called ‘table’ nine by nine.

   int table [MAX][MAX];

   // This will place the values into the array.  Arrays begin indexing at
   // zero and goes to MAX.

   for (row = 0; row <MAX; row ++)
      for (col =  0; col < MAX; col ++)
         table [row][col] = (row + 1) * (col + 1);

   // Output the header for the table.
   cout << "\n\n\t This is a Multiplication Table: (Using the Array)\n\n";

   // This code will output the contents of the array in a table.
   for (row = 0; row < MAX; row ++)
      {
      for (col = 0; col < MAX; col ++)
         cout <<table [row][col] << "\t";
      cout <<"\n";
      }

  // This code will do the same thing without using the array.
   // Output the header for the table.
   cout<<"\n\n\t This is a Multiplication Table: (Without the Array)";
   cout<<"\n\n";

   // This code will build a table without using an array.
   for (row = 1; row < MAX+1; row ++)
      {
      for (col = 1; col < MAX + 1; col ++)
         cout << row * col << "\t";
      cout << "\n";
      }

   // This code will print end of report.
   cout << "\n\n\t\t\t End of Report\n\n";

  return 0;
}

