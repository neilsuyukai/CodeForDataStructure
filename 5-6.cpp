#include <iostream>
using namespace std;

class ListNode {
   public:
    ListNode(int a, int b) {
        coef = a;
        exp = b;
        link = 0;
    }

   private:
    int coef;
    int exp;
    ListNode* link;
    friend class PolyList;
};

class PolyList {
   public:
    void InsertLast(int, int);
    void Add(PolyList&);
    void PrintList();

   private:
    ListNode* first = 0;
    ListNode* last = 0;
};

void PolyList::InsertLast(int coef, int exp) {
    ListNode* newNode = new ListNode(coef, exp);
    if (last == 0)
        first = newNode;
    else
        last->link = newNode;
    last = newNode;
}

void PolyList::Add(PolyList& b) {
    // Write here
    ListNode* tempAFront=0;
    ListNode* tempA=first;
    ListNode* tempB=b.first;

    while(tempA!=0&&tempB!=0){
        if(tempA->exp>tempB->exp){
            tempAFront=tempA;
            tempA=tempA->link;
        }
        else if(tempA->exp<tempB->exp){
            ListNode* newNode=new ListNode(tempB->coef,tempB->exp);
            if(tempA==first){
                newNode->link=first;
                first=newNode;
                tempAFront=newNode;
            }
             else{
            
            newNode->link=tempA;
            tempAFront->link=newNode;
        }
        tempB=tempB->link;
        }
        else{
        tempA->coef+=tempB->coef;
        if(tempA->coef==0){
            if(tempA==first)first=first->link;
            else tempAFront=tempA;
        }
        else tempAFront=tempA;
         
         tempA=tempA->link;
         tempB=tempB->link;
    }
       
    }
    
    while(tempB!=0){
        InsertLast(tempB->coef,tempB->exp);
        tempB=tempB->link;
    }
}

void PolyList::PrintList() {
    // Write here
    if(first!=0){
        ListNode* temp=first;
        while(temp!=0){
            cout<<temp->coef<<"x^"<<temp->exp<<" ";
            temp=temp->link;
        }
    }
}

int main(int argc, char* argv[]) {
    PolyList A, B;
    int times, input, input2;
    for (cin >> times, times /= 2; times > 0; times--) {
        cin >> input >> input2;
        A.InsertLast(input, input2);
    }
    for (cin >> times, times /= 2; times > 0; times--) {
        cin >> input >> input2;
        B.InsertLast(input, input2);
    }
    A.Add(B);
    A.PrintList();
}