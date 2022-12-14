#include <iostream>
using namespace std;
#define n 10;
class Queue
{
private:
    int arr[10] = {};
    int rear = 0;
    int front = 0;
public:
    Queue()
    {
        int arr[10];
        int rear = 0;
        int front = 0;
    }
    void Enqueue(int x)
    {
        rear = (rear + 1) % n;
        arr[rear] = x;
    }
    int Dequeue()
    {
        front = (front + 1) % n;
        return arr[front];
    }
    void PrintQueue()
    {
        for (int i = (front + 1) % 10; i != rear + 1; i = (i + 1) % 10)
        {
            cout << arr[i] << " ";

        }
        cout << "rear:" << rear << " " << "front:" << front;
    }
    void BackEnqueue(int x)
    {
        if (!(rear == front)) {
            arr[front] = x;
            front = (front + 9) % 10;
        }
    }
    int BackDequeue()
    {
        rear = (rear + 9) % 10;
        if (!(front == rear)) {
            return arr[rear];
        }
    }


};
int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;
    cin >> times;
    for (int j = 0; j < times; j++) {
        cin >> input;
        queue.Enqueue(input);
    }
    cin >> times;
    for (int j = 0; j < times; j++) {
        queue.Dequeue();
    }
    cin >> times;
    for (int j = 0; j < times; j++) {
        cin >> input;
        queue.BackEnqueue(input);
    }
    cin >> times;
    for (int j = 0; j < times; j++) {
        queue.BackDequeue();
    }
    queue.PrintQueue();
}
