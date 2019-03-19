/***
 * @author Vladimir Shubarin.
 * @date 19.03.19
 * @file lab1_2.cpp
 * @brief I DONT KNOW WHAT THE FUCK TO DO
*/

#include <cstdlib>
#include <iostream>

using namespace std;

typedef int DataType;

class Queue {
    struct element {
        DataType data;
        element *next; ///< IDK what this var does
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
    int DeQueue(); ///<извлечение элемента из очереди
};


void clearBuff() {
    cin.clear();    // Restore input stream to working state
    cin.ignore(100, '\n');    // Get rid of any garbage that user might have entered}
}

int main(int argc, char *argv[]) {
    char menu = '0';
    Queue q;
    int i = 0;
    while (menu != '4') {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Посчитать diff" << endl;
        cout << "3. Show" << endl;
        cout << "4. Quit" << endl;
        cin >> menu;
        clearBuff();
        switch (menu) {
            case '1':
                system("clear");
                q.EnQueue(i);
                i++;
                break;
            case '2':
                system("clear");
                throw;
                break;
            case '3':
                system("clear");
                throw;
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
    front = front->next;
    delete tmp;
    return temp;
}
