// 5592085	ksw1220	1078	정답!	1,628 KB	9 ms	CPP	1562 B	2022-03-22 16:58:15
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct POS
{
    int x, y, t;
};
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
queue<POS> que;

int main()
{
    int N, M, startX, startY;
    int deadTime=0, notDeadCnt = 0;
    // N:행, M:열, x:행, y:열
    cin >> M >> N;
    arr.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }


    cin >> startY >> startX;

    visited[startX - 1][startY - 1] = true;
    que.push({startX - 1, startY - 1, 0});

    while (!que.empty())
    {
        POS now = que.front();
        que.pop();
        deadTime = deadTime < now.t ? now.t : deadTime;
        for (int dir = 0; dir < 4; dir++)
        {
            int tox = now.x + dx[dir];
            int toy = now.y + dy[dir];
            if (tox < 0 || toy < 0 || tox >= N || toy >= M || arr[tox][toy] == 0 || visited[tox][toy])
                continue;

            visited[tox][toy] = true;
            que.push({tox, toy, now.t + 1});
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                notDeadCnt++;
            }
        }
    }
    cout << deadTime + 3 << endl
         << notDeadCnt << endl;
    return 0;
}