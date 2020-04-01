#include <iostream>

using namespace std;

class Row
{
    string symbol;
    string attributes;
    int chain;
    friend class Operations;

public:
    Row()
    {
        symbol = "";
        attributes = "";
        chain = -1;
    }
};

class Operations
{
public:
    bool isFull(Row symTable[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (symTable[i].symbol == "")
            {
                return false;
            }
        }
        return true;
    }

    void insertWithoutReplacement(Row symTable[], int n)
    {
        if (isFull(symTable, n))
        {
            cout << "Symbol Table is full!" << endl;
            return;
        }
        string sym, attr;
        char key;
        cout << "Enter the symbol and attributes ";
        cin >> sym >> attr;
        cout << "Enter the key ";
        cin >> key;
        int pos = ((int)key) - 97;
        int loop = pos;
        int k = pos;
        if (symTable[pos].symbol == "")
        {
            symTable[pos].symbol = sym;
            symTable[pos].attributes = attr;
        }
        else
        {
            if (symTable[pos].symbol[0] != sym[0])
            {
                while (symTable[pos].symbol != "")
                {
                    if (symTable[pos].symbol[0] == sym[0])
                    {
                        k = pos;
                    }
                    pos = (pos + 1) % n;
                }
                if (k == loop)
                {
                    symTable[pos].symbol = sym;
                    symTable[pos].attributes = attr;
                }
                else
                {
                    symTable[pos].symbol = sym;
                    symTable[pos].attributes = attr;
                    symTable[k].chain = pos;
                }
            }
            else
            {
                while (symTable[pos].chain != -1)
                {
                    pos = symTable[pos].chain;
                }
                k = pos;
                while (symTable[pos].symbol != "")
                {
                    pos = (pos + 1) % n;
                }
                symTable[pos].symbol = sym;
                symTable[pos].attributes = attr;
                symTable[k].chain = pos;
            }
        }
    }

    void insertWithReplacement(Row symTable[], int n)
    {
        if (isFull(symTable, n))
        {
            cout << "Symbol Table is full!" << endl;
            return;
        }
        string sym, attr;
        char key;
        cout << "Enter the symbol and attributes ";
        cin >> sym >> attr;
        cout << "Enter the key ";
        cin >> key;
        int pos = ((int)key) - 97;
        int loop = pos;
        int k = pos;
        int chain = -1;
        if (symTable[pos].symbol == "")
        {
            symTable[pos].symbol = sym;
            symTable[pos].attributes = attr;
        }
        else
        {
            if (symTable[pos].symbol[0] != sym[0])
            {
                int i;
                for (i = 0; i < n; i++)
                {
                    if (symTable[i].chain == pos)
                    {
                        break;
                    }
                    if ((symTable[i].symbol[0] == sym[0]) && (symTable[i].chain == -1))
                    {
                        chain = i;
                    }
                }
                k = pos;
                while (symTable[pos].symbol != "")
                {
                    pos = (pos + 1) % n;
                }
                symTable[pos].symbol = symTable[k].symbol;
                symTable[pos].attributes = symTable[k].attributes;
                symTable[pos].chain = symTable[k].chain;
                symTable[k].symbol = sym;
                symTable[k].attributes = attr;
                symTable[k].chain = -1;
                symTable[i].chain = k;
                symTable[chain].chain = k;
            }
            else
            {
                while (symTable[pos].chain != -1)
                {
                    pos = symTable[pos].chain;
                }
                loop = pos;
                while (symTable[pos].symbol != "")
                {
                    pos = (pos + 1) % n;
                }
                symTable[pos].symbol = symTable[k].symbol;
                symTable[pos].attributes = symTable[k].attributes;
                symTable[pos].chain = symTable[k].chain;
                symTable[k].symbol = sym;
                symTable[k].attributes = attr;
                symTable[loop].chain = k;
                if (loop == k)
                {
                    symTable[pos].chain = k;
                    symTable[loop].chain = -1;
                }
            }
        }
    }

    void display(Row symTable[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << symTable[i].symbol << " : " << symTable[i].attributes << "\t" << symTable[i].chain << endl;
        }
    }
};

int main()
{
    int maxSize;
    cout << "Enter the number of symbols ";
    cin >> maxSize;
    Row symTable[maxSize];
    Operations obj;
    cout << "Menu\n1) Insert Symbol without replacement\n2) Insert Symbol with replacement\n3) Find Symbol\n4) Display Symbol Table\n5) Exit" << endl;
    int choice;
    do
    {
        cout << "Enter choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.insertWithoutReplacement(symTable, maxSize);
            break;
        case 2:
            obj.insertWithReplacement(symTable, maxSize);
            break;
        case 3:
            //obj.find(symTable, maxSize);
            break;
        case 4:
            obj.display(symTable, maxSize);
            break;
        case 5:
            break;
        }
    } while (choice != 5);
}