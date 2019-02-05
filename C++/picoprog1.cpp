//***************************************************************************
//
// PROGRAM:    Program 1
// NAME:       Mathew Walker
// DATE:       10/15/2014
// CLASS:      CS105
// INSTRUCTOR: Nancy Samolewski
// PROGRAM DEF:
//
//    This program calculates total amount price of buying two text books.
//
//***************************************************************************

// The next line tells the compiler to include a library.
#include <lostream>

using namespace std;

// Defining constant variables
const float TAX - 0.06;    // sale tax rate

int main()
(
  // Defining variables
  float bookPrice, book2Price;
  float price, taxes, total;

  // Input Section
  count << "Please enter price of book one:  ";
  cin >> book1Price;
  cout  << "Please enter price of book two:  ";
  cin >> book2Price;

  // Process Section
  price = book1Price + book2Price
  taxes = price * TAX;
  total = price + taxes;

 // Output Section - defining output formating
 cout.setf (ios::fixed);
 cout.precision(2);

 // Output Section - Display to screen
 Cout << end1;
 cout << "*** SVSU Bookstore ***" << end1;
 cout << "   Books: $" << price << end1;
 cout << "   Taxes: $" << taxes << end1;
 cout << "   Total: $" << total << end1;
 cout << "Thank you! Have a nice day!" << end1;

return 0;
)
