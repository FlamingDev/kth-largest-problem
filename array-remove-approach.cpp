#include <iostream>
using namespace std;

// Solução 1: Localizando o maior elemento e removendo-o. Repetir por k vezes. 
// Complexidade T(n) = k*2n = O(kn) S(n) = 0 = O(1)

int remove(int* A, int n, int i){
	int temp = A[i];
	for (; i < n; i++){
		A[i] = A[i+1];
	}
	return temp;
}

int largest(int* A, int n){
	int large = A[0];
	int large_pos = 0;
	
	for (int i = 0; i < n; i++){
		if (A[i] > large){
			large = A[i];
			large_pos = i;
		}
	}
	return large_pos;
}

int kth_largest(int* A, int n, int k){
	int max;
	for (int i = 0; i < k; i++){
		int max_pos = largest(A, n);
		max = remove(A, n, max_pos);	
	}
	return max;
}

int main(){
	int A[] = {5,7,3,4,32,9};
	
	cout << kth_largest(A,6,3);
}
