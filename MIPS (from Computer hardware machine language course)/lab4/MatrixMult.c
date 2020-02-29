
#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **arr = (int **)malloc(size * sizeof(int *));
	for(int i = 0; i < size; i++){
		*(arr + i) = (int *)malloc(size * sizeof(int*));
		for(int j = 0; j < size; j++){
			*(*(arr + i) + j) = 0;
			for(int k = 0; k < size; k++){
				*(*(arr + i) + j) += (*(*(a + i) + k) * (*(*(b + k) + j)));
			}
		}
	}
	return arr;
	free(arr);
}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d\t", *(*(arr + i) + j));
		}printf("\n");
	}

}

int main() {
	int n = 3;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
	matA = (int **)malloc(n * sizeof(int*));
	matB = (int **)malloc(n * sizeof(int*));	//creating space for these arrays
	matC = (int **)malloc(n * sizeof(int*));

	for(int i = 0; i < n; i++){
		*(matA + i) = (int *)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			*(*(matA + i) + j) = 0;	//fix this
		}
	}

	for(int i = 0; i < n; i++){
		*(matB + i) = (int *)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			*(*(matB + i) + j) = 0;	//fix this
		}
	}

	for(int i = 0; i < n; i++){
		*(matC + i) = (int *)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++){
			*(*(matC + i) + j) = 0;	//fix this
		}
	}
	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printArray(matB, n);
	
	//(5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);
	
	//(6) Call printArray to print out resulting array here.
	printArray(matC, n);


    return 0;
}