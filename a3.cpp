#include <iostream>

using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;
    int lflag;
    int rflag;
    friend class Tree;

public:
    Node()
    {
        left = NULL;
        right = NULL;
        lflag = 0;
        rflag = 0;
    }
};

class Tree
{
    Node *root;
    Node *dummy;

public:
    Tree()
    {
        root = new Node();
        root = NULL;
    }
    void addNode()
    {
        int num;
        cout << "Enter the data";
        cin >> num;
        Node *p = new Node();
        p->data = num;
        if (root == NULL)
        {
            root = p;
            dummy = new Node();
            root = p;
            dummy->left = dummy->right = root;
            root->left = root->right = dummy;
            root->lflag = root->rflag = 1;
        }
        else
        {
            Node *temp = new Node();
            temp = root;
            int flag = 0;
            while (!flag)
            {
                if (p->data < temp->data)
                {
                    if (temp->lflag == 1)
                    {
                        p->left = temp->left;
                        temp->left = p;
                        p->right = temp;
                        p->lflag = 1;
                        p->rflag = 1;
                        temp->lflag = 0;
                        flag = 1;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->rflag == 1)
                    {
                        p->right = temp->right;
                        temp->right = p;
                        p->left = temp;
                        p->lflag = 1;
                        p->rflag = 1;
                        temp->rflag = 0;
                        flag = 1;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
    void inOrder()
    {
        Node *temp = root;
        while (temp->lflag != 1)
        {
            temp = temp->left;
        }
        while (temp != dummy)
        {
            cout << temp->data << " ";
            if (temp->rflag == 1)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->right;
                while (temp->lflag != 1)
                {
                    temp = temp->left;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    Tree obj;
    obj.addNode();
    obj.addNode();
    obj.addNode();
    obj.addNode();
    obj.addNode();
    obj.addNode();
    obj.addNode();
    obj.inOrder();

    return 0;
}