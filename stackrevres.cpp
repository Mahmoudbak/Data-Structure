#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class LinkedListStack
{
private:
    Node *top;

public:
    LinkedListStack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(char val)
    {
        Node *newNode = new Node(val);
        newNode->data = val;
        if (isEmpty())
        {
            newNode->next = NULL;
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }
    char pop()
    {
        if (isEmpty())
        {
            return '\0';
        }
        else
        {
            Node *temp = top;
            top = top->next;
            char y = temp->data;
            delete temp;
            return y;
        }
    }
};
string reverseWord(const string &word)
{
    LinkedListStack letters;
    for (char letter : word)
    {
        letters.push(letter);
    }

    string reversedWord;
    while (!letters.isEmpty())
    {
        reversedWord += letters.pop();
    }

    return reversedWord;
}

bool balanceparentheses(const string &expression)
{
    LinkedListStack parentheses;
    for (char bracket : expression)
    {
        if (bracket == '(' || bracket == '[' || bracket == '{')
        {
            parentheses.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}')
        {
            if (parentheses.isEmpty())
            {
                return false;
            }
            char top = parentheses.pop();
            if ((bracket == ')' && top != '(') ||
                (bracket == ']' && top != '[') ||
                (bracket == '}' && top != '{'))
            {
                return false;
            }
        }
    }
    return parentheses.isEmpty();
}

int main()
{
    string word;
    cout << "plz enter the word need reversed\n";
    getline(cin, word);
    string reversed = reverseWord(word);
    cout << "Reversed word: " << reversed << endl;
    cout << "plz enter the parentheses need chack\n";
    string ex[12];
    for (int i = 0; i <= 4; i++)
    {
        getline(cin, ex[i]);
        bool balance = balanceparentheses(ex[i]);
        if (balance)
        {
            cout << "\"" << *ex << "\" is balanced" << endl;
        }
        else
        {
            cout << "\"" << *ex << "\" is not balanced" << endl;
        }
    }


    return 0;
}
