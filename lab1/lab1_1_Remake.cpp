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
	char name[31]{"ПРОИЗОШЛАОШИБКА"}; ///< Название
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

list add(list begin, atom atom);

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

void sort();

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

		cin >> menu;
		clearBuff();
		switch (menu) {
			case '1':
				system("clear");
				atoms = add(atoms, input_atom()); ///< позволяет пользователю ввести элемент
				sort();
				break;
			case '2':
				system("clear");
				edit(atoms); ///< Радактирование элемента
				sort();
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
				atoms = fillFileWithRandomData(10, atoms);
				break;
			case '9':
				system("clear");
				sort();
				break;

			default:
				break;
		}
	}
	writeFile(inFileName, atoms);
	deleteList(atoms);
	return 0;
}

list add(list begin, atom atom) {
	list temp;
	if (begin == nullptr) {
		begin = new struct List;
		head = tail = begin;
		temp = begin;
		temp->data = atom;
		temp->next = nullptr;
		system("clear");
		return begin;
	}
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

	return head;
}


atom input_atom() {
	atom atom;

	string tmp;
	cout << "Название: ";
	cin >> tmp;
	for (int i = 0; i < 30; ++i) {
		atom.name[i] = tmp[i];
	}
	atom.name[30] = '\000';
	clearBuff();

	tmp.clear();
	cout << "Обозначение: ";
	cin >> tmp;
	for (int i = 0; i < 2; ++i) {
		atom.abr[i] = tmp[i];
	}
	atom.abr[2] = '\000';
	clearBuff();

	double mass;
	cout << "Масса: ";
	cin >> mass;
	while (mass <= 0) {
		clearBuff();
		cout << "Некорректный ввод! " << endl;
		cin >> mass;
	}
	atom.mass = mass;
	clearBuff();

	int charge;
	cout << "Заряд: ";
	cin >> charge;
	while (charge <= 0) {
		clearBuff();
		cout << "Некорректный ввод! " << endl;
		cin >> charge;
	}
	atom.charge = charge;
	clearBuff();
	return atom;
}

list readFile(const string &fileName, list begin) {
	cout << "\n========\nЧтение файла -";
	FILE *f;
	atom atom;
	if ((f = fopen(fileName.c_str(), "rb")) == nullptr) {
		cout << "Ошибка" << endl << endl;
		perror("");
		return begin;
	}
	while (fread(&atom, sizeof(atom), 1, f))
		begin = add(begin, atom);
	fclose(f);
	cout << "OK\n========\n" << endl;
	return begin;
}


void edit(list begin) {
	int n, k = 1;
	char yes;
	system("clear");
	if (begin == nullptr) {
		cout << "Список пуст\n";
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
	cout << "\n========\nЗапись файла -";
	FILE *f;
	if ((f = fopen(filename.c_str(), "wb")) == nullptr) {
		perror("Ошибка создания файла");
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
	atom atom;
	char *tmp = new char[30];
	for (int i = 0; i < amountOfRecords + 1; ++i) {
		const char charset[] =
				"0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
		for (int j = 0; j < 12; ++j) {
			tmp[j] = charset[randomNum()];
		}
		strcpy(atom.name, tmp);
		int j;
		for (j = 0; j < 2; ++j) {
			tmp[j] = charset[randomNum()];
			if (j == 1)
				tmp[j] = tolower(tmp[j]);
			if (j == 0)
				tmp[j] = toupper(tmp[j]);
		}
		tmp[2] = '\0';
		strcpy(atom.abr, tmp);
		atom.mass = randomNum() + randomNum();
		atom.charge = randomNum() + randomNum();
		begin = add(begin, atom);
	}
	system("clear");
	return begin;
}


void sort() {
	list tmp, a, b = new struct List;
	bool flag = true;
	int i = 0;
	while (flag) {
		tmp = head;
		a = tmp->next;
		flag = false;
		while (a) {
			if ((tmp->data.mass) > (a->data.mass)) {
				b->data = tmp->data;
				tmp->data = a->data;
				a->data = b->data;
				flag = true;
				i++;
			}

			tmp = tmp->next;
			a = a->next;

		}
		i++;
	}
}