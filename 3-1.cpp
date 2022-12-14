#include <iostream>
using namespace std;

class Stack
{
    public:
    Stack()
    {
        capacity=0;
        array=new int[10];
        top=-1;
    }
    void Push(int x)
    {
        array[++top]=x;
    }
    void Pop()
    {
        top--;
    }
    void PrintStack()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<array[i]<<" ";
        }
    }
    private:
     int capacity;
     int* array;
     int top;

};
int main(int argc, char* argv[]) {
    Stack stack;
    int times, input;
    cin >> times;
    for (int i = 0; i < times; i++) {
        cin >> input;
        stack.Push(input);
    }
    cin >> times;
    for (int i = 0; i < times; i++) {
        stack.Pop();
    }
    stack.PrintStack();
}