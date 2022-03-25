#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> tree;
vector<int> parent, depth, subTreeSize;
int dfs(int now)
{
    int re = 1;
    for (int i = 0; i < tree[now].size(); i++)
    {
        int next = tree[now][i];
        if (next != parent[now])
        {
            parent[next] = now;
            depth[next] = depth[now] + 1;
            re += dfs(next);
        }
    }
    return subTreeSize[now] = re;
}

int getAncestor(int a, int b)
{
    if (depth[a] > depth[b])
    {
        swap(a, b);
    }

    while (depth[a] != depth[b])
    {
        b = parent[b];
    }

    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, V, E, A, B, a, b;
    cin >> T;
    for (int testCase = 1; testCase <= 10; testCase++)
    {
        cin >> V >> E >> A >> B;
        tree.assign(V + 1, vector<int>(0, 0));
        parent.assign(V + 1, 0);
        depth.assign(V + 1, 0);
        subTreeSize.assign(V + 1, 0);
        while (E--)
        {
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        parent[1] = 0;
        depth[1] = 1;
        subTreeSize[1] = dfs(1);

        int ancestor = getAncestor(A, B);
        cout << "#" << testCase << " " << ancestor << " " << subTreeSize[ancestor];
        cout << endl;
    }

    return 0;
}