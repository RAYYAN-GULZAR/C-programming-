#ifndef CALCULATOR_H
#define CALCULATOR_H

void trace(int n, int m, int arr[n][m]);
void transpose(int n, int m, int arr[n][m]);
void determinant(int n, int m, int arr[n][m]);
void scalar(int x, int n, int m, int arr[n][m]);
void row_sum(int y, int n, int m, int arr[n][m]);
void column_sum(int y, int n, int m, int arr[n][m]);
void symmetric(int n, int m, int arr[n][m]);
void skew(int n, int m, int arr[n][m]);
void addition(int n, int m, int arr[n][m], int k, int l, int array[k][l]);
void subtraction(int n, int m, int arr[n][m], int k, int l, int array[k][l]);
void multiplication(int n, int m, int arr[n][m], int k, int l, int array[k][l]);
void equality(int n, int m, int arr[n][m], int k, int l, int array[k][l]);
void identity(int n, int m, int arr[n][m]);
void power(int k, int n, int m, int arr[n][m]);
#endif // CALCULATOR_H
