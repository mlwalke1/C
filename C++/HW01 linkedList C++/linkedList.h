using namespace std;
#include <iostream>

struct nodeType 
{
	int info;
	nodeType *next;
};

class linkedList
{
	public:
		linkedList();
		void addToHead(int);
		void printList();
		void deleteTail();
		bool isEmpty();
		
	private:
		nodeType * head;
		nodeType * tail;
		int nodeCount;

};