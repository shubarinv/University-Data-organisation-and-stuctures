//
// Created by vhundef on 18.02.19.
//

#include <iostream>

typedef int DataType;

using namespace std;

class Queue {
    struct element {
        DataType data;
        element *next; ///< IDK what this var does
        double coef; ///< Коэф c в (cx^en)
        int expon; ///< Степень x
    } *front, *rear; //индексы головы и хвоста
public:
    Queue() { front = rear = nullptr; }

    ~Queue();        ///<деструктор (освобождение памяти)
    int Empty(); ///<проверка на пустоту
    int Full(); ///<проверка на полноту заполнения
    DataType Front(); ///<неразрушающее чтение элемента
    int EnQueue(DataType x); ///<добавление элемента в очередь
    DataType DeQueue(); ///<извлечение элемента из очереди
};

int main() {
    Queue q;
    int i = 0;
    while (q.EnQueue(i)) {
        i++;
    }
    while (!q.Empty())
        cout << q.DeQueue();
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

DataType Queue::DeQueue() {
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