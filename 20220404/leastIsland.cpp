#include <stdio.h>
#include <vector>
#include <algorithm>

// 최대 소비 식량이 10,000이고 섬의 개수가 100,000이므로 필요 식량의 최솟값은 -INF이다.
#define INF 1000000000
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> foods;
vector<bool> visited;
int N, answer;
void dfs(int now, int nowFood, int minFood)
{
    minFood = minFood < nowFood ? minFood : nowFood;
    // 섬에 도착하면 foods[now]를 더해 친구가 주는 식량을 추가한다.
    nowFood += foods[now];
    // N에 도착하면 N까지 도착할때 까지의 최소 식량인 minFood 값을 통해 answer를 갱신한다.
    if (now == N)
    {
        answer = answer > minFood ? answer : minFood;
        return;
    }
    else
    {
        int len = adj[now].size();

        // minFood에는 nowFood의 최솟값을 저장한다.
        for (int i = 0; i < len; i++)
        {
            int next = adj[now][i].first;
            int nextFood = nowFood - adj[now][i].second;

            if (!visited[next])
            {
                visited[next] = true;
                dfs(next, nextFood, minFood);
                visited[next] = false;
            }
        }
    }
}
int main()
{
    int T, M, K, answerTime, a, b, c;
    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d %d %d", &N, &M, &K);

        answer = -INF;
        foods.assign(N + 1, 0);
        visited.assign(N + 1, false);
        adj.assign(N + 1, vector<pair<int, int>>(0, {0, 0}));
        while (M--)
        {
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back({b, c});
        }
        while (K--)
        {
            scanf("%d %d", &a, &b);
            foods[a] = b;
        }

        visited[1] = true;
        dfs(1, 0, 0);
        visited[1] = false;

        printf("%d\n", -answer);
    }
    return 0;
}