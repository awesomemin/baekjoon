#include <stdio.h>

int main() {
	int E = 1;
	int S = 1;
	int M = 1;
	
	int E_result;
	int S_result;
	int M_result;
	
	int OurWordYear = 1;
	
	scanf("%d %d %d", &E_result, &S_result, &M_result);
	while(1) {
		if(E == E_result && S == S_result && M == M_result) {
			break;
		}
		
		E++; S++; M++;
		if(E == 16) {
			E = 1;
		}
		if(S == 29) {
			S = 1;
		}
		if(M == 20) {
			M = 1;
		}
		
		OurWordYear++;
	}
	
	printf("%d\n", OurWordYear);
	
	return 0;
}