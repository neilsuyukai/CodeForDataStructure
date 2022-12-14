#include <iostream>
using namespace std;

const int rows = 4;
const int columns = 4;

void matrix_init(int arr[][columns]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> arr[i][j];
}
void matrix_transpose(int arr[][columns],int brr[][columns]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            brr[j][i]=arr[i][j];
        }
    }
}
void matrix_print(int brr[][columns]){
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            cout<<brr[i][j]<<" ";
        }
    }
}
int main(int argc, char* argv[]) {
    int A[rows][columns];
    int B[4][4];
    matrix_init(A);
    matrix_transpose(A,B);
    matrix_print(B);
}