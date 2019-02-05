#include "complex.h"

int main(){

ifstream inFile;
ofstream outFile;
inFile.open("in.data");
outFile.open("out.data");

if (inFile.fail() || outFile.fail())
  {
    outFile << "Check your input and output file!" << endl;
    return 1;
  }

outFile << "<* Complex Numbers *>" << endl;
outFile << " " << endl;

complex A;
complex B;
complex C;

inFile >> A;
inFile >> B;

outFile << "A = ";
outFile << A;
outFile << "B = ";
outFile << B;

outFile << " " << endl;
C = A + B;
outFile << "A + B = ";
outFile << C;

outFile << " " << endl;
C = A - B;
outFile << "A - B = ";
outFile << C;

outFile << " " << endl;
C = A * B;
outFile << "A * B = ";
outFile << C;

outFile << " " << endl;
C = A / B;
outFile << "A / B = ";
outFile << C;

outFile << " " << endl;
C = ++A;
outFile << "++A = ";
outFile << C;

outFile << " " << endl;
C = B++;
outFile << "B++ = ";
outFile << C;

return 0;
}
