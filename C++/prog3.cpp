//***********************************************************************
//
//   PROGRAM THREE
//   NAME:        Mathew Walker
//   DATE:        10/29/2014
//   CLASS:       CS105
//   PROFESSOR:   Nancy A Samolewski
//   PROGRAM DEF:
//
//       This program will output the numbers between one and ten (count
//       to ten). It will count to twenty by two, then count to one
//       hundred by ten.  Last it will print a table of all three of
//       the above.
//
//************************************************************************

//The next few lines tells the compiler to include files.
#include <iostream>
#include <string>
using namespace std;

int main()
{
int counter;
string username;
	
// This code will allow the user to enter their name.
   cout << "Please enter your name: ";
   cin >> username;
   cout << "\n\n\t Counting Program For " << username;

// This code will count to ten.
   cout << "\n\n\n\t Count to ten by one.\n";
   for (counter=1; counter <=10; counter ++)
      cout << "\t\t" << counter << "\n";

// This code will count to twenty by two.
   cout << "\n\n\n\t Count to twenty by two.\n";
   for (counter=2; counter<=20; counter+=2)
      cout << "\t\t" << counter << "\n";

// This code will count to one hundred by ten.
   cout << "\n\n\n\t Count to one hundred by ten.\n";
   for (counter=10; counter <= 100; counter += 10)
      cout << "\t\t" << counter << "\n";

// This code will create a table of all the above.
   cout << "\n\n\n\t\t Create a Table.\n\n"
        << "\t\tOnes\tTwos\tTens\n";
   for (counter=1; counter<=10; counter ++)
      cout << "\t\t" << counter << "\t" << counter*2
           << "\t" << counter*10 << "\n";

// This code will display a message when the program is done.
   cout << "\n\n\t\t All Done!\n\n";

return 0;
}
