/* Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Feb 2019
 */

#include <cstdlib>
#include <iostream>
//#include <windows.h>

using namespace std;

#include "lab1_2/polynomial_list.h"

struct num {
	float coef; /* Коэффициент */
	int pwr;    /* Степень */
};

num polinom{1, 1};
num cplnm{-1, -1};

void clearBuff() { ///< @brief Чистит буфер
	cin.clear();     // Restore input stream to working state
	cin.ignore(1000, '\n'); // Get rid of any garbage that user might have entered}
}

void enterPolinomial(Queue<struct num> *, int);

void printPolinomial(Queue<struct num> *);

void diffPolinomial(Queue<struct num> *);

int main(int argc, char *argv[]) {

	/* Чтобы русский текст выводился нормально */
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);

	Queue<struct num> polinm;

	bool doOnce = true;
	char k = 'e';
	while (k != '0') {
		cout << "p(x)=C1*X^e1+C2*X^e2+...+Cn*X^en" << endl;
		cout << "e1>e2>...>en>=0" << endl;
		cout << "_____________________________" << endl;
		cout << "1: Задать многочлен 1 " << endl;
		cout << "2: Удалить многочлен 1 " << endl;
		if (doOnce)
			cout << "3: Продифференцировать многочлен " << endl;
		cout << "4: Вывести многочлен " << endl;
		cout << "0:Выход" << endl;
		cout << endl;
		cin >> k;

		switch (k) {
			case '1':
				int n;
				cout << "Введите количество элементов в многочлене: ";
				cin >> n;
				enterPolinomial(&polinm, n);
				break;
			case '2':
				system("cls");
				polinm.~Queue();
				cout << "Многочлен был удалён" << endl;
				break;
			case '3':
				if (doOnce) {
					diffPolinomial(&polinm);
					doOnce = false;
				} else cout << "Функция отключена";
				break;
			case '4':
				printPolinomial(&polinm);
				break;
		}
	}
	return 0;
}

void printPolinomial(Queue<struct num> *queue) {
	system("cls");
	polinom = {1, 1};
	cplnm = {-1, -1};
	cout << "==============" << endl;
	if (!queue->Empty()) {
		while (cplnm.pwr < polinom.pwr) {
			polinom = queue->DeQueue();
			cout << polinom.coef << "X^" << polinom.pwr << "+ ";
			queue->EnQueue(polinom);
			cplnm = queue->Front();
		}
		cout << endl << "==============" << endl;
	} else
		cout << "Пустой многочлен" << endl;
}

void diffPolinomial(Queue<struct num> *queue) {
	system("cls");
	polinom = {1, 1};
	cplnm = {-1, -1};
	if (!queue->Empty())
		while (cplnm.pwr < polinom.pwr) {
			polinom = queue->DeQueue();
			polinom.coef *= polinom.pwr;
			polinom.pwr--;
			queue->EnQueue(polinom);
			cplnm = queue->Front();
		}
	cout << endl << "Продифференцированно !" << endl;
}

void enterPolinomial(Queue<struct num> *queue, int n) {
	system("cls");
	if (queue->Empty()) {
		int tmp;
		clearBuff();
		while (n < 1) {
			cout << "Кол-во элементов не может быть < 1 . Please try again ";
			cin >> n;
			clearBuff();
		}
		cout << "Введите коэф. Х: ";
		cin >> polinom.coef;
		clearBuff();
		while (polinom.coef == 0) {
			cout << "Многочлен не может существовать если коэф. Х = 0 . Please try again ";
			cin >> polinom.coef;
			clearBuff();
		}
		cout << "Введите степень: ";
		cin >> polinom.pwr;
		tmp = polinom.pwr;
		queue->EnQueue(polinom);
		n--;
		while (n > 0) {
			if (tmp == 0) {
				cout << "Ввод не может быть продолжен т.к степень не может быть (<) или (=) 0";
				break;
			}
			cout << "Введите коэф. Х: ";
			cin >> polinom.coef;
			clearBuff();
			while (polinom.coef == 0) {
				cout << "Многочлен не может существовать если коэф. Х = 0 . Please try again ";
				cin >> polinom.coef;
				clearBuff();
			}
			cout << "Введите степень: ";
			cin >> polinom.pwr;
			clearBuff();
			while (polinom.pwr >= tmp || polinom.pwr < 0) {
				cout << "Степень должна быть меньше предыдущей и больше 0: ";
				cin >> polinom.pwr;
				clearBuff();
			}
			tmp = polinom.pwr;
			queue->EnQueue(polinom);
			n--;
		}
		cout << "Многочлен задан" << endl;
	} else
		cout << "Многочлен уже был задан" << endl;

	// Просмотр многочлена
	if (!queue->Empty()) {
		cout << endl << "==============" << endl;
		while (cplnm.pwr < polinom.pwr) {
			polinom = queue->DeQueue();
			cout << polinom.coef << "X^" << polinom.pwr << "+ ";
			queue->EnQueue(polinom);
			cplnm = queue->Front();
		}
		cout << endl << "==============" << endl;
	}
}