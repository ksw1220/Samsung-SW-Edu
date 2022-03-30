// 5611107	ksw1220	1278	정답!	15,512 KB	16 ms	CPP	839 B	2022-03-30 15:53:34
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> weight, price;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, W;
    cin >> N >> W;

    weight.resize(N + 1);
    price.resize(N + 1);
    dp.assign(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i] >> price[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j >= weight[i])
            {
                dp[i][j] = max(dp[i - 1][j - weight[i]] + price[i], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][W] << endl;
    return 0;
}