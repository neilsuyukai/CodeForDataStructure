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
        cout<<endl;
    }
    void Reverse(){
        ListNode* l=NULL;
        ListNode* m=first;
        ListNode* r=m->link;
        while(l!=last){
            m->link=l;
            l=m;
            m=r;
            if(r->link!=NULL)
                r=r->link;
        }
        first=l;

    }
private:
    ListNode* first;
    ListNode* last;

};
class Stack:public LinkedList{
    public:
    void Push(int x){
        InsertFirst(x);
    }
    void Pop(){
        DeleteFirst();
    }
    void PrintStack(){
        Reverse();
        PrintList();
    }
};
int main(int argc, char* argv[]) {
    Stack stack;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        stack.Push(input);
    }
    for (cin >> times; times > 0; times--)
        stack.Pop();
    stack.PrintStack();
}