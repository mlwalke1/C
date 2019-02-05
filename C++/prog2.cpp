//*********************************************************************
//
// PROGRAM:     Program 2
// NAME:        Your Name
// DATE:        Today's Date
// CLASS:       cs105
// INSTRUCTOR:  Nancy Samolewski
// PROGRAM DEF:
//
//    This program reads two integer numbers from input file and 
//    calculates minimum, maximum, abd average of two numbers.
//
//*********************************************************************

// The next line tells the compiler to unclude a file.
#include <iostream>

using namespace std;

int main ()
{

  // Defining variables
  int num1, num2, min, max;
  float avg;

  // Input Section
  cout << endl << "Program 2 - Min Max Avg" << endl;
  cout << "Please enter first number: ";
  cin >> num1;
  cout << "Please enter second number: ";
  cin >> num2;
  
  // Process Section
  if (num1 > num2)
  {
    max = num1;
    min = num2;
  }
  else
  {
    max = num2;
    min = num1;
  }

  avg = float (num1 + num2)/2;

  // Output Section - defining output formatting
  cout.setf(ios::fixed);
  cout.precision(2);

  // Output Section
  cout << endl << "*** MAX, MIN, AVG of Two Numbers ***";
  cout << endl << endl;
  cout << "Number1: " << num1 << endl;
  cout << "Number2: " << num2 << endl;
  cout << endl;
  cout << "Minimum: " << min << endl;
  cout << "Maximum: " << max << endl;
  cout << "Average: " << avg << endl;
  cout << endl;
  cout << "*> end <*" << endl;

return 0;
}
