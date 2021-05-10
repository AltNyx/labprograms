#include <iostream>
#include <fstream>

using namespace std;

// Function to reverse a string in place
void reverse(char *name)
{
    int n = strlen(name);
    char ch;

    for (int i = 0; i < n / 2; i++)
    {
        ch = name[i];
        name[i] = name[n - i - 1];
        name[n - 1 - i] = ch;
    }
}

int main()
{
    int n;
    cout << "Enter number of names to be read: ";
    cin >> n;

    char buffer[20]; // buffer to store name
    fstream fp1, fp2;

    fp1.open("names.txt", ios::out); // opening in write mode

    cout << "Enter the names, one per line:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> buffer;
        fp1 << buffer << endl;
    }

    fp1.close();

    fp1.open("names.txt", ios::in);     // Read
    fp2.open("revnames.txt", ios::out); // write

    cout << "The reversed names are:" << endl;
    for (int i = 0; i < n; i++)
    {
        fp1 >> buffer;
        reverse(buffer); // Reverse the name
        fp2 << buffer << endl;
        cout << buffer << endl;
    }

    fp1.close();
    fp2.close();
}