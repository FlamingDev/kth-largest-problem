#include <iostream>
inline int left_child(int i) {return 2*i + 1;}
inline int right_child(int i){return 2*i + 2;}
inline int parent(int i) {return i%2==0? i/2 - 1 : i/2;}
using namespace std;

// Solução 2: Inserindo os n elementos em um max-heap e removendo-os k vezes, o que dará o k-ésimo maior elemento
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
	int temp = heap[0]; // o ultimo elemento irá assumir a raíz inicialmente
	heap[0] = last; // deletando a raíz
	max_heapify(heap,n-1,0);
	return temp;
}

// buildmaxheap começa do ultimo nó não folha e transforma em heap todos antes dele, que também não são folha
// aproveitando do fato de que todos os nós folha já são max heap
void build_max_heap(int *A, int heap_size){
	for (int i = parent(heap_size-1); i >= 0; i--){ // i começa apontando pro pai do último nó
		max_heapify(A,heap_size,i); // transforma em heap aquele nó do índice i
	}
}

void max_heapify(int *A, int heap_size, int i){
	int largest = i; // assume que aquela árvore já é maxheap
	int l = left_child(i); // calculando índice do filho esquerdo se ele existir
	int r = right_child(i); // calculando indice do filho direito se ele existir
	
	if (l < heap_size && A[l] > A[largest]){ // se left estiver no heap e for maior que o pai
		largest = l;
	}
	if (r < heap_size && A[r] > A[largest]){ // se right estiver no heap e for maior que o largest
		largest = r;
	}
		
	if (A[largest] != A[i]){ // se largest for diferente do pai,troca suas pósições e ajusta o ponteiro pra baixo na árvore (filho esquerdo ou direito)
		swap(&A[largest],&A[i]);
		max_heapify(A,heap_size,largest); // heapifica pra baixo onde largest está
	}
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
