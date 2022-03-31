// 5614039	ksw1220	1825	정답!	1,520 KB	5 ms	CPP	1454 B	2022-03-31 16:51:12
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp, price;
vector<int> track;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int W, N, cost;
    cin >> W >> N;
    price.assign(N + 1, vector<int>(W + 1, 0));
    dp.assign(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= W; i++)
    {
        cin >> cost;
        for (int j = 1; j <= N; j++)
        {
            cin >> price[j][i];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            // k는 i번째 기업에 투자할 돈
            for (int k = 0; k <= j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + price[i][k]);
            }
        }
    }

    // track 벡터에 i번째 기업에 투자한 액수를 N부터 1까지 역순으로 저장한다.
    int nowCost = W;
    for (int i = N; i > 0; i--)
    {
        for (int j = nowCost; j >= 0; j--)
        {
            // 아래 조건문을 만족한다는 것은 i번째 기업에 nowCost-j 원을 투자했다는 것을 의미한다.
            if (dp[i - 1][j] + price[i][nowCost - j] == dp[i][nowCost])
            {
                track.push_back(nowCost - j);
                nowCost = j;
                break;
            }
        }
    }


    cout << dp[N][W] << endl;
    int len = track.size();
    // track를 역순으로 출력
    for (int i = len - 1; i >= 0; i--)
    {
        cout << track[i] << " ";
    }
    cout << endl;
    return 0;
}