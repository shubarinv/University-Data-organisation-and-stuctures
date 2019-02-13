//
// Created by vhundef on 13.02.19.
//

#include <string>
#include <iostream>

using namespace std;
/*
 * Поля данных:
 * Название, символическое обозначение, массу атома, заряд ядра.
 * Вывести сведения о химическом элементе по его символическому названию.
 * Найти элемент с самой большой массой.
 */

struct atom {
    string name;
    char abr[2];
    double mass;
    bool charge; // false means negative, true means positive
};

typedef struct atom DataType;

struct List {
    DataType data;
    struct List *next = nullptr;
};

typedef List *list;

DataType input_atom();

list readFile(string *filename, list begin);

list add(list begin, DataType atom);

void writeFile(string *filename, list begin);

void deleteList(list begin);

void edit(list);

void show(list);

void sum(list begin);

list del(list);

int main() {
    string file;
    char menu = '0';
    list atoms = nullptr;

    // TODO add function for file opening and reading

    //atoms = readFile(&file, atoms);
    atoms = NULL;

    while (menu != '6') {
        system("clear");
        system("cls");
        cout << "1. ADD" << endl;
        cout << "2. Edit record" << endl;
        cout << "3. Show" << endl;
        cout << "4. Sum(?)" << endl;
        cout << "5. Delete record" << endl;
        cout << "6. Quit" << endl;
        cin >> menu;
        switch (menu) {
            case '1':
                atoms = add(atoms, input_atom());
                break;
            case '2':
                edit(atoms);
                break;
            case '3':
                show(atoms);
                break;
            case '4':
                sum(atoms);
                break;
            case '5':
                atoms = del(atoms);

            default:
                break;
        }
    }

    // TODO add function for file opening and writing

    deleteList(atoms);
    return 0;
}

DataType input_atom() {
    DataType atom;
    cout << "Name: ";
    cin >> atom.name;
    cout << "Abbreviation: ";
    cin >> atom.abr;
    cout << "Mass: ";
    cin >> atom.mass;
    cout << "Charge: ";
    cin >> atom.charge;
    return atom;
}

list add(list begin, DataType atom) {
    throw;
}

list readFile(string *filename, list begin) {
    throw;
}

void deleteList(list begin) {
    throw;
}

void writeFile(string *filename, list begin) {
    throw;
}

void edit(list begin) {
    throw;
}

void show(list begin) {
    throw;
}

void sum(list begin) {
    throw;
}

list del(list begin) {
    throw;
}