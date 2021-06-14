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
fstream fi;

string filename = "students.txt";
string idxfile = "index.txt";

int numRecords = 0;
int recordSize = 70;
char buffer[100];
const char *delimeter = "|";
const char *padding = "*";

// FUNCTIONS
// Write student record to file
void pack(Student &student)
{
    f.open(filename, ios::out | ios::app);
    const char *RRN = to_string(numRecords).c_str();

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

    for (int i = strlen(buffer); i < recordSize; i++)
        strcat(buffer, padding);

    f << buffer << endl; // Write record to file
    f.close();

    fi.open(idxfile, ios::out | ios::app);
    fi << student.usn << delimeter << numRecords << delimeter << endl;
    fi.close();
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

    for (int i = 0; i < numRecords; i++)
    {
        f.getline(buffer, 100);
        sscanf(buffer,
               "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", // Read all 5 fields using RE
               students[i].fname,
               students[i].lname,
               students[i].usn,
               students[i].sem,
               students[i].branch);
    }

    f.close();
}

int search()
{
    char usn[10];
    cin >> usn;

    char tempusn[10], idx[5];
    fi.open(idxfile, ios::in);
    Student student;

    for (int i = 0; i < numRecords; i++)
    {
        fi.getline(buffer, 30);
        sscanf(buffer, "%[^|]|%[^|]|", tempusn, idx);
        if (strcmp(usn, tempusn) == 0)
        {

            int seekIdx = atoi(idx); // Ascii to int
            int seekPosition = recordSize * (seekIdx - 1);
            seekPosition += (seekIdx - 1) * 2; // This is needed to account for crlf in windows

            // Seek to the right position
            f.open(filename, ios::in);
            f.seekg(seekPosition, ios::beg);
            f.read(buffer, recordSize);

            sscanf(buffer,
                   "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", // Read all 5 fields using RE
                   student.fname,
                   student.lname,
                   student.usn,
                   student.sem,
                   student.branch);

            cout << "Match Found!" << endl;
            display(student);

            f.close();
            fi.close();

            return seekIdx;
        }
    }

    f.close();
    fi.close();
    cout << "Match not found!" << endl;
    return -1;
}

void deleteRecord(int index)
{
    if (index == -1)
        return;

    unpack();
    remove(filename.c_str());
    remove(idxfile.c_str());

    f.open(filename, ios::out);
    fi.open(idxfile, ios::out);
    f.close();
    fi.close();

    int oldCount = numRecords;
    numRecords = 0;

    for (int i = 0; i < oldCount; i++)
    {
        if (i + 1 != index)
        {
            numRecords++;
            pack(students[i]);
        }
    }

    cout << "Record has been deleted!" << endl;
}

int main()
{
    f.open(filename, ios::out);
    fi.open(idxfile, ios::out);
    f.close();
    fi.close();

    char choice;

    while (1)
    {
        cout << "\n1.Pack\n2.Unpack\n3.Search\n4.Delete\n5.Exit" << endl;
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
            cout << "Enter USN to search: ";
            search();
            break;
        case '4':
            cout << "Enter USN to delete: ";
            deleteRecord(search());
            break;
        case '5':
            return 0;
        default:
            cout << "\nInvalid choice!" << endl;
        }
    }

    return 0;
}