#include <iostream>
#include <queue>
using namespace std;
    struct Node
    {
        int data;
        Node *left, *right;
      // Node(int k) : key(k), left(nullptr), right(nullptr) {}
        
    };
struct BTS
{
    Node *root;
BTS()
{
    Node *root=nullptr;
}
public:
    Node *insert(Node *root, int item)
    {

        if (root == nullptr)
        {
            Node *newnode = new Node();
            newnode->data=item;
            root = newnode;
        }
        else if (item < root->data)
        {
            root->left = insert(root->left, item);
        }
        else
        {
            root->right = insert(root->right, item);
        }
        return root;
    }
    void insert(int item)
    {
        root=insert(root,item);
    }
   bool search(Node *root, int item)
    {
        if (root == nullptr)
        {
            return false;
        }
        else if (item == root->data)
        {
            return true;
        }
        else if (item < root->data)
        {
            return search(root->left, item);
        }
        else
        {
            return search(root->right, item);
        }
    }
    void printsearch(Node *root, int item)
    {
        bool x = search(root, item);
        if (x == true)
        {
            cout << "\nthe item search is found : " << item << endl;
        }
        else
        {
            cout<<"\nthe item search is not found : "<<item<<endl;
        }
    }
        void printinorder(Node *node)
    {
        if (node == nullptr)
            return;
        else
        {
            printinorder(node->left);
            cout << node->data << " ";
            printinorder(node->right);
        }
    }
     void printpreorder(Node *node)
    {
        if (node == nullptr)
            return;
        else
        {
            cout << node->data << " ";
            printpreorder(node->left);
            printpreorder(node->right);
        }
    }
     void printpostorder(Node *node)
    {
        if (node == nullptr)
            return;
        else
        {
            printpostorder(node->left);
            printpostorder(node->right);
            cout << node->data << " ";
        }
    }
     void levelorder(Node *root)
    {
        if (root == nullptr)
            return;
        else
        {
            queue<Node *> q;
            q.push(root);
            while (q.empty() == false)
            {

                int nodesize = q.size();
                while (nodesize > 0)
                {
                    Node *temp = q.front();
                    cout << temp->data << " ";
                    q.pop();
                    if (temp->left != nullptr)
                        q.push(temp->left);
                    if (temp->right != nullptr)
                        q.push(temp->right);
                    nodesize--;
                }
                cout << endl;
            }
        }
    }
};
int main()
{
    BTS t;
    t.insert(8);
    t.insert(3);
    t.insert(1);
    t.insert(6);
    t.insert(4);
    t.insert(7);
    t.insert(10);
    t.insert(14);
    t.insert(13);
    cout<<"the tree print is inorde is:";
    t.printinorder(t.root);
    cout<<"\n-----------------------------\n";
    cout<<"the tree print is preorde is:";
    t.printpreorder(t.root);
    cout<<"\n------------------------------\n";
    cout<<"the tree print is postorde is:";
    t.printpostorder(t.root);
    t.printsearch(t.root,4);
    t.printsearch(t.root,10);
    t.printsearch(t.root,66);
}
