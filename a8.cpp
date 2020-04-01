#include <iostream>

using namespace std;

class Node
{
public:
    string data;
    int ht;
    Node *left;
    Node *right;
    friend class AVL;
};

class AVL
{
    Node *root;

public:
    AVL()
    {
        root = new Node();
        root = NULL;
    }
    Node *insert(Node *t, string x)
    {
        if (t == NULL)
        {
            Node *temp = new Node();
            temp->data = x;
            temp->left = NULL;
            temp->right = NULL;
            t = temp;
        }
        else
        {
            if (x > t->data)
            {
                t->right = insert(t->right, x);
                if (balanceFactor(t) == -2)
                {
                    if (x > t->right->data)
                    {
                        t = RR(t);
                    }
                    else
                    {
                        t = RL(t);
                    }
                }
            }
            else
            {
                t->left = insert(t->left, x);
                if (balanceFactor(t) == 2)
                {
                    if (x > t->left->data)
                    {
                        t = LR(t);
                    }
                    else
                    {
                        t = LL(t);
                    }
                }
            }
        }
        t->ht = height(t);
        return t;
    }
    void ascending(Node *t)
    {
        if (t != NULL)
        {
            ascending(t->left);
            cout << t->data << " ";
            ascending(t->right);
        }
    }

    void descending(Node *t)
    {
        if (t != NULL)
        {
            descending(t->right);
            cout << t->data << " ";
            descending(t->left);
        }
    }

    int height(Node *t)
    {
        if (t == NULL)
        {
            return 0;
        }
        int heightl = height(t->left);
        int heightr = height(t->right);
        if (heightl > heightr)
            return heightl + 1;
        else
            return heightr + 1;
    }

    int balanceFactor(Node *t)
    {
        if (t == NULL)
        {
            return 0;
        }
        int lh = height(t->left);
        int rh = height(t->right);
        return (lh - rh);
    }

    Node *leftRotate(Node *p)
    {
        Node *q;
        q = p->right;
        p->right = q->left;
        q->left = p;
        p->ht = height(p);
        q->ht = height(q);
        return q;
    }

    Node *rightRotate(Node *p)
    {
        Node *q;
        q = p->left;
        p->left = q->right;
        q->right = p;
        p->ht = height(p);
        q->ht = height(q);
        return q;
    }

    Node *RR(Node *t)
    {
        t = leftRotate(t);
        return t;
    }

    Node *LL(Node *t)
    {
        t = rightRotate(t);
        return t;
    }

    Node *LR(Node *t)
    {
        t->left = leftRotate(t->left);
        t = rightRotate(t);
        return t;
    }

    Node *RL(Node *t)
    {
        t->right = rightRotate(t->right);
        t = leftRotate(t);
        return t;
    }

    void showHeight(Node *head)
    {
        cout << "Height is " << height(head) << endl;
    }

    void find(Node *root)
    {
        string word;
        cout << "Enter the word to be searched ";
        cin >> word;
        int comparisons = 1;
        while (1)
        {
            if (root == NULL)
            {
                cout << "Word not found" << endl;
                return;
            }
            if (word == root->data)
            {
                cout << word << " found in " << comparisons << " comparisons" << endl;
                return;
            }
            if (word < root->data)
                root = root->left;
            else
                root = root->right;
            comparisons++;
        }
    }
};

int main()
{
    AVL obj;
    Node *root = new Node();
    root = NULL;
    int choice;
    cout << "Menu:\n1) Add word\n2) Ascending Order\n3) Descending Order\n4) Print root and it's BF\n5) Find word\n6) Exit\n";
    do
    {
        cout << "Enter choice ";
        cin >> choice;
        string data;
        switch (choice)
        {
        case 1:
            cout << "Enter the word ";
            cin >> data;
            root = obj.insert(root, data);
            break;
        case 2:
            obj.ascending(root);
            cout << endl;
            break;
        case 3:
            obj.descending(root);
            cout << endl;
            break;
        case 4:
            cout << "Root is " << root->data << " and it's BF is " << obj.balanceFactor(root) << endl;
            break;
        case 5:
            obj.find(root);
            break;
        case 6:
            break;
        }
    } while (choice != 6);
    return 0;
}