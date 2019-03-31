/* Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Feb 2019
 */

#include <utility>
#include <string>
#include <iostream>
#include <cstring>
#include <random>

using namespace std;
/*
 * Поля данных:
 * Название, символическое обозначение, массу атома, заряд ядра.
 * Вывести сведения о химическом элементе по его символическому названию.
 * Найти элемент с самой большой массой.
 */
struct atom {
	char name[31]; ///< Название
	char abr[3];   ///< Сокращение
	double mass;   ///< Масса
	int charge{0}; ///< Заряд

};
typedef struct atom DataType;

struct List {
	DataType data;
	struct List *next = nullptr;
};

typedef List *list;

DataType input_atom();

void clearBuff() { ///< @brief Чистит буфер
    cin.clear();    // Restore input stream to working state
    cin.ignore(1000, '\n');    // Get rid of any garbage that user might have entered}
}

list add(list begin, DataType atom);

/// @param filename Название файла для записи
void writeFile(string filename, list begin);

void deleteList(list begin);

void edit(list);

///@param bool Выводить одну запись или несколько
void show(list, bool);

/// @param filename Название файла для записи
list readFile(string fileName, list begin);

/// @brief Находит элемент с максимальной массой
list findMax(list);

list del(list);

/// @brief Находит элемент по сокращённому названию
list findElmntByAbbr(list);

/// @brief Заполняет массив случайными элементами
list fillFileWithRandomData(int, list);

int main(int argc, char *argv[]) {
	char menu = '0';
	list atoms = nullptr;

	string inFileName; // Хранит название файла для чтения и записи

	if (argc == 2) // Если в main переданно название файла, то оно присваивается infilename
		inFileName = argv[1];
	else { // иначе спрашиваем название файла у пользователя
		cout << "Введите название файла: " << endl;
		cin >> inFileName;
	}
	atoms = readFile(inFileName, atoms); ///< Читает указанный пользователем файл
	while (menu != '7') {
		cout << "1. ADD" << endl;
		cout << "2. Edit record" << endl;
		cout << "3. Show" << endl;
		cout << "4. Find Max" << endl;
		cout << "5. Find Element by Abbr" << endl;
		cout << "6. Delete record" << endl;
		cout << "7. Quit" << endl;
		cout << "8. Random fill" << endl;

		cin >> menu;
		clearBuff();
		switch (menu) {
			case '1':
				system("clear");
				atoms =
						add(atoms, input_atom()); ///< позволяет пользователю ввести элемент
				break;
			case '2':
				system("clear");
				edit(atoms); ///< Радактирование элемента
				break;
			case '3':
				system("clear");
				show(atoms, true); ///< Вывод всех элементов
				break;
			case '4':
				system("clear");
				show(findMax(atoms), false);
				break;
			case '5':
				system("clear");
				show(findElmntByAbbr(atoms), false);
				break;
			case '6':
				system("clear");
				atoms = del(atoms);
				break;
			case '8':
				system("clear");
				atoms = fillFileWithRandomData(80, atoms);
				break;

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

	string tmp;
	cout << "Name: ";
	cin >> tmp;
	for (int i = 0; i < 30; ++i) {
		atom.name[i] = tmp[i];
	}
	atom.name[30] = '\000';
	clearBuff();

	tmp.clear();
	cout << "Abbreviation: ";
	cin >> tmp;
	for (int i = 0; i < 2; ++i) {
		atom.abr[i] = tmp[i];
	}
	atom.abr[2] = '\000';
	clearBuff();

	double mass;
	cout << "Mass: ";
	cin >> mass;
	while (mass <= 0) {
		clearBuff();
		cout << "I call bullshit on that!!!!!" << endl;
		cin >> mass;
	}
	atom.mass = mass;
	clearBuff();

	int charge;
	cout << "Charge: ";
	cin >> charge;
	while (charge <= 0) {
		clearBuff();
		cout << "I call bullshit on that!!!!!" << endl;
		cin >> charge;
	}
	atom.charge = charge;
	clearBuff();

	return atom;
}

list readFile(string fileName, list begin) {
	cout << "\n========\nReading file -";
	FILE *f;
	DataType atom;
	if ((f = fopen(fileName.c_str(), "rb")) == NULL) {
		cout << "ERROR" << endl << endl;
		perror("");
		return begin;
	}
	while (fread(&atom, sizeof(atom), 1, f))
		begin = add(begin, atom);
	fclose(f);
	cout << "OK\n========\n" << endl;
	return begin;
}

list add(list begin, DataType atom) {
	list temp;
	if (begin == nullptr) {
		begin = new struct List;
		temp = begin;
	} else {
		temp = begin;
		while (temp->next)
			temp = temp->next;
		temp->next = new struct List;
		temp = temp->next;
	}
	temp->data = atom;
	temp->next = nullptr;
	system("clear");
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
	cout << "\n========\nWriting file -";
	FILE *f;
	if ((f = fopen(filename.c_str(), "wb")) == NULL) {
		perror("Error create file");
		system("pause");
		return;
	}
	while (begin) {
		fwrite(&begin->data, sizeof(DataType), 1, f);
		begin = begin->next;
	}
	cout << "OK\n========\n" << endl;
}

void printLine(list pos) {
	printf("Name : %s\nAbbreviation : %s\nMass : %lf\nCharge : %.2d\n",
	       pos->data.name, pos->data.abr, pos->data.mass, pos->data.charge);
}

void edit(list begin) {
	int n, k = 1;
	char yes;
	system("clear");
	if (begin == nullptr) {
		cout << "List is empty\n";
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
		cout << "Error\n";
		return;
	}
	printLine(begin);
	puts("Redact? (y/n)");
	do
		cin >> yes;
	while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
	if (yes == 'y' || yes == 'Y')
		begin->data = input_atom();
	system("clear");
}

void show(list begin,
          bool all) { // если all =true ,тогда будут напечатаны все элементы
	// после указанного(вкл указанный), иначе будет напечатан
	// только указанный элемент
	int k = 1;
	if (begin == nullptr) {
		puts("List is empty\n");
		return;
	}
	puts("| # |          Name                   | Abbreviation |  Mass  | Charge |");
	puts("------------------------------------------------------------------------");
	if (all) {

		while (begin) {
			if (k % 10 == 0) {
				cout << "________________________________________________________________________"<< endl;
				cout << "                 Press ENTER to go to the next page                     "<< endl<< endl;
				getchar();
				// system("clear");
				system("cls");
			}
			printf("|%2d | %-30s  |%-13s |%8lf |%-5d |\n", k++, begin->data.name,
			       begin->data.abr, begin->data.mass, begin->data.charge);
			begin = begin->next;
		}
	} else {
		printf("|%2s | %-30s  |%-13s |%8lf |%-5d |\n", " ", begin->data.name,
		       begin->data.abr, begin->data.mass, begin->data.charge);
	}
	puts("------------------------------------------------------------------------");
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

list findElmntByAbbr(list begin) {
	char lookFor[2];
	cout << "Введите сокращение искомого элемента: ";
	cin >> lookFor;
	string tmp;
	while (begin) {
		tmp = begin->data.abr;
		if (tmp == lookFor)
			break;
		begin = begin->next;
	}
	return begin;
}

list del(list begin) {
	int n, k = 1;
	char yes;
	list temp, temp1;
	system("clear");
	if (begin == nullptr) {
		cout << "List is empty\n";
		return nullptr;
	}
	cout << "Number record for delete? ";
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
		} else
			return begin;
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
		cout << "ERR\n";
		return begin;
	}
	printLine(temp1);
	cout << "Delete? (y/n) ";
	do
		yes = static_cast<char>(getchar());
	while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
	if (yes == 'y' || yes == 'Y') {
		temp->next = temp1->next;
		free(temp1);
	}
	return begin;
}

// ONLY FOR DEBUG
int randomNum() { // Данная функция генерирует рандомное число
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist6(0, 62);
	return static_cast<int>(dist6(rng));
}

list fillFileWithRandomData(
		int amountOfRecords,
		list begin) { // Эта функция заполняет таблицу элементов  указанным кол-вом
	// элементов
	DataType atom;
	char *tmp = new char[30];
	for (int i = 0; i < amountOfRecords + 1; ++i) {
		const char charset[] =
				"0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
		for (int j = 0; j < 12; ++j) {
			tmp[j] = charset[randomNum()];
		}
		strcpy(atom.name, tmp);
		for (int j = 0; j < 2; ++j) {
			tmp[j] = charset[randomNum()];
		}
		strcpy(atom.abr, tmp);
		atom.mass = randomNum() + randomNum();
		atom.charge = randomNum() + randomNum();
		begin = add(begin, atom);
	}
	system("clear");
	return begin;
}
