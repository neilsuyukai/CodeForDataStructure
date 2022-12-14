#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    float A[5];
    float average=0;
    int Score[4][5];
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            cin >> Score[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            average=average+Score[j][i];
        }
        average=average/4;
        A[i]=average;
        average=0;
    }
    for(int i=0;i<5;i++){
        cout<<A[i]<<" ";
    }
}