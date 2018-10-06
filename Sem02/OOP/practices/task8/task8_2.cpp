#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream f{"tmp.txt"};

    string line = " ";
    while (line != "") {
        getline(cin, line);
        f << line << endl;
    }

    return 0;
}
