#include <iostream>
using namespace std;
class Queue
{
public:
    Queue()
    {
     
        int rear = -1;
        int front = -1;
    }
    void Enqueue(int x)
    {
        arr[++rear] = x;
    }
    int Dequeue()
    {
         return arr[++front];
    }
    void PrintQueue()
    {
        for (int i = front + 1; i <=rear ; i++)
        {
            cout << arr[i] << " ";
        }
    }

private:
    int arr[10] = {};
    int rear = -1;
    int front = -1;
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