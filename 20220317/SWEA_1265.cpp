#include <iostream>

using namespace std;
int main()
{
    int T, N, P;
    int Q, R;
    long long answer;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        answer = 1;
        cin >> N >> P;
        Q = N / P;
        R = N % P;
        
        for (int i = 0; i < P - R; i++)
        {
            answer *= Q;
        }
        while (R--)
        {
            answer *= (Q + 1);
        }
        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}