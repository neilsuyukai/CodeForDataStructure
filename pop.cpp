#include <stdio.h>
#include <iostream>
using namespace std;

int stack[20];
int top=-1;

void push(int num){
    stack[++top]=num;
}

void pop(int &num){
    num=stack[top--];
}
int Transfer(char infix[]){
    for(int i=0;i<20;i++)
    {
        if(infix[i]>=48&&infix[i]<=57)
        {
            push(int(infix[i]-48));
        }
        else if(infix[i]>=40&&infix[i]<=47)
        {
            int num1,num2;
            pop(num2);
            pop(num1);
            switch(infix[i])
            {
                case '+':
                    push(num1+num2);
                    break;
                case '-':
                    push(num1-num2);
                    break;
                case '*':
                    push(num1*num2);
                    break;
                case '/':
                    push(num1/num2);
                    break;
            }
        }
        else 
        {
            return stack[0];
        }
    }
}


int main(int argc, char* argv[]) {
    char itemset[20];
    scanf("%s", itemset);
    cout<<Transfer(itemset)<<endl;
}