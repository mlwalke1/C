using namespace std;
#include <iostream>


void syracuseSeq(int);


int main() 
{
	int n = 0;
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~~~~~~~~ SYRACUSE SEQUENCE ~~~~~~~~ " << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	cout << "Enter positive integer: ";
	
	cin >> n;
	
	syracuseSeq(n);
	
	return 0;
}


void syracuseSeq(int n) 
{
  if(n == 1)
  {
	 cout << endl << "Syracuse Sequence Complete." << endl;
	 cout << n << " ";
  }
  else if(n % 2 == 0)
  {
	  syracuseSeq(n/2);
	  cout << n << " ";
  }
  else if (n % 2 != 0)
  {
	  syracuseSeq((n * 3) + 1);
	  cout << n << " ";
  }
	
}