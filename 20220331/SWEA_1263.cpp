#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

queue<int> que;
vector<vector<int>> dist;
vector<vector<int>> adj;
int main()
{
    int T, N, a, b;
    scanf("%d", &T);

    for (int testCase = 1; testCase <= T; testCase++)
    {
        int answer = INF;
        scanf("%d", &N);
        adj.assign(N, vector<int>(0, 0));
        dist.assign(N, vector<int>(N, INF));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &a);
                if (a == 1)
                {
                    adj[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            dist[i][i] = 0;
            que.push(i);

            while (!que.empty())
            {
                int now = que.front();
                que.pop();

                int len = adj[now].size();
                for (int j = 0; j < len; j++)
                {
                    if (dist[i][adj[now][j]] == INF)
                    {
                        dist[i][adj[now][j]] = dist[i][now] + 1;
                        que.push(adj[now][j]);
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            int acc = 0;
            for (int j = 0; j < N; j++)
            {
                acc += dist[i][j];
            }
            answer = min(answer, acc);
        }

        printf("#%d %d\n", testCase, answer);
    }
    return 0;
}