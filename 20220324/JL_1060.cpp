//5596072	ksw1220	1060	정답!	1,764 KB	8 ms	CPP	1423 B	2022-03-24 16:46:34
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> parent;
struct Edge
{
    int start, end, weight;

    bool operator<(const Edge &edge) const
    {
        return weight > edge.weight;
    }
};

int find(int n)
{
    if (n == parent[n])
    {
        return n;
    }
    else
    {
        return parent[n] = find(parent[n]);
    }
}
priority_queue<Edge> pq;
int main()
{
    int N, answer = 0;
    cin >> N;

    graph.assign(N, vector<int>(N, 0));
    parent.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    for (int i = 1; i < N; i++)
    {
        pq.push({0, i, graph[0][i]});
    }

    while (!pq.empty())
    {
        Edge now = pq.top();
        pq.pop();

        int pStart = find(now.start);
        int pEnd = find(now.end);

        if (pStart != pEnd)
        {
            parent[pEnd] = pStart;
            answer += now.weight;
            for (int i = 0; i < N; i++)
            {
                if (now.end != i)
                {
                    pq.push({now.end, i, graph[now.end][i]});
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}