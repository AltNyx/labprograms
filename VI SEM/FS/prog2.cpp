#include <iostream>
#include <fstream>

using namespace std;

class Student
{
public:
    char fname[20], lname[20], usn[12], sem[5], branch[5];
};

Student t; // temp student object
int count = 0;
fstream fp;
char buffer[100]; // Buffer to hold record
string filename = "student.txt";
Student s[20];

void pack(Student s)
{
    fp.open(filename, ios::out | ios::app);
    strcpy(buffer, s.fname);
    strcat(buffer, "|");
    strcat(buffer, s.lname);
    strcat(buffer, "|");
    strcat(buffer, s.usn);
    strcat(buffer, "|");
    strcat(buffer, s.sem);
    strcat(buffer, "|");
    strcat(buffer, s.branch);
    strcat(buffer, "|");

    int size = strlen(buffer);

    for (int i = 0; i < 70 - size; i++) // Add padding
        strcat(buffer, "*");

    fp << buffer << endl;
    fp.close();
}

void unpack()
{
    fp.open(filename, ios::in);

    for (int i = 0; i < count; i++)
    {
        fp.getline(buffer, 100);
        sscanf(buffer,
               "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|", // Read all 5 fields using RE
               s[i].fname,
               s[i].lname,
               s[i].usn,
               s[i].sem,
               s[i].branch);

        fp.close();
    }
}

void write()
{
    cout << "Enter the fname: ";
    cin >> t.fname;

    cout << "Enter the lname: ";
    cin >> t.lname;

    cout << "Enter the USN: ";
    cin >> t.usn;

    cout << "Enter the sem: ";
    cin >> t.sem;

    cout << "Enter the branch: ";
    cin >> t.branch;

    pack(t);
}

void display()
{
    cout << "\nStudent records are:" << endl;
    cout << "Fname\tLname\tUSN\tSem\tBranch" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << s[i].fname << "\t";
        cout << s[i].lname << "\t";
        cout << s[i].usn << "\t";
        cout << s[i].sem << "\t";
        cout << s[i].branch << endl;
    }
}

int main()
{
    fp.open(filename, ios::out);
    fp.close();

    int choice;

    while (1)
    {
        cout << "1.pack\t2.Unpack\t3.Search\t4.Modify" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            count++;
            write();
            break;
        case 2:
            unpack();
            display();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }

    return 0;
}