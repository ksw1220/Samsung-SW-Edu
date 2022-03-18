#include <iostream>
#include <stack>
using namespace std;

stack<char> st;
int main()
{
    int testCase, N;
    string password, answer;
    for (testCase = 1; testCase <= 10; testCase++)
    {
        cin >> N >> password;
        answer = "";
        for (int i = 0; i < N; i++)
        {
            if (!st.empty() && st.top() == password[i])
            {
                st.pop();
            }
            else
            {
                st.push(password[i]);
            }
        }

        while (!st.empty())
        {
            answer = st.top() + answer;
            st.pop();
        }

        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}