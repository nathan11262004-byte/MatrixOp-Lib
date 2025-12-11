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

//Determinant
int mat_det(int A[SIZE][SIZE]) {
    int a = A[0][0], b = A[0][1], c = A[0][2];
    int d = A[1][0], e = A[1][1], f = A[1][2];
    int g = A[2][0], h = A[2][1], i = A[2][2];

    return a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g);
}

//Cofactor(>>Adjoint)
void mat_cofactor(int A[SIZE][SIZE], int Cof[SIZE][SIZE]) {
    for(int r=0;r<SIZE;r++){
        for(int c=0;c<SIZE;c++){
            int m[4], idx = 0;
            for(int i=0;i<SIZE;i++){
                if(i==r) continue;
                for(int j=0;j<SIZE;j++){
                    if(j==c) continue;
                    m[idx++] = A[i][j];
                }
            }
            int det = m[0]*m[3] - m[1]*m[2];
            Cof[r][c] = ((r+c)%2==0 ? 1 : -1) * det;
        }
    }
}

//Adjoint Matrix
void mat_adjoint(int A[SIZE][SIZE], int Adj[SIZE][SIZE]) {
    int Cof[SIZE][SIZE];
    mat_cofactor(A, Cof);
    mat_transpose(Cof, Adj);
}

//Inverse
int mat_inverse(int A[SIZE][SIZE], float Inv[SIZE][SIZE]) {
    int det = mat_det(A);
    if(det == 0) return 0;

    int Adj[SIZE][SIZE];
    mat_adjoint(A, Adj);

    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            Inv[i][j] = (float)Adj[i][j] / det;

    return 1;
}

void mat_print_int(int A[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
            printf("%4d ", A[i][j]);
        printf("\n");
    }
}

void mat_print_float(float A[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++)
            printf("%8.3f ", A[i][j]);
        printf("\n");
    }
}
