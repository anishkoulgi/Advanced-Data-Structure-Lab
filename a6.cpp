#include <iostream>

using namespace std;

class Node
{
    string word;
    string meaning;
    friend class Operations;

public:
    Node()
    {
        word = "";
        meaning = "";
    }
};

class Operations
{
public:
    bool isFull(Node hashTable[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (hashTable[i].word == "")
            {
                return false;
            }
        }
        return true;
    }
    void insertWithoutReplacement(Node hashTable[], int n)
    {
        if (isFull(hashTable, n))
        {
            cout << "Dictionary is full!" << endl;
            return;
        }
        char key;
        string wor, mean;
        cout << "Enter the word and meaning ";
        cin >> wor;
        cin >> mean;
        cout << "Enter the key ";
        cin >> key;
        int pos = ((int)key) - 97;
        if (hashTable[pos].word != "")
        {
            while (hashTable[pos].word != "")
            {
                pos++;
                pos = pos % n;
            }
        }
        hashTable[pos].word = wor;
        hashTable[pos].meaning = mean;
    }
    void insertWithReplacement(Node hashTable[], int n)
    {
        if (isFull(hashTable, n))
        {
            cout << "Dictionary is full!" << endl;
            return;
        }
        char key;
        string wor, mean;
        cout << "Enter the word and meaning ";
        cin >> wor;
        cin >> mean;
        cout << "Enter the key ";
        cin >> key;
        int pos = ((int)key) - 97;
        if (hashTable[pos].word != "")
        {
            swap(hashTable[pos].word, wor);
            swap(hashTable[pos].meaning, mean);
            while (hashTable[pos].word != "")
            {
                pos++;
                pos = pos % n;
            }
        }
        hashTable[pos].word = wor;
        hashTable[pos].meaning = mean;
    }
    void display(Node hashTable[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << hashTable[i].word << " : " << hashTable[i].meaning << endl;
        }
    }
    void find(Node hashTable[], int n)
    {
        string wor;
        cout << "Enter the word to be searched ";
        cin >> wor;
        int pos = ((int)wor[0]) - 97;
        if (hashTable[pos].word != wor)
        {
            int loop = pos;
            pos++;
            while (hashTable[pos].word != wor && pos != loop)
            {
                pos++;
                pos = pos % n;
            }
            if (pos == loop)
            {
                cout << "Word not present in the Dictionary" << endl;
            }
            else
            {
                cout << hashTable[pos].word << " found at position " << pos << endl;
            }
        }
        else
        {
            cout << hashTable[pos].word << " found at position " << pos << endl;
        }
    }
};

int main()
{
    int maxSize;
    cout << "Enter the number of words ";
    cin >> maxSize;
    Node hashTable[maxSize];
    Operations obj;
    cout << "Menu\n1) Insert Word without replacement\n2) Insert Word with replacement\n3) Find Word\n4) Display Dictionary\n5) Exit" << endl;
    int choice;
    do
    {
        cout << "Enter choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.insertWithoutReplacement(hashTable, maxSize);
            break;
        case 2:
            obj.insertWithReplacement(hashTable, maxSize);
            break;
        case 3:
            obj.find(hashTable, maxSize);
            break;
        case 4:
            obj.display(hashTable, maxSize);
            break;
        case 5:
            break;
        }
    } while (choice != 5);
    return 0;
}