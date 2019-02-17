//
// Created by vhundef on 13.02.19.
//

#include <string>
#include <iostream>
#include <fstream>
#include <climits>

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

list readFile(string fileName, list begin);

list del(list);

int main(int argc, char *argv[]) {
    string file;
    char menu = '0';
    list atoms = nullptr;

    string inFileName;

    if (argc == 2)
        inFileName = argv[1];
    else {
        cout << "Введите название файла: " << endl;
        cin >> inFileName;
    }
    inFileName = "../lab1-1.txt";
    atoms = readFile(inFileName, atoms);

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
    writeFile(&inFileName, atoms);
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

list readFile(string fileName, list begin) {
    FILE *file;
    DataType atom;
    const char *fileNameC = fileName.c_str();
    if ((file = fopen(fileNameC, "rb")) == NULL) {
        perror("Error open file");
        return begin;
    }
    while (fread(&atom, sizeof(atom), 1, file))
        begin = add(begin, atom);
    fclose(file);
    return begin;
}

list add(list begin, DataType atom) {
    list temp;
    if (begin == nullptr) {
        begin = new struct List;
        temp = begin;
    } else {
        temp = begin;
        while (temp->next) temp = temp->next;
        temp->next = new struct List;
        temp = temp->next;
    }
    temp->data = atom;
    temp->next = nullptr;
    std::cin.ignore(INT_MAX);
    cin.clear();
    return begin;
}

void deleteList(list begin) {
    list temp = begin;
    while (temp) {
        begin = temp->next;
        free(temp);
        temp = begin;
    }
}

void writeFile(string *filename, list begin) {
    FILE *f;
    const char *fileNameC = filename->c_str();
    if ((f = fopen(fileNameC, "wb")) == nullptr) {
        perror("Error create file");
        system("pause");
        return;
    }
    while (begin) {
        fwrite(&begin->data, sizeof(DataType), 1, f);
        begin = begin->next;
    }
    std::cin.ignore(INT_MAX);
    cin.clear();
}

void edit(list begin) {
    throw;
}

void show(list begin) {
    int k = 0;
    if (begin == NULL) {
        puts("List is empty");
        return;
    }
    puts("| # |          Name                   | Abbreviation |  Mass  | Charge |");
    puts("-------------------------------------------------------------------------");
    while (begin) {
        printf("|%3d | %-29s |%11s |%8lf |%10.2d |\n", ++k, begin->data.name.c_str(),
               begin->data.abr, begin->data.mass, begin->data.charge);
        begin = begin->next;
    }
    puts("-------------------------------------------------------------------------");
    std::cin.ignore(INT_MAX);
    cin.clear();
}

void sum(list begin) {
    throw;
}

list del(list begin) {
    throw;
}