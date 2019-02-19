//
// Created by vhundef on 18.02.19.
//

#include <iostream>

typedef int DataType;

class Queue {
    struct element {
        DataType data;
        element *next;
    } *front, *rear; //индексы головы и хвоста
public:
    Queue() { front = rear = NULL; }

    ~Queue();        //деструктор (освобождение памяти)
    int Empty(void); //проверка на пустоту
    int Full(void); //проверка на полноту заполнения
    DataType Front(void); //неразрушающее чтение элемента
    int EnQueue(DataType x); //добавление элемента в очередь
    DataType DeQueue(void); //извлечение элемента из очереди
};

int main(void) {
    Queue q;
    int i;
    for (i = 1; i <= 6; i++)
        q.EnQueue(i);
    std::cout << q.DeQueue() << ' ';
    std::cout << q.DeQueue() << ' ';
    for (i = 1; i < 6; i++)
        q.EnQueue(i);
    while (!q.Empty())
        std::cout << q.DeQueue() << ' ';
    system("pause");
    return 0;
}

int Queue::Empty(void) {
    return front == NULL;
}

int Queue::Full(void) {
    element *temp = new(std::nothrow) element;
    if (temp == NULL) return 1;
    delete temp;
    return 0;
}

DataType Queue::Front(void) {
    return front->data;
}

int Queue::EnQueue(DataType x) {
    element *temp = new(std::nothrow) element;
    if (temp == NULL) return 1;
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

DataType Queue::DeQueue(void) {
    DataType temp = front->data;
    element *tmp = front;
    front = front->next;
    delete tmp;
    return temp;
}

Queue::~Queue() {
    element *temp = front;
    while (front) {
        temp = front;
        front = front->next;
        delete temp;
    }
}