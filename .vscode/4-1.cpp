#include <iostream>
using namespace std;
class Queue
{
    public:
    Queue()
    {
        int rear=-1;
        int front=-1;
    }
    void Enqueue(int x)
    {
        array[++rear]=x;
    }
    int Dequeue()
    {
        return array[++front];
    }
    void PrintQueue()
    {
        for(int i = front + 1; i <=rear ; i++)
        {
            cout<<array[i]<<" ";
        }
    }
    private:
    int array[10]={};
    int rear=-1;
    int front=-1;

};

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for (int i = 0; i < times; i++) {
        queue.Dequeue();
    }
    queue.PrintQueue();
}
/*#inclide <iostream>
using namespace std;
int main(int agrgv, char* argv[]){
    Queue queue;
    int times,input;
    cin>>times;
    for(int i=0;i<times;i++){
        cin>>input;
        queue.Enqueue(input);
    }
    cin>>times;
    for(int i=0;i<times;i++){
        queue.Dequeue();
    }
    queue.PrintQueue();
}
{
    
}*/