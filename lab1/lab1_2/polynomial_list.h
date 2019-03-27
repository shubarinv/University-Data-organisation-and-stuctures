//
// Created by vhund on 27.03.2019.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_POLYNOMIAL_LIST_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_POLYNOMIAL_LIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

template<class DataType>

class Queue {
    struct element {
        DataType data;
        element *next;
    } *front, *rear; //индексы головы и хвоста

public:

    Queue() { front = rear = NULL; }
    ~Queue(); //деструктор (освобождение памяти)
    int Empty(); //проверка на пустоту
    int Full(); //проверка на полноту заполнения
    DataType Front(); //неразрушающее чтение элемента
    int EnQueue(DataType x); //добавление элемента в очередь
    DataType DeQueue(); //извлечение элемента из очереди
};

template<class DataType>
int Queue<DataType>::Empty() {
    return front == NULL;
}

template<class DataType>
int Queue<DataType>::Full() {
    element *temp = new element;
    if (temp == NULL) return 1;
    delete temp;
    return 0;
}

template<class DataType>
DataType Queue<DataType>::Front() {
    return front->data;
}

template<class DataType>
int Queue<DataType>::EnQueue(DataType x) {
    if (Full()) return 0;
    element *temp = new element;
    temp->data = x;
    temp->next = NULL;
    if (front == NULL)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = rear->next;
    }
    return 1;
}

template<class DataType>
DataType Queue<DataType>::DeQueue() {
    DataType temp = front->data;
    element *tmp = front;
    front = front->next;
    delete tmp;
    return temp;
}

template<class DataType>
Queue<DataType>::~Queue() {
    element *temp = front;
    while (front) {
        temp = front;
        front = front->next;
        delete temp;
    }
}

#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_POLYNOMIAL_LIST_H
