#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 200000000000000
using namespace std;

long long answer;
int blueCnt;
vector<vector<int>> adj;
vector<vector<bool>> isUsed;
vector<long long> dp, army;
vector<bool> visited;

long long dfs(int now)
{
    long long re = army[now], tmp;

    int len = adj[now].size();
    for (int i = 0; i < len; i++)
    {
        int next = adj[now][i];
        if (!visited[next])
        {
            visited[next] = true;
            tmp = dfs(next);
            // tmp 값이 양수라면 now의 자식 노드인 next의 서브트리중 일부를 사용하여 사단을 구성하는 것이 더 크다.
            if (tmp > 0)
            {
                // now에서 i번째 child를 사단의 최댓값을 만들 때 사용하였다는 체크
                isUsed[now][i] = true;
                re += tmp;
            }
        }
    }
    return dp[now] = re;
}

void checkBlue(int now)
{
    blueCnt++;
    visited[now] = true;
    int len = isUsed[now].size();

    for (int i = 0; i < len; i++)
    {
        if (isUsed[now][i])
        {
            checkBlue(adj[now][i]);
        }
    }
}
int main()
{
    int T, N, a, b, blueRoot;
    long long blue, yellow;
    scanf("%d", &T);

    for (int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d", &N);
        blue = yellow = -INF;
        blueCnt = 0;
        adj.assign(N + 1, vector<int>(0, 0));
        isUsed.assign(N + 1, vector<bool>(0, false));
        army.assign(N + 1, 0);
        dp.assign(N + 1, -INF);
        visited.assign(N + 1, false);
        for (int i = 1; i <= N; i++)
        {
            scanf("%lld", &army[i]);
        }

        for (int i = 0; i < N - 1; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= N; i++)
        {
            isUsed[i].assign(adj[i].size(), false);
        }

        visited[1] = true;
        dp[1] = dfs(1);
        blueRoot = 1;

        // 가장 dp값이 큰 것을 blue에 저장
        for (int i = 1; i <= N; i++)
        {
            if (blue < dp[i])
            {
                blue = dp[i];
                blueRoot = i;
            }
        }

        visited.assign(N + 1, false);
        dp.assign(N + 1, -INF);

        // blueRoot를 시점으로 blue 사단을 만드는데 사용된 노드들을 체크한다.
        // 처음 dfs함수를 돌릴 때 isUsed 벡터를 체크한 것을 이용한다.

        checkBlue(blueRoot);
        // 위 함수가 끝나면 blue 사단에 포함되는 노드들은 visited가 true로 되어있다.
        // 따라서 dfs를 추가적으로 돌릴 때 제외된다.

        // blueRoot를 기준으로 트리가 끊어져 있기 때문에 (1~N)까지 노드들을 모두 확인하며,
        // 방문된 적이 없다면 dfs를 돌려 dp 배열이 blue 사단을 제외한 것들로 구성되게 만든다.
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                dfs(i);
            }
        }

        for (int i = 1; i <= N; i++)
        {
            if (yellow < dp[i])
            {
                yellow = dp[i];
            }
        }

        // 만약 yellow가 음수라면 blue 사단을 구성할 때 트리 내의 양수 노드를 모두 사용한 것이다.
        // 이 경우 yellow를 음수 노드로 구성하는 것 보다 blue 사단의 임의의 한 노드를 yellow에게 주어 구성하는 것이 더 최댓값이다.
        // 따라서 yellow를 0으로 만든 후 더하는 것이 위의 blue에서 노드 하나를 받아오는 방법과 더한 값이 같다.

        // blue가 양수이고 blueCnt가 1보다 크다면 yellow에게 노드를 하나 줄 수 있으므로 yellow=0
        // blue가 양수이더라도 blueCnt가 1보다 작다면 yellow에게 줄 수 있는 노드가 없다.
        // blue가 음수라면 모든 노드가 음수인 것이므로 blueCnt는 1일 것이고 yellow 값도 음수 노드 중 그 다음으로 큰 값일 것이다.
        if (blue >= 0 && yellow < 0 && blueCnt > 1)
        {
            yellow = 0;
        }
        printf("#%d %lld\n", testCase, blue + yellow);
    }
    return 0;
}