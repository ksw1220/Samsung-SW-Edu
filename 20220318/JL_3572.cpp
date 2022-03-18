#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> op;
int main()
{
    string exp, answer;
    cin >> exp;

    int len = exp.length();

    for (int i = 0; i < len; i++)
    {
        if (exp[i] == '+' || exp[i] == '-')
        {
            while (!op.empty())
            {
                answer += op.top();
                op.pop();
            }
            op.push(exp[i]);
        }
        else if (exp[i] == '*' || exp[i] == '/')
        {
            while (!op.empty() && op.top() != '+' && op.top() != '-')
            {
                answer += op.top();
                op.pop();
            }
            op.push(exp[i]);
        }
        else
        {
            answer += exp[i];
        }
    }
    while (!op.empty())
    {
        answer += op.top();
        op.pop();
    }
    cout << answer << endl;
    return 0;
}