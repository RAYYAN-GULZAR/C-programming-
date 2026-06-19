#include <stdio.h>
#include "calculator.h"

void trace(int n, int m, int arr[n][m])
{
    if (n != m)
    {
        printf("Trace only exists for a square matrix.\n");
    }
    else
    {
        int tr = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(i == j)
                    tr += arr[i][j];
            }
        }
        printf("The trace of given matrix is %d\n", tr);
    }
}

void transpose(int n, int m, int arr[n][m])
{
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void determinant(int n, int m, int arr[n][m])
{
    if(m != n)
        printf("Determinant only exists for a square matrix. Please enter a square matrix.\n");
    else if(n > 3 || m > 3)
        printf("Please enter a matrix of order 1, 2 or 3.\n");
    else
    {
        if(m == 1 && n == 1)
            printf("%d\n", arr[0][0]);
        else if(m == 2 && n == 2)
            printf("%d\n", arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0]);
        else if(m == 3 && n == 3)
        {
            printf("The determinant of given matrix is %d\n", arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1]) - arr[0][1]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0]) + arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]));
        }
    }
}

void scalar(int x, int n, int m, int arr[n][m])
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
            printf("%d\t", arr[i][j] * x );
        printf("\n");
    }
}

void row_sum(int y, int n, int m, int arr[n][m])
{
    int index = y - 1; // Adjusts to 0-based indexing for the user
    if (index < n && index >= 0)
    {
        int sum = 0;
        for(int j = 0; j < m; j++)
        {
            sum += arr[index][j];
        }
        printf("The sum of row %d is: %d\n", y, sum);
    }
    else
        printf("Please enter a valid row.\n");
}

void column_sum(int y, int n, int m, int arr[n][m])
{
    int index = y - 1; // Adjusts to 0-based indexing for the user
    if (index < m && index >= 0)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i][index];
        }
        printf("The sum of column %d is: %d\n", y, sum);
    }
    else
        printf("Please enter a valid column.\n");
}

void symmetric(int n, int m, int arr[n][m])
{
    int flag = 0;
    if (n != m)
        printf("The given matrix is not square and hence not symmetric.\n");
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(flag == 1) break;
            for(int j = i; j < n; j++)
            {
                if(arr[i][j] != arr[j][i])
                {
                    flag = 1;
                    printf("The given matrix is not symmetric.\n");
                    break;
                }
            }
        }
        if(flag == 0)
            printf("The given matrix is symmetric.\n");
    }
}

void skew(int n, int m, int arr[n][m])
{
    int flag = 0;
    if (n != m)
        printf("The given matrix is not square and hence not skew symmetric.\n");
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(flag == 1) break;
            for(int j = i; j < n; j++)
            {
                if(arr[i][j] != -arr[j][i])
                {
                    flag = 1;
                    printf("The given matrix is not skew symmetric.\n");
                    break;
                }
            }
        }
        if(flag == 0)
            printf("The given matrix is skew symmetric.\n");
    }
}

void addition(int n, int m, int arr[n][m], int k, int l, int array[k][l])
{
    if(n != k || m != l)
        printf("Addition is not possible as the matrices are of different order.\n");
    else
    {
        printf("The sum of the two matrices is: \n");
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                printf("%d\t", arr[i][j] + array[i][j]);
            }
            printf("\n");
        }
    }
}

void subtraction(int n, int m, int arr[n][m], int k, int l, int array[k][l])
{
    if(n != k || m != l)
        printf("Subtraction is not possible as the matrices are of different order.\n");
    else
    {
        printf("The difference of the two matrices is: \n");
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                printf("%d\t", arr[i][j] - array[i][j]);
            }
            printf("\n");
        }
    }
}

void multiplication(int n, int m, int arr[n][m], int k, int l, int array[k][l])
{
    if(m != k)
        printf("Multiplication is not possible as the number of columns of first matrix is not equal to the number of rows of second matrix.");
    else
    {
        printf("The product of the two matrices is: \n");
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<l;j++)
            {
                int sum = 0;
                for(int p = 0;p<m;p++)
                {
                    sum += arr[i][p] * array[p][j];
                }
                printf("%d\t", sum);
            }
            printf("\n");
        }
    }
}
void equality(int n, int m, int arr[n][m], int k, int l, int array[k][l])
{
    if(n != k || m != l)
        printf("The matrices are not equal as they are of different order.\n");
    else
    {
        int flag = 0;
        for(int i = 0;i<n;i++)
        {
            if(flag == 1) break;
            for(int j = 0;j<m;j++)
            {
                if(arr[i][j] != array[i][j])
                {
                    flag = 1;
                    printf("The matrices are not equal.\n");
                    break;
                }
            }
        }
        if(flag == 0)
            printf("The matrices are equal.\n");
    }
}
void identity(int n, int m, int arr[n][m])
{ 
    int flag = 0;
    if(m!=n)
        printf("The given matrix is not a identity matrix.\n");
    else
    {
        for(int i = 0;i<n;i++)
        {
            if(flag == 1) break;
            for(int j = 0;j<m;j++)
            {
                if(i == j)
                {
                    if(arr[i][j] != 1 )
                        {
                            flag = 1;
                            break;
                        }
                }
                else
                {
                    if(arr[i][j] != 0)
                        {
                            flag = 1;
                            break;
                        }
                }
            }
        }
        if(flag == 0)
            printf("The given matrix is an identity matrix.\n");
        else
            printf("The given matrix is not an identity matrix.\n");
    }
}
void power(int k, int n, int m, int arr[n][m])
{
    if (n != m)
    {
        printf("Matrix power is only defined for square matrices.\n");
        return;
    }
    
    if (k < 0)
    {
        printf("Negative powers are not supported. Please enter a positive power.\n");
        return;
    }

    if (k == 0)
    {
        printf("The matrix raised to the power %d is:\n", k);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    printf("%d\t", 1);
                else
                    printf("%d\t", 0);
            }
            printf("\n");
        }
        return;
    }

    int matrix[n][m];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }

    for(int p = 0; p < k; p++)
    {
        int result[n][m];
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int sum = 0;
                for(int q = 0; q < m; q++)
                {
                    sum += matrix[i][q] * arr[q][j];
                }
                result[i][j] = sum;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                matrix[i][j] = result[i][j];
            }
        }
    }

    printf("The matrix raised to the power %d is:\n", k);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
