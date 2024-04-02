#include <iostream>
using namespace std;

int main(void) {
	int N; cin>>N;
	int ** graph = new int * [N];
	for(int i = 0; i < N; i++) {
		graph[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin>>graph[i][j];
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(graph[i][j] == 1) {
				for(int k = 0; k < N; k++) {
					if(graph[j][k] == 1) {
						graph[i][k] = 1;
					}
				}
			}
		}
	}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if(graph[i][j] == 1) {
				for(int k = 0; k < N; k++) {
					if(graph[j][k] == 1) {
						graph[i][k] = 1;
					}
				}
			}
		}
	}
	
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	for(int i = 0; i < N; i++) {
		delete[] graph[i];
	}
	delete[] graph;
	
	return 0;
}