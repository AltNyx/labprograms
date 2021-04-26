#include<iostream>
using namespace std;

class Student {
    private: char usn[20];
             char name[20];
    
    public: void readData() {
                cout << "Enter the value for USN and NAME: " << endl;
                cin >> usn >> name;
            }

            void display() {
                cout << "The name and usn of the student is: " << name << " " << usn;
            }
};

int main() {
    Student s;
    s.readData();
    s.display();
    return 0;
}