#include "complex.h"

istream& operator>>(ifstream& inFile, complex& A)
{
  inFile >> A.a >> A.b;
}

ostream& operator<<(ofstream& outFile, complex& A)
{
  outFile << "("  << A.a << ")" << " + " <<"("  <<A.b << ") i" << endl;
}

complex complex::operator+(const complex& B)
{
         complex temp;
         temp.a = this->a + B.a;
         temp.b = this->b + B.b;
         return temp;
}

complex complex::operator-(const complex& B)
{
         complex temp;
         temp.a = this->a - B.a;
         temp.b = this->b - B.b;
         return temp;
}

complex complex::operator*(const complex& B)
{
         complex temp;
         temp.a = this->a * B.a;
         temp.b = this->b * B.b;
         return temp;
}

complex complex::operator/(const complex& B)
{
         complex temp;
         temp.a = this->a / B.a;
         temp.b = this->b / B.b;
         return temp;
}

complex complex::operator++(int)
{
  complex temp = *this;
  a++;
  b++;
  return temp;
}

complex complex::operator++()
{
  ++a;
  ++b;
  return *this;
}

float complex::geta()
{
  return a;
}

float complex::getb()
{
  return b;
}
