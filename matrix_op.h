#ifndef MATRIX_OP_H
#define MATRIX_OP_H
#define SIZE 3

void mat_add(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void mat_sub(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void mat_elem_mult(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);

void mat_mult(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void mat_transpose(int A[SIZE][SIZE], int R[SIZE][SIZE]);

int mat_det(int A[SIZE][SIZE]);
void mat_adjoint(int A[SIZE][SIZE], int Adj[SIZE][SIZE]);

int mat_inverse(int A[SIZE][SIZE], float Inv[SIZE][SIZE]);

void mat_print_int(int A[SIZE][SIZE]);
void mat_print_float(float A[SIZE][SIZE]);

#endif
