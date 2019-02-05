#include <string>
#include "ItemType.h"
using namespace std;

const int MAX_SIZE = 5;

class Queue 
{
  public:
    void MakeEmpty();
    //PURPOSE: To empty the queue
    //INPUT: None
    //PRE: Queue must exist
    //OUTPUT: None
    //POST: Queue will be empty
    //NOTE:

    bool IsEmpty() const;
    //PURPOSE: To check if the queue is empty
    //INPUT: None
    //PRE: Queue must exist
    //OUTPUT: Bool
    //POST: Bool will be returned
    //NOTE:

    bool IsFull() const;
    //PURPOSE: To check if the queue is full
    //INPUT: None
    //PRE: Queue must exist
    //OUTPUT: Bool
    //POST: Bool will be returned
    //NOTE:

    void Enqueue(string name);
    //PURPOSE: Value will be added to the end of the queue
    //INPUT: name
    //PRE: Queue must be initialized and not full
    //OUTPUT: none
    //POST: Value will be added to the end of the queue
    //NOTE:

    void Dequeue(string& name);
    //PURPOSE: First value will be removed from the queue
    //INPUT: name
    //PRE: queue must be initialized and have values
    //OUTPUT: none
    //POST: item will be removed from the queue
    //NOTE:

    Queue();
    //PURPOSE: Class constructor initializes variables
    //INPUT: none
    //PRE: none
    //OUTPUT: none
    //POST: class will be initialized
    //NOTE:

private:
    string data[MAX_SIZE+1];
    int front;
    int rear;
};
