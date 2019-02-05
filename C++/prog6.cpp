//***********************************************************************
//
//   PROGRAM SIX
//   NAME:        Mathew Walker
//   DATE:        11/19/2014
//   CLASS:       CS105
//   PROFESSOR:   Nancy A Samolewski
//   PROGRAM DEF:
//
//   This program will prompt the user for a number between 1 and 20.
//   It will loop until a zero is entered. It will then output the
//   following information:
//
//       The factorial of that number
//       The arithmetic progression of that number
//       Two raised to that number
//       That many Fibonacci numbers
//
//************************************************************************

#include<iostream>
#include<iomanip>

using namespace std;

/////////////////////////////////////////////////////////////////////////
//
//	This function will receive a number and return
//	its factorial.
//
/////////////////////////////////////////////////////////////////////////
long factorial (int number)
{
  long fac = 1;
  int index;
  for (index=1; index <= number; index++)
    fac *= index;
  return fac;
}

/////////////////////////////////////////////////////////////////////////
//
//	This function will receive a number and return
//	the value of its arithmetic progression.
//
/////////////////////////////////////////////////////////////////////////
int ap (int number)
{
  int sum = 0, index;
  for (index = 1; index <= number; index++)
    sum += index;
  return sum;
}

////////////////////////////////////////////////////////////////////////
//
//	This function will receive a number and return
//	two raised to that power.
//
////////////////////////////////////////////////////////////////////////
int two_power (int number)
{
  int twos = 1, index;
  for (index = 1; index <= number; index++)
    twos *=2;
  return twos;
}

////////////////////////////////////////////////////////////////////////
//
//	This function will print out Fibonacci numbers.
//	It will receive an integer as a parameter and
//	print that many numbers.
//
////////////////////////////////////////////////////////////////////////
void fib (int num)
{
  int temp, index, last=0, next=1;
  for (index = 1; index <= num; index ++)
  {
    cout<<"\n\t\t"<<next;
    temp = next;
    next += last;
    last =temp;
  }
  cout<< endl << endl;
}

////////////////////////////////////////////////////////////////////////
//
//	This is the main program.
//
////////////////////////////////////////////////////////////////////////
int main()
{
  int num;

  // Output instructions to the user.  Explain how to quit.
  cout <<"\n\nThis program will let you type a number between 1 and 20.\n\n"
       <<"It will then give you the following information:\n\n"
       <<"\t That number’s factorial\n"
       <<"\t The arithmetic progression of that number\n"
       <<"\t Two raised to that number\n"
       <<"\t That many Fibonacci numbers\n\n";

  do                  // Start a loop.
  {
    do                // Make sure the number is correct.
    {                 // Ask for the number.
      cout<<"\t Please type in number between 1 and 20. (zero to quit):";
                      // Get the number
      cin >> num;
    }
    while (num < 0 || num > 20);

    if (num)
    {
      cout << "\n\n\t The factorial number of " << num <<" is: ";
      cout << factorial(num);
      cout << "\n\t The arithmetic progression of " << num <<" is: ";
      cout << ap(num);
      cout << "\n\t Two to the power of “ << num <<” is: ";
      cout << two_power(num);
      cout << "\n\t The first " << num <<" Fibonacci number(s) are: ";
      fib(num);
      cout << endl;
    }
  }
  while (num);

  return 0;
}

