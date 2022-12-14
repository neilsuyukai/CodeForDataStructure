#include <iostream>
using namespace std;
int main(int argc,char* argv[])
{
    int Array_Data[3][5];
    for(int i=0;i<3;i++)
        for(int j=0;j<5;j++)
            cin>>Array_Data[i][j];
    int Array_Ans[15];
    
    int n;
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            n=i+j*3;
            Array_Ans[n]=Array_Data[i][j];
        }
    }
    for(int i=0;i<15;i++){
        cout<<Array_Ans[i]<<" ";
    }
    return 0;
}
//columns