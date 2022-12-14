#include <iostream>
using namespace std;
class ListNode {
public:
    ListNode(int a) {
        data = a;
        link = 0;
    }

private:
    int data;
    ListNode* link;
    friend class LinkedList;
};
class LinkedList
{
public:
    LinkedList()
    {
        first = NULL;
        last = NULL;
    }
    void InsertFirst(int x)
    {
        ListNode* newNode = new ListNode(x);
        newNode->link = first;
        first = newNode;

        if (last == NULL) last = first;
    }
    void InsertLast(int x)
    {
        ListNode* newNode = new ListNode(x);
        last->link=newNode;
        last = newNode;

        if (first == NULL) first = last;
    }
    int DeleteFirst()
    {
        int x = first->data;
        first = first->link;
        return x;

    }
    int DeleteLast()
    {
        int x;
        ListNode* temp = first;
        while (temp != NULL) {
            if (temp->link == last)break;
            temp = temp->link;
        }
        x = last->data;
        last = temp;
        last->link = NULL;
        return x;
    }
    void PrintList()
    {
        ListNode* temp = first;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }

private:
    ListNode* first;
    ListNode* last;

};
class Queue:public LinkedList
{
    public:
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
    int arr[10]={};
    int rear=-1;
    int front=-1;

};
    

int main(int argc, char* argv[]) {
    Queue queue;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        queue.Enqueue(input);
    }
    for (cin >> times; times > 0; times--)
        queue.Dequeue();
    queue.PrintQueue();
}