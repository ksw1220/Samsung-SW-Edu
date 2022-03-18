#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int testCase, N, answer;
    string str;
    for (testCase = 1; testCase <= 10; testCase++)
    {
        stack<char> st;
        cin >> N >> str;
        answer = 1;
        for (int i = 0; i < N; i++)
        {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<')
            {
                st.push(str[i]);
            }
            else if (str[i] == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    answer = 0;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else if (str[i] == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    answer = 0;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else if (str[i] == '}')
            {
                if (st.empty() || st.top() != '{')
                {
                    answer = 0;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
            else if (str[i] == '>')
            {
                if (st.empty() || st.top() != '<')
                {
                    answer = 0;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }

        if (!st.empty())
        {
            answer = 0;
        }
        
        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}