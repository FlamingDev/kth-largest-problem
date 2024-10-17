#include <iostream>
inline int left_child(int i) {return 2*i + 1;}
inline int right_child(int i){return 2*i + 2;}
inline int parent(int i) {return i%2==0? i/2 - 1 : i/2;}
using namespace std;

// Solu��o 2: Inserindo os n elementos em um max-heap e removendo-os k vezes, o que dar� o k-�simo maior elemento
// Complexidade T(n) = n + (k-1)*logn = n + klogn - logn = O(n + klogn)

void max_heapify(int *A, int heap_size, int i);
void build_max_heap(int *A, int heap_size);
int heap_extract(int* heap, int n);
int kth_largest(int* A, int n, int k);
void swap(int *a, int *b);

int main(){
	int A[] = {3,2,1,5,6,7};
	cout << kth_largest(A,7,3);
}

int kth_largest(int* A, int n, int k){
	build_max_heap(A,n);
	
	for (; k > 1; k--){
		heap_extract(A,n); // extrai o maior elemento k-1 vezes
	}
	return A[0]; 
}

int heap_extract(int *heap, int n){
	int last = heap[n-1];
	int i = 0; // apontador para a raiz
	int temp = heap[0]; // o ultimo elemento ir� assumir a ra�z inicialmente
	heap[0] = last; // deletando a ra�z
	max_heapify(heap,n-1,0);
	return temp;
}

// buildmaxheap come�a do ultimo n� n�o folha e transforma em heap todos antes dele, que tamb�m n�o s�o folha
// aproveitando do fato de que todos os n�s folha j� s�o max heap
void build_max_heap(int *A, int heap_size){
	for (int i = parent(heap_size-1); i >= 0; i--){ // i come�a apontando pro pai do �ltimo n�
		max_heapify(A,heap_size,i); // transforma em heap aquele n� do �ndice i
	}
}

void max_heapify(int *A, int heap_size, int i){
	int largest = i; // assume que aquela �rvore j� � maxheap
	int l = left_child(i); // calculando �ndice do filho esquerdo se ele existir
	int r = right_child(i); // calculando indice do filho direito se ele existir
	
	if (l < heap_size && A[l] > A[largest]){ // se left estiver no heap e for maior que o pai
		largest = l;
	}
	if (r < heap_size && A[r] > A[largest]){ // se right estiver no heap e for maior que o largest
		largest = r;
	}
		
	if (A[largest] != A[i]){ // se largest for diferente do pai,troca suas p�si��es e ajusta o ponteiro pra baixo na �rvore (filho esquerdo ou direito)
		swap(&A[largest],&A[i]);
		max_heapify(A,heap_size,largest); // heapifica pra baixo onde largest est�
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
