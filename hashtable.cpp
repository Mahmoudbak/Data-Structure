#include <iostream>
using namespace std;
#define size 10
#define null NULL
class HTcollision
{
private:
    int HT[size] = {null};
    int key;

public:
    HTcollision()
    {
        key = -1;
    }
    bool Isfull()
    {
        return (key == size - 1);
    }
    bool Isempty()
    {
        return (key == -1);
    }

    void insert(int x)
    {
        if (Isfull())
        {
            cout << "the list is full \n";
        }
        else
        {
            int i = 1;
            key = (x) % size;
            while (HT[key] != null)
            {
                key = (x + i) % size;
                i++;
            }
            HT[key] = x;
        }
    }
    bool lookup(int x)
    {
        if (Isempty())
        {
            cout << "the list is empty \n";
            return false;
        }
        else
        {
            int i = 0;
            while (HT[key] != NULL)
            {
                key = (x + i) % size;
                if (HT[key])
                    return true;
                i++;
            }
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            int temp;
            temp = HT[i];
            cout << "the index " << i << "-->";
            while (temp)
            {
                cout << temp << "-->";
                temp = temp + 1;
            }
        }
    }
};

template <class type>
class HTchaining
{
private:
    struct Node
    {
        type data;
        Node *next;

        Node HTchaining(type value)
        {
            data = value;
            next = NULL;
        }
    };
    type key ;
    Node *temp;
    Node *HT[size] = {null};

public:

    void insert(type x)
    {

        Node *newNode = new Node();
        key=x%size;
        newNode->data=x;
        newNode->next=null;
        if (HT[key] == null)
        {
            HT[key] = newNode;
        }
        else
        {
            temp = HT[key];
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    type search(type x)
    {   
        key=x%size;
        temp = HT[key];
        while (temp)
        {
            if (temp->data == x)
            {
                return 1;
                temp = temp->next;
            }
            return 0;
        }
    }
    void lookup(type x)
    {
        type y=search(x);
        if(y==1)
        {
            cout<<"the number is found -->"<<x;
            return ;
        }
        else
            cout<<"the number is not fount \n";
    }
    void display()
    {

        for (int i = 0; i < size; i++)
        {
            temp = HT[i];
            cout << "the index" << i << "-->";
            while (temp)
            {
                cout << temp->data << "-->";
                temp = temp->next;
            }
            cout << "NULL \n";
        }
    }
};
int main()
{
    /*HTcollision HT;
    HT.insert(41);
    HT.insert(34);
    HT.insert(11);
    HT.insert(7);
    cout << HT.lookup(11);
    cout << HT.lookup(9);
    HT.display();*/
    HTchaining<int> HTT;
    HTT.insert(107);
    HTT.insert(22);
    HTT.insert(10);
    HTT.insert(12);
    HTT.insert(42);
    HTT.lookup(10);
    HTT.display();
}