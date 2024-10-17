#include <iostream>
using namespace std;

/* Solução 3: Usando o método partition, o que vai permitir chegar a O(n)
 * o método partition irá escolher um pivot qualquer na esperança de ser um
 * pivot bem no meio do array. Tendo a posição do pivot nós limitamos o espaço
 * de busca do k-ésimo maior elemento em apenas metade do array, no caso médio.
 *
 * A solução decorre do fato de que tendo um elemento arbitrário do array
 * em sua posição ordenada revela se o k-ésimo maior elemento está na seção
 * da esquerda ou da direita, ou é o próprio pivot.
 */

int kth_largest(int* A, int l, int h, int k);
int partition(int* A, int l, int h);
int swap(int* a, int* b);

int main(){
	int A[] = {7,2,3,5,1};
	
	cout << kth_largest(A,0,4,2);
}

int kth_largest(int* A, int l, int h, int k){
	int pivot_pos = partition(A,l,h); // encontra a posição ordenada de um elemento arbitrário
	static int n = h+1; // tamanho do array
	if (pivot_pos == n-k){ 
		return A[pivot_pos];
	}
	else if(pivot_pos > n-k){
		return kth_largest(A,l,pivot_pos-1,k);
	}
	else{
		return kth_largest(A,pivot_pos+1,h,k);
	}
}

int partition(int* A, int l, int h){
	int pivot = A[h];
	int i = l-1;
	
	for (int j = l; j < h; j++){
		if (A[j] < pivot){
			i++;
			swap(&A[i],&A[j]);
		}
	}
	swap(&A[i+1],&A[h]);
	return i+1;
}

int swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
