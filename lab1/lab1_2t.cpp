//
// Created by vhund on 27.03.2019.
//

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

#define LIST
#ifdef LIST

#include "lab1_2/polynomial_list.h"

#else
#include "lab1_2/polynomial_vector.h"
#endif

struct num {
    float coef; /* Коэффициент */
    int pwr; /* Степень */
};
void clearBuff() { ///< @brief Чистит буфер
    cin.clear();    // Restore input stream to working state
    cin.ignore(1000, '\n');    // Get rid of any garbage that user might have entered}
}
int main(int argc, char *argv[]) {

/* Чтобы русский текст выводился нормально */
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Queue<struct num> polynm;
    num polinom;
    num cplnm;

/* Меню */

    bool loop = true;
    while (loop) {
        system("cls");
        cout << "p(x)=C1*X^e1+C2*X^e2+...+Cn*X^en" << endl;
        cout << "e1>e2>...>en>=0" << endl;
        cout << "_____________________________" << endl;
        cout << "01: Задать полином 1 " << endl;
        cout << "02: Удалить полином 1 " << endl;
        cout << "03: Задать полином 2 " << endl;
        cout << "04: Удалить полином 2 " << endl;
        cout << "05: Посчитать разность полиномов 1 и 2 " << endl;
        cout << "00:Выход" << endl;
        cout << endl;
        char k;
        cin >> k;
        switch (k) {
            case '0': /* Выход из цика "Меню" */
                loop = false;
                break;
            case '1':
                system("cls");
                if (polynm.Empty()) {
                    cout << "Задайте полином 1 " << endl;
                    short n;
                    int t;
                    cout << "Введите количество элементов: ";
                    cin >> n;
                    clearBuff();
                    while (n < 1) {
                        cout << "Количество элементов не может быть менее 1. Введите количество элементов: ";
                        cin >> n;
                        clearBuff();
                    }
                    cout << "Введите коэффициент: ";
                    cin >> polinom.coef;
                    clearBuff();
                    while (polinom.coef == 0) {
                        cout << "При коэффициенте х=0 многочлен не будетсуще ствовать.Введите коэффициент x: ";
                        cin >> polinom.coef;
                        clearBuff();

                    }
                    cout << "Введите степень: ";
                    cin >> polinom.pwr;
                    t = polinom.pwr;
                    polynm.EnQueue(polinom);
                    n--;
                    while (n > 0) {
                        if (t == 0) {
                            cout << "Ввод не может быть продолжен, так как степень меньше 0 не может существовать."
                                 << endl;
                            break;
                        }
                        cout << "Введите коэффициент: ";
                        cin >> polinom.coef;
                        clearBuff();
                        while (polinom.coef == 0) {
                            cout << "При коэффициенте х=0 многочлен не будетсуществовать.Введите коэффициент x: ";
                            cin >> polinom.coef;
                            clearBuff();
                        }
                        cout << "Введите степень: ";
                        cin >> polinom.pwr;
                        clearBuff();
                        while (polinom.pwr >= t || polinom.pwr < 0) {
                            cout << "Степень должна быть меньше предыдущей, но не меньше 0.Введите степень y:";
                            cin >> polinom.pwr;
                            clearBuff();
                        }
                        t = polinom.pwr;
                        polynm.EnQueue(polinom);
                        n--;
                    }
                    cout << "Полином 1 задан" << endl;
                } else
                    cout << "Полином 1 уже задан" << endl;
                /* Просмотр полинома */
                if (!polynm.Empty())
                    do {
                        polinom = polynm.DeQueue();
                        cout << polinom.coef << " " << polinom.pwr << endl;
                        polynm.EnQueue(polinom);
                        cplnm = polynm.Front();
                    } while (cplnm.pwr < polinom.pwr);

                break;
            case '2':
                system("cls");
                polynm.~Queue();
                cout << "Полином 1 очищен" << endl;
                break;
            case '3':
                throw;
                break;
            case '4':
                throw;
                break;
            case '5':
                throw;
                break;
        }
    }
    return 0;
}