// filename: cin1.cpp
#include <iostream> // cout, cin
#include <string>
#include <fstream>

using namespace std;  // avoid std::cout

int main()
{
  // declare file
  ifstream inFile;
  inFile.open("in.data");

  // declare varialbes
  string player = "", food = "";
  int age = 0;

  // get user input
  //cout << "Player Name:";
  //cin >> player;
  getline(inFile.player);
  // cout << "Food:";
  //cin >> food;
  getline(inFile.
cout << "Age:";
  cin >> age;

  // print output
  cout << player << (" ") << food << (" ") << age;
  return 0;
}
