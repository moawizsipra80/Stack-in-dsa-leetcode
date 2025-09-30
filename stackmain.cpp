#include "stack.h"
#include <iostream>
#include <cmath>
using namespace std;
int precedence(char c)
{
    int n;
    if (c == '(' || c == ')')
    {
        n = 0;
        return n;
    }
    else if (c == '+' || c == '-')
    {
        n = 1;
        return n;
    }
    else if (c == '*' || c == '/')
    {
        n = 2;
        return n;
    }
    else if (c == '^')
    {
        n = 3;
        return n;
    }

    else
    {
        return -1; // invalid case
    }
}
int size;
string postfix;
void evaluatepostfix(string exp)
{
    size = exp.length();
    // stack<char> postfix(size);//isko change kia ha main na
    postfix = "";
    stack<char> operands(size);
    char *c = new char[size];
    for (int i = 0; i < size; i++)
    {
        c[i] = exp[i];
        if (isdigit(c[i]))
        {
            // int n = c[i] - '0';//digit conversion byuild karonga  num*10+digit
            // postfix.push(n);
            postfix += c[i];
        }
        else if (c[i] == '(')
        {

            operands.push(c[i]);
        }
        else if (c[i] == ')')
        {
            while (operands.stacktop() != '(')
            {
                postfix += operands.pop();
            }

            operands.pop();
        }
        else
        {
            // if (precedence(c[i])>precedence(operands.stacktop())){
            //     operands.push(c[i]);

            // }
            while (!operands.isEmpty() && precedence(c[i]) < precedence(operands.stacktop()))
            {
                // postfix.push(operands.pop());
                postfix += operands.pop();
            }
            operands.push(c[i]);
        }
    }
    while (!operands.isEmpty())
    {
        // postfix.push(operands.pop());
        postfix += operands.pop();
    }
    // postfix.display();
}
void calculation()
{
    stack<int> cal(size);
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            int n = ch - '0';
            cal.push(n);
        }
        else
        {
            int a = cal.pop();
            int b = cal.pop();
            switch (ch)
            {
            case '+':
                cal.push(a + b);
                break;
            case '-':
                cal.push(b - a);
                break;
            case '*':
                cal.push(a * b);
                break;
            case '/':
                cal.push(b / a);
                break;
            case '^':
                cal.push(pow(b, a));
                break;
            }
        }
    }
    cout << "the result is " << cal.pop() << endl;
}
bool isValid(string exp)
{
    int size = exp.length();
    int start = 0;
    int end = exp[size - 1];
    while (start < end)
    {
        if (exp[start] == '[')
        {
            for (int i = end; i > 0; i++)
            {
                if (exp[i] == ')' || exp[i] == '}')
                {
                    return false;
                }
            }
        }
            else if (exp[start] == '{')
            {
                for (int i = end; i > 0; i--)
                {
                    if (exp[end] == ']' || exp[end] == ')')
                    {
                        return false;

                    }
                }
            }
            else if (exp[start] == '{')
            {
                for (int i = end; i > 0; i--)
                {
                    if (exp[end] == ']' || exp[end] == ')')
                    {
                        return false;
                    }
                }
            }
             else if (exp[start] == '(')
            {
                for (int i = end; i > 0; i--)
                {
                    if (exp[end] == ']' || exp[end] == '}')
                    {
                        return false;
                      
                    }
                }
            }

            start++;
            end--;
        }
    }

    int main()
    {

        int n1;
        cout << "enter the space you want to allocate for stack " << endl;
        cin >> n1;
        stack<int> s(n1);
        s.push(10);
        s.push(20);
        s.push(30);

        cout << "Top element: " << s.stacktop() << endl;

        s.display();

        s.pop();
        cout << "After pop, new top: " << s.stacktop() << endl;
        //
        string exp;
        cout << "enter the equation" << endl;
        cin >> exp;
        evaluatepostfix(exp);
        calculation();
        //
        return 0;
    }
