#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1300000000
using namespace std;

struct pos
{
    int x, y, dist;

    bool operator<(const pos &t) const
    {
        return dist > t.dist;
    }
};
// distJ는 존으로부터 거리 distC는 클로이으로부터 거리 // distD는 목적지로부터 거리
vector<vector<int>> arr, distJ, distC, distT;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
priority_queue<pos> pq;
int main()
{
    int T, N, M, jx, jy, cx, cy, tx, ty, answer;

    scanf("%d", &T);

    for (int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d %d %d %d %d %d %d %d", &N, &M, &jx, &jy, &cx, &cy, &tx, &ty);
        answer = INF;
        arr.assign(N + 1, vector<int>(M + 1, 0));
        distJ.assign(N + 1, vector<int>(M + 1, INF));
        distC.assign(N + 1, vector<int>(M + 1, INF));
        distT.assign(N + 1, vector<int>(M + 1, INF));

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        // 존과의 거리를 구한다.
        distJ[jx][jy] = 0;
        pq.push({jx, jy, 0});
        while (!pq.empty())
        {
            pos now = pq.top();
            pq.pop();

            for (int dir = 0; dir < N; dir++)
            {
                int tox = now.x + dx[dir];
                int toy = now.y + dy[dir];
                if (tox < 1 || toy < 1 || tox > N || toy > M)
                    continue;
                if (distJ[tox][toy] > arr[now.x][now.y] + distJ[now.x][now.y])
                {
                    distJ[tox][toy] = arr[now.x][now.y] + distJ[now.x][now.y];
                    pq.push({tox, toy, distJ[tox][toy]});
                }
            }
        }
        // 클로이와의 거리를 구한다.
        distC[cx][cy] = 0;
        pq.push({cx, cy, 0});
        while (!pq.empty())
        {
            pos now = pq.top();
            pq.pop();

            for (int dir = 0; dir < N; dir++)
            {
                int tox = now.x + dx[dir];
                int toy = now.y + dy[dir];
                if (tox < 1 || toy < 1 || tox > N || toy > M)
                    continue;
                if (distC[tox][toy] > arr[now.x][now.y] + distC[now.x][now.y])
                {
                    distC[tox][toy] = arr[now.x][now.y] + distC[now.x][now.y];
                    pq.push({tox, toy, distC[tox][toy]});
                }
            }
        }
        distT[tx][ty] = 0;
        pq.push({tx, ty, 0});
        while (!pq.empty())
        {
            pos now = pq.top();
            pq.pop();

            for (int dir = 0; dir < N; dir++)
            {
                int tox = now.x + dx[dir];
                int toy = now.y + dy[dir];
                if (tox < 1 || toy < 1 || tox > N || toy > M)
                    continue;
                // distT는 도착지점이므로 역순임을 고려하여 arr[tox][toy]를 더한 값과 비교한다.
                if (distT[tox][toy] > arr[tox][toy] + distT[now.x][now.y])
                {
                    distT[tox][toy] = arr[tox][toy] + distT[now.x][now.y];
                    pq.push({tox, toy, distT[tox][toy]});
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (answer > distJ[i][j] + distC[i][j] + distT[i][j])
                {
                    answer = distJ[i][j] + distC[i][j] + distT[i][j];
                }
            }
        }

        printf("#%d %d\n", testCase, answer);
    }

    return 0;
}