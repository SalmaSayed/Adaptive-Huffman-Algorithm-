#include"Tree.h"
Tree::Tree() {

	root = new Node;
    root->value =1; //nyt

}
Node * Tree:: getRoot()const{
	return root;
}
Node* Tree ::insert(char ch){

	Node * node = search(ch, root);

	if (node != NULL){  // the symbol already transmitted/inserted to the array before
		node->weight= (node->weight)+1;
		calculateWeight(root);
		shuffling(root);
		return node;
	} else {
		Node * newNode = new Node;     //linking node
		Node * newCharNode = new Node; //node to hold symbol
			   newCharNode->value= ch;
			   newCharNode->weight=1;
			   newCharNode->edge= '1';

		Node * NYT = new Node; //nyt to be inserted
			NYT->value=1;
			NYT->weight=0;
			NYT->edge='0';

		if (root->value == 1){ // first time to insert in the tree
			root->value = 0;
			root->right= newCharNode;
			root->left=NYT; //nyt

			NYT->parent = root; //****
			newCharNode->parent= root;

		}else{
		Node * NYTParent = nytParent(root);
		newNode->edge= (NYTParent->left)->edge; // new node takes the edge of previous NYT

		NYTParent->left= newNode;

		newNode->right = newCharNode;
		newNode->left= NYT;

		newNode->parent= NYTParent;
		newCharNode->parent= newNode;
		NYT->parent= newNode;

		}
		calculateWeight(root);
		shuffling(root);

		return newCharNode;
	}
}

Node * Tree :: search(char ch , Node * tree)const{ //Working iSA

if (tree->right==NULL&&tree->right==NULL){ //reached external node
	if (tree->value==ch) return tree;
	else return NULL;
}

	Node * res = search(ch, tree->right);
	if (res!=NULL) return res;///if search in right branch returned null , don't consider it and invoke left branch
	res = search(ch, tree->left);
	return res;   /// return result anyway

}

string reverseStr(string str){  // reverse 0101 to 1010
	string res="";
	for(int i=str.length()-1; i>=0; i--){
		res+=str[i];
	}
	return res;
}


string Tree:: binaryCode(char ch , Node * tree)const{
	/* finds the char in the tree
	 * backward till the root, concatenating the edges to form the code
	 * */

	string str="";
		Node* currNode = search(ch, root);
		while (currNode!=root){
			str+= currNode->edge;
			currNode= currNode->parent;
		}
		return reverseStr(str);
}

Node* Tree:: findByBinaryCode(string str)const{
	Node * node= root;

	for (int i = 0; i<(int)str.length(); i++){
		if (str[i]=='0') node=node->left;

		else node = node->right;
	}
	return node;
}
int Tree::calculateWeight(Node* tree){ // Working
	if(tree->left==NULL && tree->right==NULL)return tree->weight ;
	tree->weight= calculateWeight(tree->left) + calculateWeight(tree->right);
	return tree->weight;

}
void Tree :: shuffling(Node* tree){ //  working iSA
	if (tree->left==NULL && tree->right==NULL) return ;
	if ((int)(tree->left->weight) > (int)(tree->right->weight)) {
		//swap
		Node * temp = tree->left;
		tree->left= tree->right;
		tree->right= temp;

		tree->left->edge='0';
		tree->right->edge='1';

	}
	shuffling(tree->left);
	shuffling(tree->right);
}

void Tree::display(Node* tree)const{
	if (tree->right==NULL && tree->left==NULL){
		cout << "char :" << tree->value << "\t weight : "<< tree->weight
				<<"\t edge: " << tree->edge<<endl;


	}
	else {
		display(tree->right);
		display(tree->left);
	}
}
void Tree:: printWeight(Node * tree)const{

	if (tree==NULL) return;
	cout << tree->weight <<endl;
	printWeight(tree->left);
	printWeight(tree->right);

}
Node * Tree:: nytParent(Node * tree)const{
	if (tree->left->value == 1 ) return tree;
		else {
		if (tree->left->left)  return nytParent(tree->left);
		if (tree->right->left) return nytParent(tree->right);
		}
}
Tree::~Tree() {
	// TODO Auto-generated destructor stub
}

