//
// Created by vhundef on 12.05.19.
//

#ifndef UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_TREE_NODE_H
#define UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_TREE_NODE_H


template <class NodeType> class TreeNode {
protected:
	TreeNode *left,*right,*parent;
public:
	TreeNode(NodeType dt) {
		data=dt;
		left=right= nullptr;
	}

	TreeNode *getLeft() const {
		return left;
	}

	void setLeft(TreeNode *lft) {
		TreeNode::left = lft;
	}

	TreeNode *getRight() const {
		return right;
	}

	void setRight(TreeNode *rght) {
		TreeNode::right = rght;
	}

	TreeNode *getParent() const {
		return parent;
	}

	void setParent(TreeNode *prnt) {
		TreeNode::parent = prnt;
	}

	NodeType getData() const {
		return data;
	}

	void setData(NodeType dt) {
		TreeNode::data = dt;
	}

protected:
	NodeType data; // Ключ

};


#endif //UNIVERSITY_DATA_ORGANISATION_AND_STUCTURES_TREE_NODE_H
