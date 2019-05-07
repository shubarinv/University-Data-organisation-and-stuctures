//
// Created by vhund on 27.03.2019.
//

#include <iostream>

#include <cstdlib>

#define MAXLENGTH 100

template<class DataType>

class Queue {
	int front, rear;          //индексы головы и хвоста
	DataType data[MAXLENGTH]; //массив для хранения элементов

public:
	Queue() {
		front = 0;
		rear = MAXLENGTH - 1;
	}

	bool Empty(); //проверка на пустоту
	bool Full();  //проверка на полноту заполнения
	DataType Front(); //неразрушающее чтение элемента
	int EnQueue(DataType x); //добавление элемента в очередь
	DataType DeQueue(); //извлечение элемента из очереди
	~Queue();
};

template<class DataType>
bool Queue<DataType>::Empty() {
	return (rear + 1) % MAXLENGTH == front;
}

template<class DataType>
bool Queue<DataType>::Full() {
	return (rear + 2) % MAXLENGTH == front;
}

template<class DataType>
DataType Queue<DataType>::Front() {
	return data[front];
}

template<class DataType>
int Queue<DataType>::EnQueue(DataType x) {
	if (Full())
		return 0;
	rear = (rear + 1) % MAXLENGTH;
	data[rear] = x;
	return 1;
}

template<class DataType>
DataType Queue<DataType>::DeQueue() {
	int temp = front;
	front = (front + 1) % MAXLENGTH;
	return data[temp];
}

template<class DataType>
Queue<DataType>::~Queue() {
	while (!Empty()) {
		DeQueue();
	}
}