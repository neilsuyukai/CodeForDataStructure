#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(int argc,char* argv[])
{
    cin>>argc;
    int sum,N;
    for(int i=0;i<argc;i++){
        cin>>N;
        sum=sum+N;
    }
    int average;
    average=sum/argc;
    if(average>=60){
        cout<<"pass!";
    }
    else {
        cout<<" no pass!";
    }
    return 0;
}