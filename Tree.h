#ifndef TREE_H_
#define TREE_H_
#include"bits/stdc++.h"
using namespace std;

struct Node {
	char value;
	int weight;
	Node * left= NULL;
	Node * right= NULL;
	Node * parent = NULL;
	char edge; //'0' for left child , '1' for right child
};

class Tree {
private :
	Node *root;
	void shuffling(Node* tree);
	Node * nytParent(Node * tree)const;
	int calculateWeight(Node* tree);

public:
	Tree();
	Node* insert(char c);
    Node * getRoot()const;
    Node * search(char ch , Node * tree)const;
    string binaryCode(char ch, Node * tree)const;
    Node * findByBinaryCode(string str)const;
    void display(Node* tree)const;
	void printWeight(Node * tree)const;
	virtual ~Tree();
};


#endif /* TREE_H_ */
