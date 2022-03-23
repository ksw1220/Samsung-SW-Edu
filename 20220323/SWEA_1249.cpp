#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<vector<int>> depth, dist;
queue<pair<int, int>> que;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
int main()
{
    int T, N, answer;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N;
        depth.assign(N, vector<int>(N, 0));
        dist.assign(N, vector<int>(N, INF));
        answer = INF;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%1d", &depth[i][j]);
            }
        }

        dist[0][0] = 0;
        que.push({0, 0});

        while (!que.empty())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();

            if (x == N - 1 && y == N - 1)
            {
                answer = answer > dist[x][y] ? dist[x][y] : answer;
                continue;
            }
            for (int dir = 0; dir < 4; dir++)
            {
                int tox = x + dx[dir];
                int toy = y + dy[dir];
                if (tox < 0 || toy < 0 || tox >= N || toy >= N)
                    continue;
                if (dist[tox][toy] > dist[x][y] + depth[tox][toy])
                {
                    dist[tox][toy] = dist[x][y] + depth[tox][toy];
                    que.push({tox, toy});
                }
            }
        }

        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}