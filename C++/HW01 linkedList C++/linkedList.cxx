#include "linkedList.h"

linkedList::linkedList()
{
	head = NULL;
	tail = NULL;
	nodeCount = 0;
}


void linkedList::addToHead(int info)
{
	nodeType * node = new nodeType;
	node->info = info;
	
	if(head == NULL)
	{
		head = node;
		tail = node;
	}
	else
	{
		node->next = head;
		head = node;
	}
	
	nodeCount++;
	
}

void linkedList::printList()
{
	nodeType * temp = NULL;
	if(head == NULL)
	{
		cout << "~NO DATA TO PRINT~\n" << endl;
	}
	else 
	{
		cout << "---- DATA LIST ----" << endl;
		temp = head;
		while(temp != NULL)
		{
			cout << "Data: " << temp->info << endl;
			temp = temp->next;
		}
		cout << endl;
	}
}

void linkedList::deleteTail()
{
	nodeType * temp = NULL;
	temp = head;
	if(tail == head)
	{
		delete head;
		nodeCount--;
		head = NULL;
		tail = NULL;
	}
	else 
	{
		for(int i = 0; i < nodeCount - 2; i++)
		{
			temp = temp->next;
		}
		delete tail;
		tail = temp;
		tail->next = NULL;
		nodeCount--;
	}
}

bool linkedList::isEmpty()
{
	if (nodeCount == 0) 
	{
		return true;
	}
	else
	{
		return false;
	}
}


