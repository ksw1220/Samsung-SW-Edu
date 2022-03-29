#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int, int>> locations;
// dp[N+1][1<<(N+1)]
// dp[i][bitMask] 는 i번째 좌표에 위치했을 때 bitMask를 가질 수 있는 거리의 최솟값이다.
vector<vector<int>> dp;

int N, answer;
void dfs(int now, int accDist, int bitMask)
{
    if (accDist >= answer)
    {
        return;
    }
    // bitMask를 통해 모든 점을 방문했는지 확인한다.
    else if (bitMask == (1 << (N + 1)) - 1)
    {
        answer = min(answer, accDist + abs(locations[now].first - locations[N + 1].first) + abs(locations[now].second - locations[N + 1].second));
        return;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            int dist = abs(locations[now].first - locations[i].first) + abs(locations[now].second - locations[i].second);
            // accDist는 now번째 점에 위치할 때 bitMask를 가지는 거리의 최솟값이다.
            // 이 거리에 now에서 i번째 점까지의 거리인 dist를 더한 값이 dp[i][bitMask | (1 << i)] 보다 작다면 더 빠른 경로를 찾았으므로 갱신한다.
            if (!(bitMask & (1 << i)) && accDist + dist < dp[i][bitMask | (1 << i)])
            {
                int nextBistMask = bitMask | (1 << i);
                dp[i][nextBistMask] = accDist + dist;
                dfs(i, dp[i][nextBistMask], nextBistMask);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;

    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N;
        locations.resize(N + 2);
        dp.assign(N + 1, vector<int>(1 << (N + 1), INF));
        answer = INF;

        // locations[0] 에는 집의 좌표, locations[N+1]에는 회사의 좌표
        cin >> locations[0].first >> locations[0].second >> locations[N + 1].first >> locations[N + 1].second;
        for (int i = 1; i <= N; i++)
        {
            cin >> locations[i].first >> locations[i].second;
        }
        dp[0][0] = 0;
        // 0번은 시작점이므로 bitMask를 1로 시작한다.
        dfs(0, 0, 1);

        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}