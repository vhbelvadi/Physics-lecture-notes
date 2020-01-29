#include<stdio.h>

int main() {

    int matrixA[10][10], matrixB[10][10], matrixC[10][10] = {0};
    int rowsA, rowsB, colsA, colsB, i, j, k;
    
    // First, ask for number of rows and columns in the matrices
    printf("\n\nEnter the number of rows and columns in matrix A:\n");
    scanf("%d%d", &rowsA, &colsA);
    printf("\n\nEnter the number of rows and columns in matrix B:\n");
    scanf("%d%d", &rowsB, &colsB);

    // Handle error if columns in matrix A is not equal to rows in B
    while(colsA != rowsB) {
	printf("\n\nMatrix B (%dx%d) is incompatible with matrix A (%dx%d).\nPlease re-enter the number of rows and columns in matrix B:\n", rowsB, colsB, rowsA, colsA);
	scanf("%d%d", &rowsB, &colsB);
    }

    // Second, ask for elements of the matrices
    printf("\n\nEnter elements of matrix A as asked:\n");
    for(i = 0; i < rowsA; i++) {
	for(j = 0; j < colsA; j++) {
	    printf("Enter element A%d%d:\t", i, j);
	    scanf("%d", &matrixA[i][j]);
	}
    }
    printf("\n\nEnter elements of matrix B as asked:\n");
    for(i = 0; i < rowsB; i++) {
	for(j = 0; j < colsB; j++) {
	    printf("Enter element B%d%d:\t", i, j);
	    scanf("%d", &matrixB[i][j]);
	}
    }
    
    // Multiply the two matrices
    for(i = 0; i < rowsA; i++) {
	for(j = 0; j < colsB; j++) {
	    for(k = 0; k < colsA; k++) {
		matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
	    }
	}
    }

    // Output the result
    printf("\n\nThe product is:\n");
    for(int i = 0; i < rowsA; i++) {
	for(int j = 0; j < colsB; j++) {
	    printf("%d\t", matrixC[i][j]);
	    if(j == colsB - 1) {
		printf("\n");
	    }
	}
    }

    return 0;
}
