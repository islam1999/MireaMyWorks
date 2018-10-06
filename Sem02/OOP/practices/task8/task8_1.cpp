#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << "usage: program filename" << endl;
        return 1;
    }

    ifstream f{argv[1]};
    if (!f) {
        cout << "error" << endl;
        return 1;
    }

    string word;
    while (f >> word) {
        cout << word << endl;
    }

    return 0;
}
