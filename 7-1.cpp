#include <iostream>
using namespace std;
int i,N,E;
int *V;
int ** G;

void DFS(int i)
{
    int j;
    V[i]=1;
    cout<<i+1<<" ";
    for(int j=0;j<N;j++){
        if(G[i][j]==1)
            if(V[j]!=1)
            DFS(j);
    }
}
int main(int argc, char *argv[])
{
	cin>>i>>N>>E;
	
	V=new int [N];
	G=new int *[N];
	for(int k=0;k<N;k++){
	    G[k]=new int [N];
	}
	
	for(int k=0;k<N;k++){
	    for(int j=0;j<N;j++){
	        G[k][j]=0;
	    }
	}
	
	for(int k=0;k<E;k++){
	    int n1,n2;
	    cin>>n1>>n2;
	    G[n1-1][n2-1]=1;
	    G[n2-1][n1-1]=1;

	}
	DFS(i-1);
}