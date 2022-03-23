#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> indegree;
queue<int> que;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int V, E, a, b;
    for (int testCase = 1; testCase <= 10; testCase++)
    {
        cin >> V >> E;
        indegree.assign(V + 1, 0);
        adj.assign(V + 1, vector<int>(0, 0));
        while (E--)
        {
            cin >> a >> b;
            indegree[b]++;
            adj[a].push_back(b);
        }

        for (int i = 1; i <= V; i++)
        {
            if (!indegree[i])
            {
                que.push(i);
            }
        }

        cout << "#" << testCase << " ";

        while (!que.empty())
        {
            int now = que.front();
            que.pop();
            cout << now << " ";

            for (int i = 0; i < adj[now].size(); i++)
            {
                int next = adj[now][i];
                indegree[next]--;
                if (!indegree[next])
                {
                    que.push(next);
                }
            }
        }
        cout << endl;
    }
    return 0;
}