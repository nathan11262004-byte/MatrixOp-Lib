#include <stdio.h>
#include "matrix_op.h"

int main() {

    int A[3][3] = {
        { 1, 2, 3 },
        { 0, 1, 4 },
        { 5, 6, 0 }
    };

    int B[3][3] = {
        { -2, 1, 0 },
        {  3, 0, 1 },
        {  4,-1, 2 }
    };

    int R[3][3];
    float InvA[3][3];

    printf("Matrix A:\n");
    mat_print_int(A);
    printf("\n");

    printf("Matrix B:\n");
    mat_print_int(B);
    printf("\n");

    mat_add(A,B,R);
    printf("A + B:\n");
    mat_print_int(R);
    printf("\n");

    mat_sub(A,B,R);
    printf("A - B:\n");
    mat_print_int(R);
    printf("\n");

    mat_elem_mult(A,B,R);
    printf("A .* B:\n");
    mat_print_int(R);
    printf("\n");

    mat_mult(A,B,R);
    printf("A * B:\n");
    mat_print_int(R);
    printf("\n");

    mat_transpose(A,R);
    printf("A^T:\n");
    mat_print_int(R);
    printf("\n");

    printf("det(A) = %d\n\n", mat_det(A));

    int Adj[3][3];
    mat_adjoint(A, Adj);
    printf("adj(A):\n");
    mat_print_int(Adj);
    printf("\n");

    if(mat_inverse(A, InvA)) {
        printf("A^-1:\n");
        mat_print_float(InvA);
    } else {
        printf("A is singular. No inverse.\n");
    }

    return 0;
}
