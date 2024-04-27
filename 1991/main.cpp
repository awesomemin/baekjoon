#include <iostream>
#include <map>
using namespace std;

int N;

map<char, struct node> nodes;

struct node {
	char data;
	char lchild = '.';
	char rchild = '.';
};


void preOrder(char node) {
	if(node == '.') return;
	cout<<node;
	preOrder(nodes[node].lchild);
	preOrder(nodes[node].rchild);
}

void inOrder(char node) {
	if(node == '.') return;
	inOrder(nodes[node].lchild);
	cout<<node;
	inOrder(nodes[node].rchild);
}

void postOrder(char node) {
	if(node == '.') return;
	postOrder(nodes[node].lchild);
	postOrder(nodes[node].rchild);
	cout<<node;
}

int main(void) {
	cin>>N;
	for(int i = 0; i < N; i++) {
		char parent, lchild, rchild;
		cin>>parent>>lchild>>rchild;
		struct node newNode;
		newNode.data = parent;
		newNode.lchild = lchild;
		newNode.rchild = rchild;
		nodes.insert({newNode.data, newNode});
		//cout<<nodes[parent]->data<<" "<<nodes[parent]->lchild<<" "<<nodes[parent]->rchild<<endl;
	}
	
	// for(auto iter = nodes.begin(); iter != nodes.end(); iter++) {
	// 	cout<<iter->second.data<<endl;
	// }
	
	preOrder('A');
	cout<<endl;
	inOrder('A');
	cout<<endl;
	postOrder('A');
	cout<<endl;
	
	return 0;
}