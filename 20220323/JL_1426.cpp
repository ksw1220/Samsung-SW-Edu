//5593784	ksw1220	1462	정답!	1,552 KB	117 ms	CPP	1767 B	2022-03-23 16:13:39
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define INF 987654321
using namespace std;

vector<string> arr;
queue<pair<int, int>> que;
vector<vector<int>> dist;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int L, W;
    int cnt = 0, answer = 0;
    cin >> L >> W;
    arr.resize(L);
    for (int i = 0; i < L; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (arr[i][j] == 'L')
            {

                dist.assign(L, vector<int>(W, INF));
                dist[i][j] = 0;
                que.push({i, j});
                while (!que.empty())
                {
                    int x = que.front().first;
                    int y = que.front().second;
                    que.pop();

                    answer = answer > dist[x][y] ? answer : dist[x][y];
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int tox = x + dx[dir];
                        int toy = y + dy[dir];

                        if (tox < 0 || toy < 0 || tox >= L || toy >= W || arr[tox][toy] == 'W')
                            continue;
                        if (dist[tox][toy] > dist[x][y] + 1)
                        {
                            dist[tox][toy] = dist[x][y] + 1;
                            que.push({tox, toy});
                        }
                    }
                }
            }
        }
    }

    cout << answer << endl;
    return 0;
}