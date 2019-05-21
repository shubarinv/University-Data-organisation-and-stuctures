//
// Created by vhundef on 12.05.19.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_TREE_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_TREE_H

#include <iostream>
#include "tree_node.h"

using namespace std;

template<class NodeType>
class Tree {
private:
	TreeNode<NodeType> *root; //Корень
public:
	Tree();

	int insert_node(const NodeType &);

	TreeNode<NodeType> *delete_node(TreeNode<NodeType> *);

	void inorder_walk(TreeNode<NodeType> *);

	TreeNode<NodeType> *find_min(TreeNode<NodeType> *);

	TreeNode<NodeType> *find_max(TreeNode<NodeType> *);

	TreeNode<NodeType> *find_node(TreeNode<NodeType> *,const NodeType &);

	TreeNode<NodeType> *find_succsessor(const NodeType &);

	TreeNode<NodeType> *get_root();

};

template<class NodeType>
Tree<NodeType>::Tree() {
	root = 0;
}

template<class NodeType>
int Tree<NodeType>::insert_node(const NodeType &x) {

	auto *nw = new TreeNode<NodeType>(x); // Новый узел
	TreeNode<NodeType> *ptr = nullptr, *ptr1 = nullptr;

	nw->setParent(nullptr);
	nw->setLeft(nullptr);
	nw->setRight(nullptr);

	ptr = root;
	while (ptr != 0) { /// Starting from root, trying to find place for a new element
		ptr1 = ptr; /// Will be parent
		if (x < ptr->getData()) /// Value on the left is less then the val. of parent
			ptr = ptr->getLeft();
		else
			ptr = ptr->getRight();
	}
	nw->setParent(ptr1);
	if (ptr1 == nullptr) /// Tree was empty
		root = nw;
	else {
		if (x < ptr1->getData())
			ptr1->setLeft(nw);
		else
			ptr1->setRight(nw);
	}
	return 0;
}


template<class NodeType>
TreeNode<NodeType> *Tree<NodeType>::delete_node(TreeNode<NodeType> *z) {
	TreeNode<NodeType> *y;
	TreeNode<NodeType> *x;
	if (z->getLeft() == nullptr || z->getRight() ==
	                               nullptr) ///< в этой и следующих двух строках ищем вершину y, которую мы потом вырежем из дерева. Это либо z, либо следующий за z
		y = z;
	else
		y = find_succsessor(z->getData());
	if (y->getLeft() != nullptr) ///< x - указатель на существующего ребенка y или Null если таковых нет
		x = y->getLeft();
	else
		x = y->getRight();
	if (x != 0) ///< эта и следующие 9 строк - вырезание y
		x->setParent(y->getParent());
	if (y->getParent() == 0)
		root = x;
	else {
		if (y == (y->getParent())->getLeft())
			(y->getParent())->setLeft(x);
		else
			(y->getParent())->setRight(x);
	}
	if (y != z) /// если мы вырезали вершину, отличную от z, то ее данные перемещаем в z
		z->setData(y->getData());
	return y;
}

template<class NodeType>
TreeNode<NodeType> *Tree<NodeType>::find_max(TreeNode<NodeType> *x) {
	while (x->getRight() != 0)  /// здесь все очевидно - самое максимальное значение у самого правого
		x = x->getRight();
	return x;
}

template<class NodeType>
TreeNode<NodeType> *Tree<NodeType>::find_min(TreeNode<NodeType> *x) {
	while (x->getLeft() != 0)
		x = x->getLeft();
	return x;
}

template<class NodeType>
TreeNode<NodeType> *Tree<NodeType>::find_succsessor(const NodeType &val) {
	TreeNode<NodeType> *x = find_node(root, val);                     /// получим указатель на узел с ключем val
	TreeNode<NodeType> *y;
	if (x == 0)
		return 0;
	if (x->getRight() !=0)  /// если у нее есть правые дети, то следующий элемент - минимальный в правом поддереве
		return find_min(x->getRight());
	y = x->getParent();
	while (y != 0 &&
	       x == y->getRight()) ///иначе - идем вверх и ищем первый элемент, являющийся левым потомком своего родителя
	{
		x = y;
		y = y->getParent();
	}
	return y;
}


template<class NodeType>
void Tree<NodeType>::inorder_walk(TreeNode<NodeType> *n) {
	if (n != nullptr) {

		inorder_walk(n->getLeft());
		cout << n->getData() << endl;
		inorder_walk(n->getRight());
	}
}

template<class NodeType>
TreeNode<NodeType> *Tree<NodeType>::find_node(TreeNode<NodeType> *n,const NodeType &val) {
	if (n == 0 || val == n->getData())
		return n;
	if (val > n->getData())
		return find_node(n->getRight(), val);
	else
		return find_node(n->getLeft(), val);
}

template<class NodeType>
TreeNode<NodeType> *Tree<NodeType>::get_root() {
	return root;
}

#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_TREE_H
