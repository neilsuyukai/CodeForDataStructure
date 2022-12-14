#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(int argc,char* argv[])
{
    cin>>argc;
    int N;
    int array[argc]={};
    for(int i=0;i<argc;i++){
        cin>>N;
        array[i]=N;
    }   
    for(int j=argc-1;j>=0;j++){
        cout<<array[j]<<" ";
    }
    return 0;
}