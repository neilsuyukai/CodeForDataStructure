#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    int Array_Data[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> Array_Data[i][j];

    // ~ write here ~ //
    
    int Array_Ans[15] = {};
    int sum=0;
    for(int i=0;i<5;i++){
        for(int j=i;j<5;j++){
            Array_Ans[sum]=Array_Data[i][j];
            sum++;
        }
    }
    for (int i = 0; i < 15; i++)
        cout << Array_Ans[i] << " ";
}