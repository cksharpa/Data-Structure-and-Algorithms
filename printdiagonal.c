#include<stdio.h>
#include<stdlib.h>

#define ROW 5
#define COL 4

void diagonalorder(int mat[][COL])
{
    for()
}

void printmatrix(int mat[ROW][COL])
{
    for (int i=0;i<ROW;i++)
    {
        for(int j=0; j<COL;j++)
            printf("%5d "mat[i][j]);
        printf("\n");
    }
}
int main()
{
    int a[ROW][COL] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16},
                        {17,18,19,20},

                        };

    printf("Given matrix is \n");
    printmatrix(a);
    printf("\n Diagonal printing of matrix is \n");
    diagonalorder(a);
    return 0;


}
