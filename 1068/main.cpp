#include <iostream>
#include <vector>
using namespace std;

int N;
int deleteNodeNum;
vector<int> tree[50];

void searchTree(int nodeNum, int &reafNodeNum) {
	if(nodeNum == deleteNodeNum) return;
	int childNum = tree[nodeNum].size();
	if(childNum == 0) {
		reafNodeNum++;
		return;
	}
	for(int i = 0; i < childNum; i++) {
		if(tree[nodeNum][i] == deleteNodeNum) {
			if(childNum == 1) reafNodeNum++;
			continue;
		}
		searchTree(tree[nodeNum][i], reafNodeNum);
	}
	return;
}

int main(void) {
	cin>>N;
	int rootNodeNum;
	int reafNodeNum = 0;
	for(int i = 0; i < N; i++) {
		int parentNum; cin>>parentNum;
		if(parentNum == -1) {
			rootNodeNum = i;
		}
		tree[parentNum].push_back(i);
	}
	
	cin>>deleteNodeNum;
	
	// for(int i = 0; i < N; i++) {
	// 	cout<<"ChildrenOfNode"<<i<<" : ";
	// 	for(int children : tree[i]) {
	// 		cout<<children<<" ";
	// 	}
	// 	cout<<endl;
	// }
	
	searchTree(rootNodeNum, reafNodeNum);
	cout<<reafNodeNum<<endl;
	
	return 0;
}