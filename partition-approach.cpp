#include <iostream>
using namespace std;

/* Solu��o 3: Usando o m�todo partition, o que vai permitir chegar a O(n)
 * o m�todo partition ir� escolher um pivot qualquer na esperan�a de ser um
 * pivot bem no meio do array. Tendo a posi��o do pivot n�s limitamos o espa�o
 * de busca do k-�simo maior elemento em apenas metade do array, no caso m�dio.
 *
 * A solu��o decorre do fato de que tendo um elemento arbitr�rio do array
 * em sua posi��o ordenada revela se o k-�simo maior elemento est� na se��o
 * da esquerda ou da direita, ou � o pr�prio pivot.
 */

int kth_largest(int* A, int l, int h, int k);
int partition(int* A, int l, int h);
int swap(int* a, int* b);

int main(){
	int A[] = {7,2,3,5,1};
	
	cout << kth_largest(A,0,4,2);
}

int kth_largest(int* A, int l, int h, int k){
	int pivot_pos = partition(A,l,h); // encontra a posi��o ordenada de um elemento arbitr�rio
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
