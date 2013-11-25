#include <iostream>
using namespace std;


class Queue
{
private:
	struct Node {int item; struct node * next;};
	enum {SIZE = 10};
	Node * front;
	Node * rear;
	int items;
	const int qSize;

public:
	Queue(int qs);
	~Queue();
	
	bool IsEmpty();
	bool IsFull();
	int QueueCount();
	bool Enqueue(const int &added);
	bool Dequeue(const int &removed);

	void PrintQueue();

};

Queue::Queue(int qs) : qSize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{

}

bool Queue::IsEmpty()
{
	return items == 0;
}

bool Queue::IsFull()
{
	return items == qSize;
}

bool Queue::Enqueue(const int &item)
{
	if(IsFull())
		return false;
	Node * add = new Node; //create node
	add->item = item; // set node pointers
	add->next = NULL;
	items++; //increment item counter
	if( front == NULL ) //if queue is empty...
		front = add; //place item at front
	else
		rear->next = add; //otherwise place it at the rear
	rear = add; // and have rear point to new node
	return true;
}

bool Queue::Dequeue(const int &item)
{
	if(front == NULL)
		return false;
	item = front->item; //set item to the first item in the queue
	items--; //decrement item counter
	Node * temp = front; //save location of first item
	front = front->next; //reset front to next item;
	delete temp;
	if(items == 0)
		rear = NULL;
	return true;
}

void Queue::PrintQueue()
{
	for(int i = 0; i < qSize; i++)
		cout << front->item;
}

int main()
{
	
	int qSize = 10;
	Queue line(qSize);

	line.Enqueue(8);
	line.Enqueue(17);
	line.Enqueue(21);

	line.PrintQueue();

	cin.get();
	cin.get();




	return 0;
}