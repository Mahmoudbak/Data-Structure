#include <iostream>
using namespace std;
template <class type>
class stack
{
private:
    struct Node
    {
        type data;
        Node *next;
    };
    Node *temp, *top;

public:
    bool isempty()
    {
        return (top == nullptr);
    }
  /*  void Top()
    {
        if (isempty())
        {
            cout << "The Stack is empty \n";
        }
        else
        {
            cout << top->data;
        }
    }*/
    void push(type x)
    {
        Node *newNode = new Node;
        if (isempty())
        {
            newNode->data = x;
            newNode->next = nullptr;
            top = newNode;
        }
        else
        {
            newNode->data = x;
            newNode->next = top;
            top = newNode;
        }
    }
    void pop()
    {
        if (isempty())
        {
            cout << "The Stack is empty \n";
        }
        else
        {
            temp = top;
            top = top->next;
            type y = temp->data;
            cout << "The elemnt pop is:" << y<<endl;
            delete (temp);
        }
    }
    void traverse()
    {
        temp = top;
        cout << "\nstack is elements: \n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    stack<int> st;
    //st.traverse();
    st.push(2);
    st.push(10);
    st.push(5);
    st.pop();
    st.push(7);
    st.isempty();
   // st.traverse();
}