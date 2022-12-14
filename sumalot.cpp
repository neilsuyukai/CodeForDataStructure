#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    int Score[3][4][5];
    for (int k = 0; k < 3; k++)
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 5; j++)
                cin >> Score[k][i][j];

  
    int stuScore[4]={0},subScore[5]={0};
    cout<<"同學總成績：";
    for (int i= 0; i < 3; i++){
        for (int j = 0; j< 4; j++){
            for (int k = 0; k< 5; k++){
                
                stuScore[j]=stuScore[j]+Score[i][j][k];
            }
        }
    }

    
    for(int i=0;i<4;i++){
        cout<<stuScore[i]<<' ';
    }
    cout<<"科目總成績：";
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<4;k++){
                subScore[j]=subScore[j]+Score[i][k][j];
            }
        }
    }
   
    
    for(int i=0;i<5;i++){
        cout<<subScore[i]<<' ';
    }
}