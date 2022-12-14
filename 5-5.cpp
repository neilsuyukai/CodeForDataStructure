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
    friend class CircularList;
};
class CircularList
{
    private:
    ListNode *last;
    public:
    CircularList(): last(NULL)
    {
        
    }
    void InsertFirst(int x)
    {
        ListNode* newNode=new ListNode(x);
        if(last==NULL){
            last=newNode;
            last->link=last;
        }
        else{
            ListNode* temp=last->link;
            last->link=newNode;
            newNode->link=temp;
        }
    }
    void InsertLast(int x)
    {
        ListNode *newNode=new ListNode(x);
        if(last==NULL){
            last=newNode;
            last->link=last;
        }
        else{
            ListNode* temp=last->link;
            last->link=newNode;
            newNode->link=temp;
            last=newNode;
        }
    }
    int DeleteFirst()
    {
        int x;
        if(last==NULL){
            return 0;
        }
        else if(last==last->link){
            x=last->data;
            last=NULL;
        }
        else{
            x=last->link->data;
            ListNode* temp=last->link;
            last->link=temp->link;
        }
        return x;
    }
    int DeleteLast()
    {
        int x;
        if(last==NULL){
            return 0;
        }
        else if(last==last->link){
            x=last->data;
            last=NULL;
        }
        else{
            x=last->data;
            ListNode* temp=last;
            while(temp->link!=last){
                temp=temp->link;
            }
            temp->link=last->link;
            last=temp;
        }
        return x;
    }
    void PrintList()
    {
        ListNode*temp=last->link;
        while(true){
            cout<<temp->data<<" ";
            if(temp==last)break;
            else temp=temp->link;
        }
    }
    
};
int main(int argc, char* argv[]) {
    CircularList list;
    int times, input;
    for (cin >> times; times > 0; times--) {
        cin >> input;
        list.InsertFirst(input);
    }
    for (cin >> times; times > 0; times--)
        list.DeleteFirst();
    for (cin >> times; times > 0; times--) {
        cin >> input;
        list.InsertLast(input);
    }
    for (cin >> times; times > 0; times--)
        list.DeleteLast();
    list.PrintList();
}