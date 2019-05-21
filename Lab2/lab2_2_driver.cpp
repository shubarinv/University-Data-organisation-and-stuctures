//
// Created by vhundef on 12.05.19.
//

#include "Lab2_2/tree.h"

using namespace std;

// Did I snatch this code from the Internet? -Well, https://www.youtube.com/watch?v=7uTFsn7na3A

void clearBuff() { ///< @brief Чистит буфер
	cin.clear();    // Restore input stream to working state
	cin.ignore(1000, '\n');    // Get rid of any garbage that user might have entered}
}

double validInput()
{
	double x;
	cin >> x;
	while(cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Шо за фигня?  Введите ЧИСЛО: ";
		cin >> x;
	}
	return x;
}

int main() {
	Tree<double> dbTree;           /* создаем новое бинароное дерево с ключем типа int */
	Tree<double> dbTree1;
	double a;
	cout << "10 numbers:" << endl;   /* заполняем его */
	for (int i = 0; i < 10; i++) {
		a=validInput();
		clearBuff();
		dbTree.insert_node(a);
	}
	cout << endl << "inorder_walk:" << endl;              /* обходим */
	dbTree.inorder_walk(dbTree.get_root());       /* вот для этого понадобился метод get_root() :-) */
	cout << endl << "Minimum is: " << (dbTree.find_min(dbTree.get_root()))->getData() << endl;
	cout << endl << "Maximum is: " << (dbTree.find_max(dbTree.get_root()))->getData() << endl;
	cout<<"Введите число, которое вы хотите удалить: ";
	a=validInput();
	while(dbTree.delete_node(dbTree.find_node(dbTree.get_root(), a))== nullptr){ // если их несколько, то удалится первый найденный
		cout<<"Введите число, которое вы хотите удалить"<<endl;
		a=validInput();
	}
	cout << endl << "Now inorder_walk:" << endl;
	dbTree.inorder_walk(dbTree.get_root());       /* посмотрим на результат */


	dbTree1=dbTree;
	dbTree1.inorder_walk(dbTree1.get_root());
}
