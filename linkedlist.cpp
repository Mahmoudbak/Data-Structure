#include <iostream>
using namespace std;

class linkedlist
{
private:
	struct Node
	{
		int data;
		Node *next;

		Node(int value)
		{
			data = value;
			next = NULL;
		}
	};
	Node *head, *prev, *temp;

public:
	linkedlist()
	{
		Node *head;
	}
	bool isempty()
	{
		return head == nullptr;
	}
	void insert(int value)
	{
		Node *newnode = new Node(value);
		newnode->data = value;
		newnode->next = NULL;

		if (isempty())
		{
			head = newnode;
		}
		else
		{
			Node *temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
	void traverse()
	{
		if (isempty())
		{
			cout << "the list is empty \n";
		}
		else
		{
			temp=head;
			while (temp !=nullptr )
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}
			cout<<endl;

		}
	}
	void deletevalue(int value)
	{

		if (head->data == value)
		{
			temp = head;
			head = head->next;
			delete temp;
			temp = nullptr;
		}
		temp = head;
		while (temp->next->data != value)
		{
			temp = temp->next;
		}
		prev = temp->next;
		temp->next = prev->next;
		delete prev;
        prev=nullptr;
	}
};
int main()
{
	
	linkedlist list;
	list.insert(9);
	list.insert(96);
	list.insert(8);
	list.insert(44);
	list.insert(26);
	list.insert(4);
	list.traverse();
    int value;
	cout << "plz enter the number need the delet \n";
	cin >> value;
	list.deletevalue(value);
	list.traverse();
}
