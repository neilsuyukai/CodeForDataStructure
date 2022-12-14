#include <iostream>
#define n 10;
using namespace std;
class Queue
{
    public:
    Queue()
    {
        int rear=0;
        int front=0;
    }
    void Enqueue(int x){
        rear=(rear+1)%n;
        arr[rear]=x;
    }
    int Dequeue(){
        front=(front+1)%n;
        return arr[front];
    }
    void PrintQueue(){
        for(int i=(front+1)%10;i!=rear+1;i=(i+1)%10){
            cout<<arr[i]<<" ";
        }
        cout<<"rear: "<<rear<<" "<<"front: "<<front;
    }
    
    private:
    int arr[10]={};
    int rear=0;
    int front=0;

};

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;
    for (int i = 0; i < 2; i++) {
        cin >> times;
        for (int j = 0; j < times; j++) {
            cin >> input;
            queue.Enqueue(input);
        }
        cin >> times;
        for (int j = 0; j < times; j++) {
            queue.Dequeue();
        }
    }
    queue.PrintQueue();
}