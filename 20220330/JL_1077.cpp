// 5611099	ksw1220	1077	정답!	1,504 KB	8 ms	CPP	701 B	2022-03-30 15:51:27
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> weight, price, dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, W;
    cin >> N >> W;

    weight.resize(N + 1);
    price.resize(N + 1);
    dp.assign(W + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> weight[i] >> price[i];
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = weight[i]; j <= W; j++)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + price[i]);
        }
    }

    cout << dp[W] << endl;
    return 0;
}