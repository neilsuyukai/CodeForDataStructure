#include <iostream>
using namespace std;
int N;
int * V;
int ** G;
int * queue;
int front=-1,rear=-1;
void BFS(int i){
    
    V[i]=1;
    cout<<i+1<<" ";
    for(int j=0;j<N;j++){
        if(G[i][j]==1){
            if(V[j]!=1){
                if(rear==N+1){
                    cout<<endl;
                    cout<<"full"<<endl;
                }
                else{
                    queue[++rear]=j;
                }
            }
        }
    }
    while(front!=rear){
        int k;
        if(rear==front){
            cout<<endl;
                cout<<"empty"<<endl;
        }
        else{
            k=queue[++front];
        }
        
        if(V[k]!=1)BFS(k);
    }
}
int main(int argc, char *argv[])
{
    int i,E;
	cin>>i>>N>>E;
	queue = new int[N+1];
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
	BFS(i-1);
}