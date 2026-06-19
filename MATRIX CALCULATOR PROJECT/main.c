#include <stdio.h>
#include "calculator.h"

int main()
{
    while(1)
    {
        int n, m;
        printf("\n====================================\n");
        printf("         MATRIX CALCULATOR          \n");
        printf("====================================\n\n");

        do {
            printf("Enter no of rows of matrix (must be > 0): ");
            scanf("%d", &n);
            printf("Enter no of columns of matrix (must be > 0): ");
            scanf("%d", &m);
            if (n <= 0 || m <= 0)
             printf("Error: Dimensions must be 1 or greater.\n\n");
        } while (n <= 0 || m <= 0);

        int arr[n][m];
        printf("\nEnter the elements of the matrix:\n");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                printf("Element [%d][%d]: ", i, j);
                scanf("%d", &arr[i][j]);
            }
        }

        printf("\nThe entered matrix is:\n");
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }

        int x, y;
        printf("\n------------------------------------\n");
        printf("1. Perform operations on THIS matrix\n");
        printf("2. Perform operations on TWO matrices\n");
        printf("Choose an option (1 or 2): ");
        scanf("%d", &x);

        if(x == 1)
        {
            printf("\n--- Single Matrix Operations ---\n");
            printf("1. Trace\n");
            printf("2. Transpose\n");
            printf("3. Determinant\n");
            printf("4. Scalar Multiplication\n");
            printf("5. Row sum\n");
            printf("6. Column sum\n");
            printf("7. Check for symmetric matrix\n");
            printf("8. Check for skew symmetric matrix\n");
            printf("9. Check for identity matrix\n");
            printf("10. Power of matrix\n");
            printf("Enter choice: ");

            int choice;
            scanf("%d", &choice);
            printf("\n");

            switch(choice)
            {
                case 1: trace(n, m, arr); break;
                case 2: transpose(n, m, arr); break;
                case 3: determinant(n, m, arr); break;
                case 4:
                    printf("Enter the scalar multiplier: ");
                    scanf("%d", &y);
                    scalar(y, n, m, arr);
                    break;
                case 5:
                    printf("Which row do you want to sum? ");
                    scanf("%d", &y);
                    row_sum(y, n, m, arr);
                    break;
                case 6:
                    printf("Which column do you want to sum? ");
                    scanf("%d", &y);
                    column_sum(y, n, m, arr);
                    break;
                case 7: symmetric(n, m, arr); break;
                case 8: skew(n, m, arr); break;
                case 9: identity(n, m, arr); break;
                case 10:
                    do {
                        printf("Enter the power to which you want to raise the matrix (must be >= 0): ");
                        scanf("%d", &y);
                        if (y < 0)
                            printf("Error: Power must be non-negative.\n");
                    } while (y < 0);
                    power(y, n, m, arr);
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        }
        else if(x == 2)
        {
            int k, l;
            printf("\n--- Second Matrix Setup ---\n");
            do {
                printf("Enter no of rows of 2nd matrix (must be > 0): ");
                scanf("%d", &k);
                printf("Enter no of columns of 2nd matrix (must be > 0): ");
                scanf("%d", &l);
                if (k <= 0 || l <= 0) printf("Error: Dimensions must be 1 or greater.\n\n");
            } while (k <= 0 || l <= 0);

            int array[k][l];
            printf("\nEnter the elements of the 2nd matrix:\n");
            for(int i = 0; i < k; i++)
            {
                for(int j = 0; j < l; j++)
                {
                    printf("Element [%d][%d]: ", i, j);
                    scanf("%d", &array[i][j]);
                }
            }

            printf("\nThe second matrix is:\n");
            for(int i = 0; i < k; i++)
            {
                for(int j = 0; j < l; j++)
                {
                    printf("%d\t", array[i][j]);
                }
                printf("\n");
            }

            int choice;
            printf("\n--- Two Matrix Operations ---\n");
            printf("1. Addition\n");
            printf("2. Subtraction\n");
            printf("3. Multiplication\n");
            printf("4. Equality Check\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            printf("\n");

            switch(choice)
            {
                case 1: addition(n, m, arr, k, l, array); break;
                case 2: subtraction(n, m, arr, k, l, array); break;
                case 3: multiplication(n, m, arr, k, l, array); break;
                case 4: equality(n, m, arr, k, l, array); break;
                default:
                    printf("Invalid choice.\n");
            }
        }
        else
        {
            printf("\nPlease Enter a valid command.\n");
        }

        char a;
        printf("\n------------------------------------\n");
        printf("Press 'c' to continue or 'e' to exit: ");
        scanf(" %c", &a);
        if(a == 'e' || a == 'E')
        {
            printf("Exiting the program.\n");
            break;
        }
        else if(a != 'c' && a != 'C')
        {
            printf("Invalid input. Exiting the program.\n");
            break;
        }
    }
    return 0;
}
