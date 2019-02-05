#include "linkedList.h"
using namespace std;

int main() 
{
	linkedList list1;
	int command;
	
	while (true) 
	{
		cout << "----- MENU -----" << endl;
		cout << "Enter 1 to INSERT to the front of the list" << endl << "enter 2 to DELETE from the end of the list" << endl
				<< "Enter 3 to PRINT the list" << endl << "Enter 4 to EXIT\n" << endl << "Your Choice: ";
		cin >> command;
		cout <<  endl;
		if(command == 4)
		{
			break;
		}
		else if ( command == 1)
		{
			int info = 0;
			cout << "Enter a value to INSERT into the list: ";
			cin >> info;
			cout <<  endl;
			list1.addToHead(info);
		}
		else if(command == 3)
		{
			list1.printList();
		}
		else if(command == 2)
		{
			if(list1.isEmpty())
			{
				cout << "List is Empty! Cannot DELETE!\n" << endl;
			}
			else
			{
				list1.deleteTail();
				cout << "Tail DELETED!\n" << endl;
			}
		}
		else
		{
			cout << "Please enter a 1, 2, 3, or 4!\n" << endl << endl;
		}
	}
	
	return 0;
}






