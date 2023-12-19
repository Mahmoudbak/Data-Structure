

#include <iostream>
using namespace std;
#define size 10
#define null NULL
class Queuearray
{
private:
    int queue[size];
    int rear, front;
    int element;

public:
    Queuearray()
    {
        rear = -1;
        front = -1;
    }
    bool Isfull()
    {
        return (rear + 1) % size == front;
    }
    bool Isempty()
    {
        return (front == -1 && rear == -1);
    }

    void Enqueue(int x)
    {
        if (Isfull())
        {
            cout << "the queue is full \n";
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            queue[0] = x;
        }
        else
        {
            rear = (rear + 1) % size;
            queue[rear] = x;
        }
    }
    int Dequeue()
    {
        if (rear == front == -1)
        {
            cout << "the queue is empty \n";
        }
        else if (rear == front)
        {
            element = queue[front];
            rear = front = -1;
            return element;
        }
        else
        {
            element = queue[front];
            front = (front + 1) % size;
            return element;
        }
    }
};
//---------------------------------------------------//
//---------------------------------------------------//
template <class type>

class Queuell
{
private:
    struct Node
    {
        type data;
        Node *next;
    };
    Node *head, *front, *rear, *temp;

public:
    Queuell() : front(null), rear(null), temp(null) {}
    bool Isempty()
    {
        return (front == null);
    }
    void Enqueue(type x)
    {
        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = null;
        if (Isempty())
        {
            rear = front = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    type Dequeue()
    {
        if (Isempty())
        {
            cout << "the list is emppty \n";
           
        }
        else if (rear = front)
        {
            temp = front;
            front = rear = null;
            return temp->data;
        }
        else
        {
            temp = front;
            front = front->next;
            return temp->data;
        }
    }
};
int main()
{ /* Queuearray Q;
   Q.Enqueue(2);
   Q.Enqueue(5);
   Q.Enqueue(7);
   cout << Q.Dequeue() << endl;
   Q.Enqueue(3);
   Q.Enqueue(1);
   Q.Enqueue(9);
   Q.Enqueue(10);
   Q.Enqueue(4);
   Q.Enqueue(6);
   cout << Q.Dequeue() << endl;
   Q.Enqueue(2);
   Q.Enqueue(1);
   Q.Isfull();
*/
    Queuell<int> qll;
    qll.Enqueue(2);
    qll.Enqueue(5);
    qll.Enqueue(7);
    cout << qll.Dequeue() << endl;
    qll.Enqueue(3);
    qll.Enqueue(1);
    qll.Enqueue(9);
    qll.Enqueue(10);
    qll.Enqueue(4);
    qll.Enqueue(6);
    cout << qll.Dequeue() << endl;
    qll.Enqueue(2);
    qll.Enqueue(1);
}