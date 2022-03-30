// 5611219	ksw1220	2112	정답!	1,456 KB	11 ms	CPP	635 B	2022-03-30 16:20:26
#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int main()
{
    int N;
    cin >> N;
    if (N % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        dp.assign(31, 0);
        dp[1] = 0;
        dp[2] = 3;
        dp[3] = 2;
        for (int i = 4; i <= N; i++)
        {
            if (i % 2 == 0)
            {
                dp[i] = dp[i - 1] + dp[i - 2] * 3;
            }
            else
            {
                dp[i] = dp[i - 2] + dp[i - 3] * 2;
            }
        }
    }

    cout << dp[N] << endl;
    return 0;
}