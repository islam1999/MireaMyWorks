#include <iostream>

using namespace std;

class Book {
private:
    string _title;
    string _author;
    int _edition;
    int _year;
public:
    Book(string title, string author, int edition, int year):
        _title{title}, _author{author}, _edition{edition}, _year{year} {}
};
