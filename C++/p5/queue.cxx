#include "queue.h"
const int VEC_SIZE = MAX_SIZE + 1;

void Queue::MakeEmpty()
//PURPOSE: To empty the queue
//INPUT: None
//PRE: Queue must exist
//OUTPUT: None
//POST: Queue will be empty
//NOTE:
{
  front = rear = VEC_SIZE - 1;
}

Queue::Queue()
//PURPOSE: Class constructor initializes variables
//INPUT: none
//PRE: none
//OUTPUT: none
//POST: class will be initialized
//NOTE:
{
  front = rear = VEC_SIZE - 1;
}

bool Queue::IsEmpty() const
//PURPOSE: To check if the queue is empty
//INPUT: None
//PRE: Queue must exist
//OUTPUT: Bool
//POST: Bool will be returned
//NOTE:
{
  return (rear == front);
}

bool Queue::IsFull() const
//PURPOSE: To check if the queue is full
//INPUT: None
//PRE: Queue must exist
//OUTPUT: Bool
//POST: Bool will be returned
//NOTE:
{
  return ((rear + 1) % VEC_SIZE == front);
}

void Queue::Enqueue(string name)
//PURPOSE: Value will be added to the end of the queue
//INPUT: name
//PRE: Queue must be initialized and not full
//OUTPUT: none
//POST: Value will be added to the end of the queue
//NOTE:
{
  rear = (rear + 1) % VEC_SIZE;
  data[rear] = name;
}

void Queue::Dequeue(string& name)
//PURPOSE: First value will be removed from the queue
//INPUT: name
//PRE: queue must be initialized and have values
//OUTPUT: none
//POST: item will be removed from the queue
//NOTE:
{
  front = (front + 1) % VEC_SIZE;
  name = data[front];
}
