#include <iostream>

using namespace std;

class Graph
{
    int graph[10][10];
    friend class Operations;

public:
    Graph()
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                graph[i][j] = 999;
            }
        }
    }
};

class Operations
{
    int citiesCount;
    string cities[10];
    Graph obj;

public:
    void createGraph()
    {
        cout << "Enter the number of cities ";
        cin >> citiesCount;
        cout << "Enter the cities ";
        for (int i = 0; i < citiesCount; i++)
        {
            cin >> cities[i];
        }
    }
    void insertEdge()
    {
        string c1, c2;
        int p, q, dist;
        cout << "Enter the cities ";
        cin >> c1 >> c2;
        cout << "Enter the distance ";
        cin >> dist;
        for (int i = 0; i < 10; i++)
        {
            if (cities[i] == c1)
            {
                p = i;
            }
            if (cities[i] == c2)
            {
                q = i;
            }
        }
        obj.graph[p][q] = obj.graph[q][p] = dist;
    }

    void displayGraph()
    {
        for (int i = 0; i < citiesCount; i++)
        {
            for (int j = 0; j < citiesCount; j++)
            {
                cout << obj.graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void prims()
    {
        bool visited[citiesCount];
        int mst[citiesCount];
        int keys[citiesCount];
        int count = 0, selected, sum = 0;
        for (int i = 0; i < citiesCount; i++)
        {
            visited[i] = false;
            keys[i] = 999;
        }
        keys[0] = 0;
        while (count < citiesCount)
        {
            int min = 999;
            for (int j = 0; j < citiesCount; j++)
            {
                if (min > keys[j] && !visited[j])
                {
                    min = keys[j];
                    selected = j;
                }
            }
            visited[selected] = true;
            sum += keys[selected];
            count++;
            for (int i = 0; i < citiesCount; i++)
            {
                if (obj.graph[selected][i] != 999 && obj.graph[selected][i] < keys[i] && !visited[i])
                {
                    keys[i] = obj.graph[selected][i];
                }
            }
        }
        cout << "Minimum cost is " << sum << endl;
    }
};

int main()
{
    Operations obj;
    cout << "Menu:\n1) Create Graph\n2) Connect cities\n3) Find minimum cost\n4) Display Graph\n5) Exit" << endl;
    int choice;
    do
    {
        cout << "Enter the choice ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.createGraph();
            break;
        case 2:
            obj.insertEdge();
            break;
        case 3:
            obj.prims();
            break;
        case 4:
            obj.displayGraph();
            break;
        case 5:
            break;
        default:
            break;
        }
    } while (choice != 5);

    return 0;
}