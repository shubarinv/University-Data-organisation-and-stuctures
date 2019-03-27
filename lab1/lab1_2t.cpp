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
    float coef; /* ����������� */
    int pwr; /* ������� */
};
void clearBuff() { ///< @brief ������ �����
    cin.clear();    // Restore input stream to working state
    cin.ignore(1000, '\n');    // Get rid of any garbage that user might have entered}
}
int main(int argc, char *argv[]) {

/* ����� ������� ����� ��������� ��������� */
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Queue<struct num> polynm;
    num polinom;
    num cplnm;

/* ���� */

    bool loop = true;
    while (loop) {
        system("cls");
        cout << "p(x)=C1*X^e1+C2*X^e2+...+Cn*X^en" << endl;
        cout << "e1>e2>...>en>=0" << endl;
        cout << "_____________________________" << endl;
        cout << "01: ������ ������� 1 " << endl;
        cout << "02: ������� ������� 1 " << endl;
        cout << "03: ������ ������� 2 " << endl;
        cout << "04: ������� ������� 2 " << endl;
        cout << "05: ��������� �������� ��������� 1 � 2 " << endl;
        cout << "00:�����" << endl;
        cout << endl;
        char k;
        cin >> k;
        switch (k) {
            case '0': /* ����� �� ���� "����" */
                loop = false;
                break;
            case '1':
                system("cls");
                if (polynm.Empty()) {
                    cout << "������� ������� 1 " << endl;
                    short n;
                    int t;
                    cout << "������� ���������� ���������: ";
                    cin >> n;
                    clearBuff();
                    while (n < 1) {
                        cout << "���������� ��������� �� ����� ���� ����� 1. ������� ���������� ���������: ";
                        cin >> n;
                        clearBuff();
                    }
                    cout << "������� �����������: ";
                    cin >> polinom.coef;
                    clearBuff();
                    while (polinom.coef == 0) {
                        cout << "��� ������������ �=0 ��������� �� ��������� ��������.������� ����������� x: ";
                        cin >> polinom.coef;
                        clearBuff();

                    }
                    cout << "������� �������: ";
                    cin >> polinom.pwr;
                    t = polinom.pwr;
                    polynm.EnQueue(polinom);
                    n--;
                    while (n > 0) {
                        if (t == 0) {
                            cout << "���� �� ����� ���� ���������, ��� ��� ������� ������ 0 �� ����� ������������."
                                 << endl;
                            break;
                        }
                        cout << "������� �����������: ";
                        cin >> polinom.coef;
                        clearBuff();
                        while (polinom.coef == 0) {
                            cout << "��� ������������ �=0 ��������� �� �����������������.������� ����������� x: ";
                            cin >> polinom.coef;
                            clearBuff();
                        }
                        cout << "������� �������: ";
                        cin >> polinom.pwr;
                        clearBuff();
                        while (polinom.pwr >= t || polinom.pwr < 0) {
                            cout << "������� ������ ���� ������ ����������, �� �� ������ 0.������� ������� y:";
                            cin >> polinom.pwr;
                            clearBuff();
                        }
                        t = polinom.pwr;
                        polynm.EnQueue(polinom);
                        n--;
                    }
                    cout << "������� 1 �����" << endl;
                } else
                    cout << "������� 1 ��� �����" << endl;
                /* �������� �������� */
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
                cout << "������� 1 ������" << endl;
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