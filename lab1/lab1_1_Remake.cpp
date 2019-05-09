/* Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vladimir Shubarin <vhundef@gmail.com>, may 2019
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
	char name[31]{"ERR NAME WASN'T SET"}; ///< Название
	char abr[3]{"ER"};   ///< Сокращение
	double mass{0};   ///< Масса
	int charge{0}; ///< Заряд

};

struct List {
	atom data;
	List *next = nullptr; ///< Next element
	List *prev = nullptr; ///< Previous element
};
List *head; ///< First element
List *tail; ///< Last element

typedef List *list;

void clearBuff() { ///< @brief Чистит буфер
	cin.clear();    // Restore input stream to working state
	cin.ignore(1000, '\n');    // Get rid of any garbage that user might have entered}
}

atom input_atom(); ///< Добавление элемента

list add(list begin, atom atom, bool);

/// @param filename Название файла для записи
void writeFile(const string &filename, list begin);

void deleteList(list begin);

void edit(list);

///@param bool Выводить одну запись или несколько
void show(list, bool);

/// @param filename Название файла для записи
list readFile(const string &fileName, list begin);

/// @brief Находит элемент с максимальной массой
list findMax(list);

list del_atoms(list);

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
				atoms = add(atoms, input_atom(), false); ///< позволяет пользователю ввести элемент
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
				atoms = del_atoms(atoms);
				break;
			case '8':
				system("clear");
				//	atoms = fillFileWithRandomData(80, atoms);
				break;

			default:
				break;
		}
	}
	writeFile(inFileName, atoms);
	deleteList(atoms);
	return 0;
}

list add(list begin, atom atom, bool bIsAuto) {
	list temp = begin;
	if (begin == nullptr) {
		begin = new struct List;
		head = tail = begin;
		temp = begin;
		temp->data = atom;
		temp->next = nullptr;
		system("clear");
		return begin;
	}
	char tmp = '-';
	if (!bIsAuto) {

		cout << "Куда добавить элемент?" << endl
		     << "1) В начало списка\n2) После указанного элемента\n3) В конец списка\n"
		     << endl;
		cin >> tmp;
	} else
		tmp = 3;
	if (tmp == '1') {
		begin = new struct List;
		begin->data = atom;
		begin->next = head;
		head->prev = begin;
		head = begin;
		return head;

	} else if (tmp == '2') {
		int tmp1;
		begin = new struct List;
		begin->data = atom;
		cout << "После какого элемента: ";
		cin >> tmp1;
		tmp1--;
		for (int i = 0; i < tmp1; i++) {
			temp = temp->next;
		}
		begin->next = temp->next;
		begin->prev = temp;
		temp->next = begin;

		return head;
	} else if (tmp == '3') {
		temp = begin;
		list prev;
		while (temp->next) {
			prev = temp;
			temp = temp->next;
			temp->prev = prev;
		}
		prev = temp;
		temp->next = new struct List;
		temp = temp->next;
		temp->prev = prev;
		temp->data = atom;
	}
	return head;
}


atom input_atom() {
	atom atom;

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
		cout << "Invalid value! Try again" << endl;
		cin >> mass;
	}
	atom.mass = mass;
	clearBuff();

	int charge;
	cout << "Charge: ";
	cin >> charge;
	while (charge <= 0) {
		clearBuff();
		cout << "Invalid value! Try again" << endl;
		cin >> charge;
	}
	atom.charge = charge;
	clearBuff();
	return atom;
}

list readFile(const string &fileName, list begin) {
	cout << "\n========\nReading file -";
	FILE *f;
	atom atom;
	if ((f = fopen(fileName.c_str(), "rb")) == nullptr) {
		cout << "ERROR" << endl << endl;
		perror("");
		return begin;
	}
	while (fread(&atom, sizeof(atom), 1, f))
		begin = add(begin, atom, true);
	fclose(f);
	cout << "OK\n========\n" << endl;
	return begin;
}


void edit(list begin) {
	int n, k = 1;
	char yes;
	system("clear");
	if (begin == nullptr) {
		cout << "List is empty\n";
		return;
	}
	cout << "Номер записи которую надо отредактировать? ";
	cin >> n;
	if (n < 1) {
		cout << "Ошибочка вышла\n\n";
		return;
	}
	while (begin && k < n) {
		begin = begin->next;
		k++;
	}
	if (begin == nullptr) {
		cout << "Ошибочка вышла\n\n";
		return;
	}
	show(begin, false);
	puts("Отредактировать? (y/n)");
	do
		cin >> yes;
	while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
	if (yes == 'y' || yes == 'Y')
		begin->data = input_atom();
	system("clear");
}

void show(list begin, bool all) { // если all =true ,тогда будут напечатаны все элементы
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

		while (begin != nullptr) {
			if (k % 10 == 0) {
				cout << "________________________________________________________________________" << endl;
				cout << "                 Press ENTER to go to the next page                     " << endl << endl;
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

list del_atoms(list begin) {
	if (begin == nullptr) {
		cout << "А список то пуст" << endl << endl;
		return nullptr;
	}
	cout << "Введите номер элемента который вы хотите удалить: ";
	begin = head;
	int tmp;
	cin >> tmp;
	tmp--;
	for (int i = 0; i < tmp; i++) {
		begin = begin->next;
	}
	if (begin == nullptr) {
		cout << "Нет элемента с таким номером" << endl << endl;
		return head;
	}
	cout << "Вы хотите удалить? " << endl;
	show(begin, false);

	if (begin->next == nullptr) // Which means element is the last one
		tail = begin;
	if (begin->prev == nullptr)
		head = begin;
	if (head != tail) {
		begin->prev->next = begin->next;
		begin->next->prev = begin->prev;
	}
	return head;
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

void writeFile(const string &filename, list begin) {
	cout << "\n========\nWriting file -";
	FILE *f;
	if ((f = fopen(filename.c_str(), "wb")) == nullptr) {
		perror("Error create file");
		system("pause");
		return;
	}
	while (begin) {
		fwrite(&begin->data, sizeof(atom), 1, f);
		begin = begin->next;
	}
	cout << "OK\n========\n" << endl;
}

void deleteList(list begin) {
	list temp = begin;
	while (temp) {
		begin = temp->next;
		free(temp);
		temp = begin;
	}
}