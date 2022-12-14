#include <iostream>
using namespace std;

const int a_rows = 4;
const int a_columns = 3;
const int b_rows = 100;
const int b_columns = 3;

void compress_init(int a[][a_columns]) {
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < a_columns; j++)
            cin >> a[i][j];
}

void compress_process(int a[][a_columns], int b[][b_columns])
{
    b[0][0] = a_rows;
    b[0][1] = a_columns;
    int numTt = 0, k = 1;
    for (int i = 0; i < a_rows; i++)
        for (int j = 0; j < a_columns; j++)
            if (a[i][j] != 0)
            {
                numTt++;
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
    b[0][2] = numTt;
}
void compress_print(int b[][b_columns])
{
    int i, j;
    for (i = 0; i < b[0][2] + 1; i++)
        for (j = 0; j < a_columns; j++)
            cout << b[i][j] << " ";
}

int main(int argc, char *argv[])
{
    int A[a_rows][a_columns], B[b_rows][b_columns];
    compress_init(A);
    compress_process(A, B);
    compress_print(B);
}