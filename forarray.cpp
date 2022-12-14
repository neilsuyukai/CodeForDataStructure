#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    int sum=0;
    int Score[6];
    for (int i = 0; i < 6; i++){
        cin >> Score[i];
        sum+=Score[i];
    }
    cout<<sum;
}