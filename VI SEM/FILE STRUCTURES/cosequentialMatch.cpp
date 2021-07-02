#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

string firstFile = "FirstFile.txt";
string secondFile = "SecondFile.txt";
string outputFile = "OutputFile.txt";

void readNames(string filename) {
    fstream fp;
    fp.open(filename, ios::out);

    int numNames;
    cout << "Enter number of names to enter in file " << filename << ": ";
    cin >> numNames;

    char name[20];
    cout << "Enter the names in ascending order: " << endl;
    for (int i = 0; i < numNames; i++) {
        cin >> name;
        fp << name << endl;
    }

    fp.close();
}

int getNames(string filename, char list[][20]) {
    int idx = 0;
    fstream fp;
    fp.open(filename, ios::in);

    while (!fp.eof()) {
        fp.getline(list[idx], 20);
        idx++;
    }
    fp.close();
    return idx-1;
}

int main() {
    readNames(firstFile);
    readNames(secondFile);

    char firstList[100][20];
    char secondList[100][20];

    int n = getNames(firstFile, firstList);
    int m = getNames(secondFile, secondList);

    fstream fp;
    fp.open(outputFile, ios::out);

    int i = 0;
    int j = 0;

    cout << "Names common to both files are: " << endl;
    while (i < n && j < m) {
        int cmp = strcmp(firstList[i], secondList[j]);
        if (cmp == 0) {
          fp << firstList[i] << endl;
          cout << firstList[i] << endl;
          i++; j++;
        } else if (cmp < 0) {
          i++;
        } else {
          j++;
        }
    }
    fp.close();
    return 0;
}