#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge
{
    int start, end;
    long long weight, dist;

    // dist를 기준으로 정렬
    bool operator<(const Edge &t) const
    {
        return dist > t.dist;
    }
};
vector<int> parent;
vector<long long> dist;
vector<vector<pair<int, long long>>> adj;
priority_queue<Edge> pq;
int find(int now)
{
    if (now == parent[now])
    {
        return now;
    }
    else
    {
        return parent[now] = find(parent[now]);
    }
}
int main()
{
    int T, N, M, S, E, answer;
    long long C;

    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d %d", &N, &M);
        answer = 0;
        parent.resize(N + 1);
        dist.assign(N + 1, 0);
        adj.assign(N + 1, vector<pair<int, long long>>(0, {0, 0}));
        for (int i = 0; i <= N; i++)
        {
            parent[i] = i;
        }

        while (M--)
        {
            scanf("%d %d %lld", &S, &E, &C);

            adj[S].push_back({E, C});
            adj[E].push_back({S, C});
        }

        int len = adj[1].size();
        dist[1] = 0;

        for (int i = 0; i < len; i++)
        {
            pq.push({1, adj[1][i].first, adj[1][i].second, adj[1][i].second});
        }

        while (!pq.empty())
        {
            Edge now = pq.top();
            pq.pop();

            int findNow = find(now.start);
            int findNext = find(now.end);

            // now.start와 now.end가 같은 집합에 속하지 않는다면 합친다.
            // pq는 1번 노드부터의 거리 dist로 정렬되었으므로 now.end까지의 최소 거리임이 보장된다.
            if (findNow != findNext)
            {
                parent[findNext] = parent[findNow];
                dist[now.end] = dist[now.start] + now.weight;
                answer += now.weight;
            }

            int len = adj[now.end].size();
            for (int i = 0; i < len; i++)
            {
                // adj[now.end][i].first는 now.end로 부터 이어지는 노드의 번호이고 adj[now.end][i].second는 그 간선의 거리이다.
                // now.start와 now.end를 잇는 간선의 가중치 now.weight가 now.end 입장에서는 부모 노드인 now.start와의 거리이다.
                // 먼저 now.weight와 adj[now.end][i].second를 비교하여 부모 노드와의 거리보다 거리가 긴지 확인한다.
                // 다음으로는 now.end와 now.end와 이어지는 노드가 같은 집합에 속하는지 확인한다. 만족한다면 pq.push()
                if (now.weight <= adj[now.end][i].second && find(now.end) != find(adj[now.end][i].first))
                {
                    // 4번째 dist위치에는 dist[now.end]에 weight를 더한 값을 넣어준다.
                    pq.push({now.end, adj[now.end][i].first, adj[now.end][i].second, dist[now.end] + adj[now.end][i].second});
                }
            }
        }

        printf("#%d %d", testCase, answer);
    }
    return 0;
}