
#include <fstream>
using namespace std;

class complex{

public:
  friend istream& operator>>(ifstream &inFile, complex& A);
  friend ostream& operator<<(ofstream &outFile, complex& A);
  complex operator+ (const complex& B);
  complex operator- (const complex& B);
  complex operator* (const complex& B);
  complex operator/ (const complex& B);
  complex operator++ ();
  complex operator++ (int);
  float geta();
  float getb();

private:
  float a;
  float b;

};
