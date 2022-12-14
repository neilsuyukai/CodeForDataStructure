#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    float A[4];
    float average=0;
    int Score[4][5];
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            
            cin >> Score[i][j];
            average+=Score[i][j];
        }
        average=average/5.0;
        A[i]=average;
        average=0;
        
    }
    for(int i=0;i<4;i++){
        cout<<A[i]<<" ";
    }
}