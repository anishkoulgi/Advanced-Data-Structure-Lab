#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Student
{
    char name[50] = "";
    int rollNo = 0;
    int year = 0;
    int division = 0;
    char address[50] = "";
    friend class FileOperations;

public:
    Student()
    {
    }
    Student(char name[50], int rollNo, int year, int division, char address[50])
    {
        strcpy(this->address, address);
        strcpy(this->name, name);
        this->division = division;
        this->rollNo = rollNo;
        this->year = year;
    }
    int getRollNo()
    {
        return rollNo;
    }
    void displayStudentData()
    {
        cout << endl
             << "\t" << rollNo << "\t" << name << "\t" << year << "\t" << division << "\t" << address;
    }
};
class FileOperations
{
    fstream file;

public:
    FileOperations(char *name)
    {
        this->file.open(name, ios::in | ios::out | ios::ate | ios::binary);
    }
    void insertRecord(int rollNo, char name[50], int year, int division, char address[50])
    {
        Student s = Student(name, rollNo, year, division, address);
        file.seekp(0, ios::end);
        file.write((char *)&s, sizeof(Student));
        file.clear();
    }
    void display()
    {
        Student s;
        file.seekg(0, ios::beg);
        while (file.read((char *)&s, sizeof(Student)))
        {
            s.displayStudentData();
        }
        file.clear();
    }
    void displayRecord(int rollNo)
    {
        Student s;
        file.seekg(0, ios::beg);
        void *p;
        while (file.read((char *)&s, sizeof(Student)))
        {
            if (s.rollNo == rollNo)
            {
                s.displayStudentData();
                break;
            }
        }
        if (p == NULL)
            cout << "Element not present" << endl;
        file.clear();
    }
    void deleteRecord(int rollNo)
    {
        ofstream newFile;
        newFile.open("temp.txt", ios::binary);
        file.seekg(0, ios::beg);
        bool flag = false;
        Student s;
        while (file.read((char *)&s, sizeof(s)))
        {
            if (s.rollNo == rollNo)
            {
                flag = true;
                continue;
            }
            newFile.write((char *)&s, sizeof(s));
        }
        if (!flag)
        {
            cout << "Element Not Present";
        }
        file.close();
        newFile.close();
        remove("student.txt");
        rename("temp.txt", "student.txt");
        file.open("student.txt", ios::in | ios::ate | ios::out | ios::binary);
    }
};
int main()
{
    ofstream newFile("student.txt", ios::app | ios::binary);
    newFile.close();
    FileOperations file((char *)"student.txt");
    int rollNo, year, division, choice = 0;
    char name[50], address[50];
    cout << "\nMenu:\n";
    cout << "1) Add New Record\n";
    cout << "2) Delete a Record\n";
    cout << "3) Display by RollNo\n";
    cout << "4) Display All Records\n";
    cout << "5) Exit\n";
    while (choice != 5)
    {
        cout << "Choose your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1: //New Record
            cout << "Enter Roll number: ";
            cin >> rollNo;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter Year and Division : \n";
            cin >> year >> division;
            cout << "Enter address : \n";
            cin >> address;
            file.insertRecord(rollNo, name, year, division, address);
            break;
        case 2:
            cout << "Enter Roll Number ";
            cin >> rollNo;
            file.deleteRecord(rollNo);
            cout << endl
                 << "Record deleted" << endl;
            break;
        case 3:
            cout << "Enter Roll Number ";
            cin >> rollNo;
            file.displayRecord(rollNo);
            cout << endl;
            break;
        case 4:
            file.display();
            cout << endl;
            break;
        case 5:
            break;
        }
    }
}
