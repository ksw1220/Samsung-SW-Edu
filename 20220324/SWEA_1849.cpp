#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, treeRank;
vector<long long> dist;
int find(int n)
{
    if (n == parent[n])
    {
        return parent[n];
    }
    else
    {
        dist[n] += dist[parent[n]];
        return parent[n] = find(parent[n]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, a, b;
    long long w;
    char op;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N >> M;
        parent.resize(N + 1);
        treeRank.resize(N + 1);
        dist.resize(N + 1);
        for (int i = 0; i <= N; i++)
        {
            parent[i] = i;
            treeRank[i] = dist[i] = 0;
        }

        cout << "#" << testCase << " ";

        while (M--)
        {
            cin >> op >> a >> b;
            int pA = find(a);
            int pB = find(b);

            if (op == '!')
            {
                cin >> w;
                if (pA != pB)
                {
                    if (treeRank[pA] > treeRank[pB])
                    {
                        parent[pB] = pA;
                        dist[pB] = dist[a] - dist[b] - w;
                    }
                    else
                    {
                        parent[pA] = pB;
                        dist[pA] = dist[b] - dist[a] + w;
                        if (treeRank[pA] == treeRank[pB])
                        {
                            treeRank[pB]++;
                        }
                    }
                }
            }
            else
            {
                if (pA == pB)
                {
                    cout << dist[a] - dist[b] << " ";
                }
                else
                {
                    cout << "UNKNOWN ";
                }
            }
        }

        cout << endl;
    }

    return 0;
}