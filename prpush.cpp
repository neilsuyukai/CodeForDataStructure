#include <stdio.h>
#include <iostream>
using namespace std;

int top=-1;
char Stack[20];

int Priority(char op)
{
    switch(op)
    {
        case '+': case '-':
            return 1;
            break;
        case '*': case '/':
            return 2;
            break;
        default:
            return 0;
    }
}

void InfixToPostfix(char infix[])
{
    char op;
    for(int i=0;i<infix[i]!= '\0';i++)
    {
        switch(op)
        {
            case '(':
                Stack[top++]=op;
                break;
            case ')':
                while(Stack[top]!= '(')
                    cout<<Stack[top--];
                    top--;
            case '+': case '-': case '*': case '/':
            while(Priority(op)<=Priority(Stack[top]))
                cout<<Stack[top--];
                Stack[top++]=op;
                break;
            default:
                cout<<op;
        }
    }
    while(top!=-1)
    {
        cout<<Stack[top--];
        cout<<endl;
    }
}
int main(int argc, char* argv[]) {
    char itemset[20];
    cin>>("%s", itemset);
    InfixToPostfix(itemset);
}