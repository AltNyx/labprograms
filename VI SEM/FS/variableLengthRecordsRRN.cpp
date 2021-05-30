#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Student
{
public:
    char fname[20], lname[20], usn[10], sem[5], branch[5];
};

Student students[20];
Student s;
fstream f;

string filename = "students.txt";

int numRecords = 0;
char buffer[100];
const char *delimeter = "|";

// FUNCTIONS
// Write student record to file
void pack(Student &student)
{
    f.open(filename, ios::out | ios::app);
    const char *RRN = to_string(numRecords).c_str();

    strcpy(buffer, RRN);
    strcat(buffer, delimeter);
    strcat(buffer, student.fname);
    strcat(buffer, delimeter);
    strcat(buffer, student.lname);
    strcat(buffer, delimeter);
    strcat(buffer, student.usn);
    strcat(buffer, delimeter);
    strcat(buffer, student.sem);
    strcat(buffer, delimeter);
    strcat(buffer, student.branch);
    strcat(buffer, delimeter);

    f << buffer << endl; // Write record to file
    f.close();
}

// Read student data and return Student object
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

// Display student data
void display(Student &student)
{
    cout << student.fname << "\t";
    cout << student.lname << "\t";
    cout << student.usn << "\t";
    cout << student.sem << "\t";
    cout << student.branch << endl;
}

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

// Unpack student records from file
void unpack()
{
    f.open(filename, ios::in);
    char RRN[10];

    for (int i = 0; i < numRecords; i++)
    {
        f.getline(buffer, 100);
        sscanf(buffer,
               "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", // Read all 6 fields using RE
               RRN,
               students[i].fname,
               students[i].lname,
               students[i].usn,
               students[i].sem,
               students[i].branch);
    }

    f.close();
}

void search()
{
    f.open(filename, ios::in);
    char searchRRN[10], RRN[10]; // Treat input number as char instead of int. Avoid conversions
    cout << "Enter the RRN value to search: ";
    cin >> searchRRN;

    for (int i = 0; i < numRecords; i++)
    {
        f.getline(buffer, 100);
        sscanf(buffer,
               "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", // Read all 5 fields using RE
               RRN,
               students[i].fname,
               students[i].lname,
               students[i].usn,
               students[i].sem,
               students[i].branch);

        if (strcmp(RRN, searchRRN) == 0)
        {
            cout << "Match Found!" << endl;
            display(students[i]);
            f.close();
            return;
        }
    }

    f.close();
    cout << "Match not found!" << endl;
}

int main()
{
    f.open(filename, ios::out);
    f.close();

    char choice;

    while (1)
    {
        cout << "\n1.Pack\n2.Unpack\n3.Search\n4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            numRecords++;
            read(s);
            pack(s);
            break;
        case '2':
            unpack();
            displayAll();
            break;
        case '3':
            search();
            break;
        case '4':
            return 0;
        default:
            cout << "\nInvalid choice!" << endl;
        }
    }

    return 0;
}