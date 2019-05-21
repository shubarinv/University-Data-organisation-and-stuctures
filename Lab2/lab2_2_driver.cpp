//
// Created by vhundef on 12.05.19.
//

#include "Lab2_2/tree.h"

using namespace std;

// Did I snatch this code from the Internet? -Well, https://www.youtube.com/watch?v=7uTFsn7na3A

int main() {
	Tree<int> intTree;           /* создаем новое бинароное дерево с ключем типа int */
	Tree<int> intTree1;
	int a;
	cout << "10 numbers:" << endl;   /* заполняем его */
	for (int i = 0; i < 10; i++) {
		cin >> a;
		intTree.insert_node(a);
	}
	cout << endl << "inorder_walk:" << endl;              /* обходим */
	intTree.inorder_walk(intTree.get_root());       /* вот для этого понадобился метод get_root() :-) */
	cout << endl << "Minimum is: " << (intTree.find_min(intTree.get_root()))->getData() << endl;
	cout << endl << "Maximum is: " << (intTree.find_max(intTree.get_root()))->getData() << endl;
	cout << "Enter node value U want to delete:";     /* попробуем удалить узел с ключем a */
	cin >> a;
	intTree.delete_node(intTree.find_node(intTree.get_root(), a));    // если их несколько, то удалится первый найденный
	cout << endl << "Now inorder_walk:" << endl;
	intTree.inorder_walk(intTree.get_root());       /* посмотрим на результат */


	intTree1=intTree;
	intTree1.inorder_walk(intTree1.get_root());
}
