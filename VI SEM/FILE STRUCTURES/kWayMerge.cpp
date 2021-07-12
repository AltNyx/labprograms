#include <iostream>
#include <string.h>
#include <fstream>
#include <list>

using namespace std;

class Record
{
public:
    char usn[20], name[20];
};

void mergeFile(string file1, string file2, string file3)
{
    Record f1Records[20];
    Record f2Records[20];

    fstream f1, f2;
    int n = 0;
    int m = 0;
    f1.open(file1, ios::in);
    f2.open(file2, ios::in);

    while (!f1.eof())
    {
        f1.getline(f1Records[n].name, 20, '|');
        f1.getline(f1Records[n].usn, 20, '\n');
        n++;
    }

    while (!f2.eof())
    {
        f2.getline(f2Records[m].name, 20, '|');
        f2.getline(f2Records[m].usn, 20, '\n');
        m++;
    }

    int i = 0;
    int j = 0;

    fstream f3;
    f3.open(file3, ios::out);

    while (i < n - 1 and j < m - 1)
    {
        if (strcmp(f1Records[i].name, f2Records[j].name) <= 0)
        {
            f3 << f1Records[i].name << "|" << f1Records[i].usn << "\n";
            i++;
        }
        else
        {
            f3 << f2Records[j].name << "|" << f2Records[j].usn << "\n";
            j++;
        }
    }

    while (i < n - 1)
    {
        f3 << f1Records[i].name << "|" << f1Records[i].usn << "\n";
        i++;
    }

    while (j < m - 1)
    {
        f3 << f2Records[j].name << "|" << f2Records[j].usn << "\n";
        j++;
    }

    f1.close();
    f2.close();
    f3.close();
}

void kWayMerge(list<string> filenames)
{
    while (filenames.size() > 1)
    {
        string file1 = filenames.front();
        filenames.pop_front();
        string file2 = filenames.front();
        filenames.pop_front();

        string file3 = file1 + file2;
        mergeFile(file1, file2, file3);
        filenames.push_back(file3);
    }
}

int main()
{
    int K = 4;
    list<string> filenames;
    for (int i = 1; i <= K; i++)
        filenames.push_back(to_string(i));

    kWayMerge(filenames);
    cout << "Merge complete\n";
    return 0;
}