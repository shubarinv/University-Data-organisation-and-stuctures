//
// Created by vhund on 27.03.2019.
//

#include <iostream>

#include <cstdlib>

#define MAXLENGTH 100

template<class DataType>

class Queue {
    int front, rear; //индексы головы и хвоста
    DataType data[MAXLENGTH]; //массив для хранения элементов

public:
    Queue() {
        front = 0;
        rear = MAXLENGTH - 1;
    }

    int Empty(void); //проверка на пустоту
    int Full(void); //проверка на полноту заполнения
    DataType Front(void); //неразрушающее чтение элемента
    int EnQueue(DataType x); //добавление элемента в очередь
    DataType DeQueue(void); //извлечение элемента из очереди

};

template<class DataType>
int Queue<DataType>::Empty(void) {
    return (rear + 1) % MAXLENGTH == front;
}

template<class DataType>
int Queue<DataType>::Full(void) {
    return (rear + 2) % MAXLENGTH == front;
}

template<class DataType>
DataType Queue<DataType>::Front(void) {
    return data[front];
}

template<class DataType>
int Queue<DataType>::EnQueue(DataType x) {
    if (Full()) return 0;
    rear = (rear + 1) % MAXLENGTH;
    data[rear] = x;
    return 1;
}

template<class DataType>
DataType Queue<DataType>::DeQueue(void) {
    int temp = front;
    front = (front + 1) % MAXLENGTH;
    return data[temp];
}