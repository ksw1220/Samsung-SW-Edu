// 5611023	ksw1220	2191	정답!	5,408 KB	7 ms	CPP	851 B	2022-03-30 15:26:44
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp;
int main()
{
    int aLen, bLen;
    string a, b;
    cin >> aLen >> a;
    cin >> bLen >> b;

    dp.assign(aLen + 1, vector<int>(bLen + 1, 0));

    for (int i = 1; i <= aLen; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= bLen; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= aLen; i++)
    {
        for (int j = 1; j <= bLen; j++)
        {
            // 문자열은 0~aLen 0~bLen까지 이므로 -1을 하여 비교
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
    }
    cout << dp[aLen][bLen] << endl;
    return 0;
}