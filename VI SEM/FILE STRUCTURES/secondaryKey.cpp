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
fstream fs;

string filename = "students.txt";
string idxfile = "index.txt";
string secondaryFile = "secidx.txt";

int numRecords = 0;
int recordSize = 70;
char buffer[100], buffer2[50], buffer3[50];
const char *delimeter = "|";
const char *padding = "*";

// FUNCTIONS
// Write student record to file
void pack(Student &student)
{
    f.open(filename, ios::out | ios::app);
    const char *RRN = to_string(numRecords).c_str();

    strcpy(buffer, student.usn);
    strcat(buffer, delimeter);
    strcat(buffer, student.fname);
    strcat(buffer, delimeter);
    strcat(buffer, student.lname);
    strcat(buffer, delimeter);
    strcat(buffer, student.sem);
    strcat(buffer, delimeter);
    strcat(buffer, student.branch);
    strcat(buffer, delimeter);

    for (int i = strlen(buffer); i < recordSize; i++)
        strcat(buffer, padding);

    f << buffer << endl; // Write record to file
    f.close();

    // Write usn|rrn to primary file
    fi.open(idxfile, ios::out | ios::app);
    fi << student.usn << delimeter << numRecords << delimeter << endl;
    fi.close();

    // Write name|usn to secondary file
    fs.open(secondaryFile, ios::out | ios::app);
    fs << student.fname << delimeter << student.usn << delimeter << endl;
    fs.close();
}

// Read student data and return Student object
void read(Student &student)
{
    cout << "Enter the USN: ";
    cin >> student.usn;
    cout << "Enter the fname: ";
    cin >> student.fname;
    cout << "Enter the lname: ";
    cin >> student.lname;
    cout << "Enter the sem: ";
    cin >> student.sem;
    cout << "Enter the branch: ";
    cin >> student.branch;
}

// Display student data
void display(Student &student)
{
    cout << student.usn << "\t";
    cout << student.fname << "\t";
    cout << student.lname << "\t";
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
    cout << "USN\tFname\tLname\tSem\tBranch" << endl;

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
               students[i].usn,
               students[i].fname,
               students[i].lname,
               students[i].sem,
               students[i].branch);
    }

    f.close();
}

int search()
{
    char name[10];
    cin >> name;

    char tempname[20], idx[5], keyusn[10], tempusn[10];
    Student student;

    f.open(filename, ios::in);
    fi.open(idxfile, ios::in);
    fs.open(secondaryFile, ios::in);

    for (int i = 0; i < numRecords; i++)
    {
        fs.getline(buffer3, 40);
        sscanf(buffer3, "%[^|]|%[^|]|", tempname, keyusn);
        if (strcmp(name, tempname) != 0)
            continue;

        for (int j = 0; j < numRecords; j++)
        {
            fi.getline(buffer2, 40);
            sscanf(buffer2, "%[^|]|%[^|]|", tempusn, idx);
            if (strcmp(keyusn, tempusn) != 0)
                continue;

            cout << "Match Found!" << endl;
            int seekIdx = atoi(idx);
            int seekPosition = (recordSize + 2) * (seekIdx - 1);
            // recordSize + 2, since 2 chars for cr and lf per line in windows

            f.seekg(seekPosition, ios::beg);
            f.getline(buffer, 100);

            sscanf(buffer,
                   "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", // Read all 5 fields using RE
                   student.usn,
                   student.fname,
                   student.lname,
                   student.sem,
                   student.branch);

            display(student);

            f.close();
            fi.close();
            fs.close();

            return seekIdx;
        }
    }

    f.close();
    fi.close();
    fs.close();
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
    remove(secondaryFile.c_str());

    f.open(filename, ios::out);
    fi.open(idxfile, ios::out);
    fs.open(secondaryFile, ios::out);
    f.close();
    fi.close();
    fs.close();

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
    fs.open(secondaryFile, ios::out);
    f.close();
    fi.close();
    fs.close();

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
            cout << "Enter name to search: ";
            search();
            break;
        case '4':
            cout << "Enter name to delete: ";
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