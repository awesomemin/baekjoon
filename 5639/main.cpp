#include <iostream>
using namespace std;

typedef struct node {
	int data;
	struct node * lchild = NULL;
	struct node * rchild = NULL;
} Node;

Node * rootNode;

void makeTree(Node * parentNode, Node * newNode) {
	if(parentNode->data < newNode->data) {
		if(parentNode->rchild == NULL) {
			parentNode->rchild = newNode;
		} else {
			makeTree(parentNode->rchild, newNode);
		}
	}
	
	if(parentNode->data > newNode->data) {
		if(parentNode->lchild == NULL) {
			parentNode->lchild = newNode;
		} else {
			makeTree(parentNode->lchild, newNode);
		}
	}
}

void postOrder(Node * n) {
	if(n->lchild != NULL)
		postOrder(n->lchild);
	if(n->rchild != NULL)
		postOrder(n->rchild);
	cout<<n->data<<'\n';
}

int main(void) {
	while(!cin.eof()) {
		int d; cin>>d;
		Node * newNode = new Node;
		newNode->data = d;
		if(rootNode == NULL) {
			rootNode = newNode;
		} else {
			makeTree(rootNode, newNode);
		}
	}
	
	postOrder(rootNode);
	
	return 0;
}