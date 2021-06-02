#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Student
{
public:
    char fname[20], lname[20], usn[10], sem[5], branch[5];
};

// GLOBALS
Student students[20];
Student s;
fstream fp;

int numRecords = 0;
int maxRecordSize = 100;

char buffer[101];
string filename = "std.txt";

// SYMBOLS
const char *delimeter = "|";
const char *padding = "!";

// FUNCTIONS

// Display single student data
void display(Student &student)
{
    cout << student.fname << "\t";
    cout << student.lname << "\t";
    cout << student.usn << "\t";
    cout << student.sem << "\t";
    cout << student.branch << endl;
}

// Display all students data
void displayAll()
{
    if (numRecords == 0)
    {
        cout << "No records found!" << endl;
        return;
    }

    cout << "\nStudent records are:" << endl;
    cout << "Fname\tLname\tUSN\tSem\tBranch" << endl;

    for (int i = 0; i < numRecords; i++)
        display(students[i]);
}

void pack(Student &student)
{
    fp.open(filename, ios::out | ios::app);
    strcpy(buffer, student.fname);
    strcat(buffer, delimeter);
    strcat(buffer, student.lname);
    strcat(buffer, delimeter);
    strcat(buffer, student.usn);
    strcat(buffer, delimeter);
    strcat(buffer, student.sem);
    strcat(buffer, delimeter);
    strcat(buffer, student.branch);
    strcat(buffer, delimeter);

    // Add padding
    int bufferLength = strlen(buffer);
    for (int i = bufferLength; i < 70; i++)
        strcat(buffer, padding);

    fp << buffer << endl;
    fp.close();
}

void read(Student &student)
{
    cout << "Enter the fname: ";
    cin >> student.fname;
    cout << "Enter the lname: ";
    cin >> student.lname;
    cout << "Enter the USN: ";
    cin >> student.usn;
    cout << "Enter the sem: ";
    cin >> student.sem;
    cout << "Enter the branch: ";
    cin >> student.branch;
}

void unpack()
{
    fp.open(filename, ios::in);
    for (int i = 0; i <= numRecords; i++)
    {
        fp.getline(buffer, 100);
        sscanf(buffer,
               "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",
               students[i].fname,
               students[i].lname,
               students[i].usn,
               students[i].sem,
               students[i].branch);
    }
    fp.close();
}

int search()
{
    char usn[20];
    cout << "Enter USN of the record: ";
    cin >> usn;
    for (int i = 0; i < numRecords; i++)
    {
        if (strcmp(students[i].usn, usn) == 0)
        {
            cout << "Record found!" << endl;
            display(students[i]);
            return i;
        }
    }

    cout << "Match not found!" << endl;
    return -1;
}

void modify(int index)
{
    if (index == -1)
        return;

    cout << "Enter the modified values:" << endl;
    read(students[index]);
    const char *name = filename.c_str();
    remove(name); // Remove old file

    for (int i = 0; i < numRecords; i++)
        pack(students[i]);
}

int main()
{
    fp.open(filename, ios::out);
    fp.close();

    int choice;

    while (1)
    {
        cout << "\n1.Pack\n2.Unpack\n3.Search\n4.Modify\n5.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            read(s);
            pack(s);
            numRecords++;
            break;

        case 2:
            unpack();
            displayAll();
            break;

        case 3:
            unpack();
            search();
            break;

        case 4:
            unpack();
            modify(search());
            break;

        case 5:
            return 0;

        default:
            cout << "\nInvalid choice!" << endl;
        }
    }

    return 0;
}