#include <iostream>
#include <fstream>

using namespace std;

char *reverse(char *name)
{
    int n = strlen(name);
    char ch;

    for (int i = 0; i < n / 2; i++)
    {
        ch = name[i];
        name[i] = name[n - i - 1];
        name[n - 1 - i] = ch;
    }

    return name;
}

int main()
{
    int n;
    cout << "Enter number of names to be read: ";
    cin >> n;

    char temp[20]; // Buffer to store name

    fstream fp1, fp2;
    fp1.open("names.txt", ios::out); // Opening in write mode

    cout << "Enter the names one per line:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        fp1 << temp << endl;
    }

    fp1.close();
    fp1.open("names.txt", ios::in);          // Read from file1
    fp2.open("reversednames.txt", ios::out); // Write to file2

    cout << "\nThe reversed names are:" << endl;
    for (int i = 0; i < n; i++)
    {
        fp1 >> temp;

        string reversedName = reverse(temp);
        fp2 << reversedName << endl;
        cout << reversedName << endl;
    }

    fp1.close();
    fp2.close();
}