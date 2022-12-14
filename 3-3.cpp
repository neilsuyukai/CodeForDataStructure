#include <stdio.h>
#include <iostream>
using namespace std;
int stack[20];
int top = -1;

void push(int num)
{
    stack[++top] = num;
}
void pop(int& num)
{
    num = stack[top--];
}
int Transfer(char postfix[])
{
    for (int i = 0; i < 20; i++)
    {
        if (postfix[i] >= 48 && postfix[i] <= 57)
        {
            push(int(postfix[i] - 48));
        }
        else if (postfix[i] >= 40 && postfix[i] <= 47)
        {
            int num1, num2;
            pop(num2);
            pop(num1);
            switch (postfix[i])
            {
            case '+':
                push(num1 + num2);
                break;
            case '-':
                push(num1 - num2);
                break;
            case '*':
                push(num1 * num2);
                break;
            case '/':
                push(num1 / num2);
                break;

            }
        }
        else {
            return stack[0];
        }
    }
}

int main(int argc, char* argv[]) {
    char itemset[20];
    scanf("%s", itemset);
    cout << Transfer(itemset) << endl;
}