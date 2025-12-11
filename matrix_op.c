#include <stdio.h>
#include "matrix_op.h"

//Addition
void mat_add(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[i][j] = A[i][j] + B[i][j];
}

//Subtraction
void mat_sub(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[i][j] = A[i][j] - B[i][j];
}

//Element-wise Multiplication
void mat_elem_mult(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[i][j] = A[i][j] * B[i][j];
}

//Matrix Multiplication
void mat_mult(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            R[i][j] = 0;
            for(int k=0;k<SIZE;k++)
                R[i][j] += A[i][k] * B[k][j];
        }
    }
}

//Transpose
void mat_transpose(int A[SIZE][SIZE], int R[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            R[j][i] = A[i][j];
}
