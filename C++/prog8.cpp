/*

	PROGRAM EIGHT
	NAME:		Mathew Walker
	DATE:		12/8/2014
	CLASS:	CS105
	PROFESSOR:	Nancy A Samolewski
	PROGRAM DEF:

This program will allow a user to guess a number from 1 to 10.
The user will be allowed to guess three times.  After each guess,
a clue will be displayed as too high, too low, or correct answer.

*/

// The next line tells the compiler to include the following files.
#include <iostream>
#include<stdlib.h>   ‘<cstdlib>
using namespace std;

main()
{
   int compnum, numofguess, myguess;
			
// To set up the random computer number to guess.
   srand(time(NULL));
   compnum = rand() % 10 + 1;
	
// To display the welcome message to screen.
   cout <<"\n\nWelcome to read my mind.";
   cout <<"\nI’m thinking of a number from 1 to 10.\n";

// To set the number of guess initially to 0
   numofguess = 0;

   while (numofguess < 3)
   {
      cout <<"\nWhat is your guess? ";
      cin >> myguess;

      if (myguess == compnum)
         {
         cout <<"You are right!\n";
         numofguess = 3;
         }
      else
         if (myguess > compnum)
            cout <<"You are too high.\n";
         else
            cout <<"You are too low.\n";
   numofguess = numofguess + 1;
   if (numofguess == 3)
      cout <<"\nYou didn’t guess it - - it was " << compnum <<"\n";
   }
cout <<"\n\nAll finished! – Please play again.\n\n";

return 0;
}

