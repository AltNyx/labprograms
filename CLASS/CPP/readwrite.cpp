#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int a, b;
    fstream f;
    f.open("data1.txt", ios::out);
    cout << "Enter a, b: " << endl;
    cin >> a >> b;
    f << a << endl << b << endl;
    f.close();
    
    int x, y;
    f.open("data1.txt", ios::in);
    f >> x >> y;
    cout << "The value of x and y: " << x << " " << y << endl;
    f.close();
    return 0;
}