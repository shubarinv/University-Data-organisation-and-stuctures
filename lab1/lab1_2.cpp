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

class Queue {
    struct element {
        DataType data;
        element *next;
        double coef; ///< Коэф c в (cx^en)
        int expon; ///< Степень x
    }
            *front, *rear; //индексы головы и хвоста
public:
    Queue() { front = rear = nullptr; }
    ~Queue();        ///<деструктор (освобождение памяти)
    int Empty(); ///<проверка на пустоту
    int Full(); ///<проверка на полноту заполнения
    int Front(); ///<неразрушающее чтение элемента
    int EnQueue(int x); ///<добавление элемента в очередь
    int EnQueue(int x, int coef, int powr); ///<@brief добавление элемента в очередь
    int DeQueue(); ///<извлечение элемента из очереди
};


void clearBuff() {
    cin.clear();    // Restore input stream to working state
    cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered}
}
/// @param q Указатель на очередь
/// @param qIndex  ?
/// @param amountOfRecords Количество рандомногенерируемых записей
int fillFileWithRandomData(int qIndex, Queue * q, int amountOfRecords);

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
            case '3':
                while (!q.Empty()) {
                    q.DeQueue();
                }
                cout << endl;
                break;
            case '5':
                int tmp;
                cout<<"Количесто рандомных элементов: ";
                cin>>tmp;
                fillFileWithRandomData(i,&q,tmp);
                break;
            default:
                break;
        }
    }
    return 0;
}


int Queue::Empty() {
    return front == nullptr;
}

int Queue::Full() {
    element *temp = new(std::nothrow) element;
    if (temp == nullptr) return 1;
    delete temp;
    return 0;
}

DataType Queue::Front() {
    return front->data;
}

int Queue::EnQueue(DataType x) {
    element *temp = new(std::nothrow) element;
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


Queue::~Queue() {
    element *temp = front;
    while (front) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

/// @brief Somewhy returns element index... not that it is useful in this case
DataType Queue::DeQueue() {
    DataType temp = front->data;
    element *tmp = front;
    tmp->coef;///< Пример получения коэф.-та
    tmp->expon;///< Пример получения показателя степени
    cout << tmp->coef << "*x^" << tmp->expon;
    front = front->next;
    delete tmp;
    if (front != nullptr) cout << "+";
    return temp;
}

int Queue::EnQueue(DataType x, int coef, int powr) { ///< @warning Only for debug purposes
    element *temp = new(std::nothrow) element;
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

int fillFileWithRandomData(int qIndex, Queue * q, int amountOfRecords) {
    int i;
    for (i = qIndex; i < amountOfRecords; i++) {
        q->EnQueue(qIndex, randomNum(), randomNum());
    }
    return i;
}