#ifndef MATRIX_OP_H
#define MATRIX_OP_H
#define SIZE 3
typedef double Matrix[SIZE][SIZE];
#endif

void print_matrix(Matrix A);
void set_matrix_zero(Matrix C);

void add_matrices(const Matrix A, const Matrix B, Matrix C);

void subtract_matrices(const Matrix A, const Matrix B, Matrix C);

void transpose_matrix(const Matrix A, Matrix C);

void multiply_matrices(const Matrix A, const Matrix B, Matrix C);

void element_wise_multiply(const Matrix A, const Matrix B, Matrix C);

double calculate_determinant(const Matrix A);

void calculate_adjoint(const Matrix A, Matrix C);

int calculate_inverse(const Matrix A, Matrix C);
