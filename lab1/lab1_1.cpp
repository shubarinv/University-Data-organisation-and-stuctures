#include <utility>
#include <string>
#include <iostream>
#include <fstream>
//
// Created by vhundef on 13.02.19.
//

using namespace std;
/*
 * Поля данных:
 * Название, символическое обозначение, массу атома, заряд ядра.
 * Вывести сведения о химическом элементе по его символическому названию.
 * Найти элемент с самой большой массой.
 */

struct atom {
    string name;
    string abr;
    double mass;
    int charge; // false means negative, true means positive
};
typedef struct atom DataType;

struct List {
    DataType data;
    struct List *next = nullptr;
};


typedef List *list;

DataType input_atom();

void clearBuff() {
    cin.clear();    // Restore input stream to working state
    cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered}
}


list add(list begin, DataType atom);

void writeFile(string filename, list begin);

void deleteList(list begin);

void edit(list);

void show(list, bool);

list readFile(string fileName, list begin);

list findMax(list);

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
        cout << "4. Find Max" << endl;
        cout << "5. Delete record" << endl;
        cout << "6. Quit" << endl;
        cin >> menu;
        clearBuff();
        switch (menu) {
            case '1':
                atoms = add(atoms, input_atom());
                break;
            case '2':
                edit(atoms);
                break;
            case '3':
                show(atoms, true);
                break;
            case '4':
                show(findMax(atoms), false);
                break;
            case '5':
                atoms = del(atoms);

            default:
                break;
        }
    }
    writeFile(inFileName, atoms);
    deleteList(atoms);
    return 0;
}

DataType input_atom() {
    DataType atom;
    cout << "Name: ";
    cin >> atom.name;
    clearBuff();
    cout << "Abbreviation: ";
    cin >> atom.abr;
    clearBuff();
    cout << "Mass: ";
    cin >> atom.mass;
    clearBuff();
    cout << "Charge: ";
    cin >> atom.charge;
    //clearBuff();
    return atom;
}

list readFile(string fileName, list begin) {
    ifstream f(fileName);
    if (!f)
        return begin;
    DataType atom;
    string str;
    char c = '\n';
    int counter = 0;
    while (getline(f, str, c)) {
        cout << "Str :" << str << " ITR " << counter << endl;
        switch (counter) {
            case 0:
                atom.name = str;
                counter++;
                break;
            case 1:
                atom.abr = str;
                counter++;
                break;
            case 2:
                atom.mass = atoi(str.c_str());
                counter++;
                break;
            case 3:
                atom.charge = atoi(str.c_str());
                counter++;
                break;
            case 4:
                counter = 0;
                begin = add(begin, atom);
                break;
            default:
                atom.name = "";
                atom.abr = "";
                atom.mass = 0;
                atom.charge = 0;
        }
    }
    clearBuff();
    f.close();
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
    temp->data = std::move(atom);
    temp->next = nullptr;
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


void writeFile(string filename, list begin) {
    ofstream f(filename);
    if (!f) {
        return;
    }
    while (begin) {
        f << begin->data.name << endl << begin->data.abr << endl;
        f << begin->data.mass << endl << begin->data.charge << endl << "====" << endl;
        begin = begin->next;
    }
    f.close();
}

void printLine(list pos) {
    printf("Name : %s\nAbbreviation : %s\nMass : %lf\nCharge : %.2d\n", pos->data.name.c_str(),
           pos->data.abr.c_str(), pos->data.mass, pos->data.charge);
}

void edit(list begin) {
    int n, k = 1;
    char yes;
    system("clear");
    if (begin == nullptr) {
        cout << "List is empty";
        return;
    }
    cout << "Number record for redact?";
    cin >> n;
    if (n < 1) {
        cout << "Error";
        return;
    }
    while (begin && k < n) {
        begin = begin->next;
        k++;
    }
    if (begin == nullptr) {
        cout << "Error";
        return;
    }
    printLine(begin);
    puts("Redact? (y/n)");
    do
        cin >> yes;
    while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
    if (yes == 'y' || yes == 'Y')
        begin->data = input_atom();
}

void show(list begin, bool all) {
    int k = 0;
    if (begin == nullptr) {
        puts("List is empty");
        return;
    }
    puts("| # |          Name                   | Abbreviation |  Mass  | Charge |");
    puts("-------------------------------------------------------------------------");
    if (all) {
        while (begin) {
            printf("|%2d | %-30s  |%-13s |%8lf |%-5d |\n", ++k, begin->data.name.c_str(),
                   begin->data.abr.c_str(), begin->data.mass, begin->data.charge);
            begin = begin->next;
        }
    } else {
        printf("|%2s | %-30s  |%-13s |%8lf |%-5d |\n", " ", begin->data.name.c_str(),
               begin->data.abr.c_str(), begin->data.mass, begin->data.charge);
    }
    puts("-------------------------------------------------------------------------");
}

list findMax(list begin) {
    list maxEntry = nullptr;
    double max = -1;
    while (begin) {
        if (begin->data.mass > max) {
            max = begin->data.mass;
            maxEntry = begin;
        }
        begin = begin->next;
    }
    return maxEntry;
}

list del(list begin) {
    int n, k = 1;
    char yes;
    list temp, temp1;
    system("clear");
    system("cls");
    if (begin == nullptr) {
        cout << "List is empty";
        return nullptr;
    }
    cout << "Number record for delete?";
    cin >> n;
    if (n < 1) {
        cout << "ERR";
        return begin;
    }
    if (n == 1) {
        printLine(begin);
        puts("Delete? (y/n)");
        do
            yes = static_cast<char>(getchar());
        while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
        if (yes == 'y' || yes == 'Y') {
            temp = begin->next;
            free(begin);
            return temp;
        } else return begin;
    }
    if (begin->next == nullptr && n > 1) {
        cout << "ERR";
        return begin;
    }
    temp = begin;
    temp1 = temp->next;
    while (temp1->next && k < n - 1) {
        temp = temp1;
        temp1 = temp->next;
        k++;
    }
    if (k < n - 1) {
        cout << "ERR";
        return begin;
    }
    printLine(temp1);
    cout << "Delete? (y/n)";
    do
        yes = static_cast<char>(getchar());
    while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
    if (yes == 'y' || yes == 'Y') {
        temp->next = temp1->next;
        free(temp1);
    }
    return begin;
}