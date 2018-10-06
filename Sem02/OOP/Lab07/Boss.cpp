#include "Boss.h"


Boss::Boss(string surname, string name, string midname, int age, int numw):Human( surname,  name,  midname,  age) {
    number_of_workers = numw;
}

void Boss::print() {
    cout << "\nSurname: " << surname << "\nName: " << name
         << "\nMidname: " << midname << "\nAge: " << age
         << "\nNumber of workers; " << number_of_workers;
}
