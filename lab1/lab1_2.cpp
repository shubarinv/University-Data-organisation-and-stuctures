/* Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Feb 2019
 */

/***
 * @author Vladimir Shubarin.
 * @date 19.02.19
 * @file lab1_2.cpp
*/

#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

typedef int DataType;

class Element {
public:
    DataType data;
    Element *next;
    double coef; ///< Коэф c в (cx^en)
    int expon; ///< Степень x
};

class Queue {
public:
    Element *front;
    Element *rear; //индексы головы и хвоста
public:
    Queue() { front = rear = nullptr; }

    ~Queue() { ///<деструктор (освобождение памяти)
        Element *elmnt;
        while (front) {
            elmnt = front;
            front = front->next;
            delete elmnt;
        }
    }

    int Empty(); ///<проверка на пустоту
    int EnQueue(int x); ///<добавление элемента в очередь
    int EnQueue(int x, int coef, int powr); ///<@brief добавление элемента в очередь
    void showAllElements();

    void findDiff();
};


void clearBuff() {
    cin.clear();    // Restore input stream to working state
    cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered}
}

/// @param q Указатель на очередь
/// @param qIndex  ?
/// @param amountOfRecords Количество рандомногенерируемых записей
int fillFileWithRandomData(int qIndex, Queue *q, int amountOfRecords);


int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "rus");
    char menu = '0';
    Queue q;
    int i = 0;
    while (menu != '4') {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Посчитать diff(NOT YET IMPLEMENTED)" << endl;
        cout << "3. Show" << endl;
        cout << "4. Quit" << endl;
        cout << "5. Заполнить рандомно" << endl;
        cin >> menu;
        clearBuff();
        switch (menu) {
            case '1':
                q.EnQueue(i);
                i++;
                break;
            case '2':
                throw;
                break;
            case '3':
                q.showAllElements();
                break;
            case '5':
                int tmp;
                cout << "Количесто рандомных элементов: ";
                cin >> tmp;
                fillFileWithRandomData(i, &q, tmp);
                break;
            default:
                break;
        }
    }
    return 0;
}

void Queue::showAllElements() {
    Element *Vsp;
    cout << endl << "\t\tShow QUEUE:" << endl;
    if (!Empty()) {
        while (front) {
            cout << front->coef << "*x^" << front->expon << "+";
            Vsp = front;
            front = front->next;

        }
        cout<<endl;
        front = rear = NULL;
    }
}

void Queue::findDiff() {
    if (!Queue::Empty()) {
        while (front) {
            cout << front->coef << "*x^" << front->expon << "+";
            front = front->next;
        }
        cout << endl;
        front = rear = NULL;
    }
}

int Queue::Empty() {
    return front == nullptr;
}

int Queue::EnQueue(DataType x) {
    Element *temp = new(std::nothrow) Element;
    if (temp == nullptr) return 1;
    temp->data = x;
    temp->next = nullptr;
    if (front == nullptr)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = rear->next;
    }
    cout << "Введите коэффициент C: ";
    cin >> temp->coef;
    cout << endl << "Введите показатель степени e: ";
    cin >> temp->expon;
    cout << endl;
    if (temp->expon < 0) {
        return 0;
    }
    return 1;
}


int Queue::EnQueue(DataType x, int coef, int powr) { ///< @warning Only for debug purposes
    Element *temp = new(std::nothrow) Element;
    if (temp == nullptr) return 1;
    temp->data = x;
    temp->next = nullptr;
    if (front == nullptr)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = rear->next;
    }
    temp->coef = coef;
    temp->expon = powr;
    if (temp->expon < 0) {
        return 0;
    }
    return 1;
}

int randomNum() { ///< @brief Генерирует случайные числа от 0 до 100 @bug на windows не работает
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> dist6(1, 100);
    return static_cast<int>(dist6(rng));
}

int fillFileWithRandomData(int qIndex, Queue *q, int amountOfRecords) {
    int i;
    for (i = qIndex; i < amountOfRecords; i++) {
        q->EnQueue(qIndex, randomNum(), randomNum());
    }
    return i;
}