#include <iostream>
#include <vector>

#define SIZE 100
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

// 그래프 탐색을 위한 dfs
void dfs(int now)
{
    visited[now] = true;
    for (int i = 0; i < graph[now].size(); i++)
    {
        int next = graph[now][i];
        if (!visited[next])
        {
            dfs(next);
        }
    }
}
int main()
{
    int T, N, a, b;

    for (int testCase = 1; testCase <= 10; testCase++)
    {
        cin >> T >> N;
        graph.assign(SIZE, vector<int>(0, 0));
        visited.assign(SIZE, false);
        for (int i = 0; i < N; i++)
        {
            cin >> a >> b;
            graph[a].push_back(b);
        }

        dfs(0);

        cout << "#" << testCase << " ";

        if (visited[99])
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}