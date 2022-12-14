#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==0)
    return 1;
    else
    return 3*fact(n-1);
}