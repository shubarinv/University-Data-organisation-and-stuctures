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
        element *next; ///< IDK what this var does
        double coef; ///< ���� c � (cx^en)
        int expon; ///< ������� x
    }
            *front, *rear; //������� ������ � ������
public:
    Queue() { front = rear = nullptr; }
    ~Queue();        ///<���������� (������������ ������)
    int Empty(); ///<�������� �� �������
    int Full(); ///<�������� �� ������� ����������
    int Front(); ///<������������� ������ ��������
    int EnQueue(int x); ///<���������� �������� � �������
    int EnQueue(int x, int coef, int powr); ///<@brief ���������� �������� � �������
    int DeQueue(); ///<���������� �������� �� �������
};


void clearBuff() {
    cin.clear();    // Restore input stream to working state
    cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered}
}
/// @param q ��������� �� �������
/// @param qIndex  ?
/// @param amountOfRecords ���������� �������������������� �������
int fillFileWithRandomData(int qIndex, Queue * q, int amountOfRecords);

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "rus");
    char menu = '0';
    Queue q;
    int i = 0;
    while (menu != '4') {
        cout << "1. �������� �������" << endl;
        cout << "2. ��������� diff(NOT YET IMPLEMENTED)" << endl;
        cout << "3. Show" << endl;
        cout << "4. Quit" << endl;
        cout << "5. ��������� ��������" << endl;
        cin >> menu;
        clearBuff();
        switch (menu) {
            case '1':
                // system("clear");
                q.EnQueue(i);
                i++;
                break;
            case '2':
                // system("clear");
                throw;
                break;
            case '3':
                while (!q.Empty()) {
                    q.DeQueue();
                }
                cout << endl;
                break;
            case '5':
                int tmp;
                cout<<"��������� ��������� ���������: ";
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
    cout << "������� ����������� C: ";
    cin >> temp->coef;
    cout << endl << "������� ���������� ������� e: ";
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
    tmp->coef;///< ������ ��������� ����.-��
    tmp->expon;///< ������ ��������� ���������� �������
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

int randomNum() { ///< @brief ���������� ��������� ����� �� 0 �� 100 @bug �� windows �� ��������
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