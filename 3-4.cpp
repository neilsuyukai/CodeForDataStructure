#include <stdio.h>
#include <iostream>
using namespace std;
char stack[20];
char back[20];
int  nStack[20];
int top = -1;
int ntop = -1;
int back_index = 0;



void push(char c)
{
    stack[++top] = c;
}
void pop(char& chr)
{
    chr = stack[top--];
}
void push2(int num)
{
    nStack[++ntop] = num;
}
void pop2(int &num)
{
    num = nStack[ntop--];
}


int Priority(char op)
{
    if (op == '*' || op == '/')return 2;
    if (op == '+' || op == '-')return 1;
}

void InfixToPostfix(char infix[])
{
    bool hat = false;
    for (int i = 0; i < 20; i++)
    {
        if (infix[i] >= 48 && infix[i] <= 57)
        {
            back[back_index] = infix[i];
            back_index++;
        }
        else if (infix[i] >= 40 && infix[i] <= 47)
        {
            if (infix[i] == '(')
            {
                push(infix[i]);
                hat = true;
            }
            else if (top == -1 || stack[top] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                char print_sym;
                while (hat)
                {
                    pop(print_sym);
                    if (print_sym != '(')
                    {
                        back[back_index] = print_sym;
                        back_index++;
                    }
                    else
                    {
                        hat = false;
                    }
                }
            }
            else
            {
                bool run = false;
                int now = Priority(infix[i]);
                while (!run)
                {
                    char print_sym;
                    int before = Priority(stack[top]);
                    if (before >= now && stack[top] != '(')
                    {
                        pop(print_sym);
                        back[back_index] = print_sym;
                        back_index++;
                    }
                    else
                    {
                        push(infix[i]);
                        run = true;
                    }
                }
            }
        }
        else
        {
            while (top != -1)
            {
                char print_sym;
                pop(print_sym);
                back[back_index] = print_sym;
                back_index++;
            }
            break;
        }
    }
}
int Transfer(char infix[])
{
    for (int i = 0; i < 20; i++)
    {
        if (infix[i] >= 48 && infix[i] <= 57)
        {
            push2(int(infix[i] - 48));
        }
        else if (infix[i] >= 40 && infix[i] <= 47)
        {
            int num1, num2;
            pop2(num2);
            pop2(num1);
            switch (infix[i])
            {
            case '+':
                push2(num1 + num2);
                break;
            case '-':
                push2(num1 - num2);
                break;
            case '*':
                push2(num1 * num2);
                break;
            case '/':
                push2(num1 / num2);
                break;

            }
        }
        else {
            return nStack[0];
        }
    }
}
int Eval(char infix[])
{
    InfixToPostfix(infix);
    return Transfer(back);
}
int main(int argc, char* argv[]) {
    char itemset[20];
    cin >> ("%s", itemset);
    cout << Eval(itemset) << endl;
}