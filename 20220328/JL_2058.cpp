// 5607656	ksw1220	2058	정답!	2,824 KB	41 ms	CPP	2311 B	2022-03-28 15:22:18
#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
    int x1, y1, x2, y2;
};
int dx[9] = {-1, -1, -1, 0, 1, 1, 1, 0, 0};
int dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1, 0};
int visitedTime[26][26][26][26];
int arr[26][26];
queue<Pos> que;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, answer = 0;
    int startX1, startY1, endX1, endY1;
    int startX2, startY2, endX2, endY2;

    cin >> N;
    cin >> startX1 >> startY1 >> endX1 >> endY1;
    cin >> startX2 >> startY2 >> endX2 >> endY2;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }

    visitedTime[startX1][startY1][startX2][startY2] = 0;
    que.push({startX1, startY1, startX2, startY2});

    while (!que.empty())
    {
        Pos now = que.front();
        que.pop();

        // 도착했다면 answer를 저장한 뒤 break
        if (now.x1 == endX1 && now.y1 == endY1 && now.x2 == endX2 && now.y2 == endY2)
        {
            answer = visitedTime[now.x1][now.y1][now.x2][now.y2];
            break;
        }
        // 첫 번째 고슴도치의 8방향
        for (int dir1 = 0; dir1 < 9; dir1++)
        {
            int tox1 = now.x1 + dx[dir1];
            int toy1 = now.y1 + dy[dir1];
            if (tox1 <= 0 || toy1 <= 0 || tox1 > N || toy1 > N || arr[tox1][toy1] == 1)
                continue;

            // 두 번째 고슴도치의 8방향
            for (int dir2 = 0; dir2 < 9; dir2++)
            {
                bool isPos = true;
                int tox2 = now.x2 + dx[dir2];
                int toy2 = now.y2 + dy[dir2];
                if (tox2 <= 0 || toy2 <= 0 || tox2 > N || toy2 > N || arr[tox2][toy2] == 1)
                    continue;

                // 두 고슴도치가 서로 붙어있는지 확인
                if (abs(tox1 - tox2) <= 1 && abs(toy1 - toy2) <= 1)
                {
                    continue;
                }

                if (visitedTime[tox1][toy1][tox2][toy2] == 0)
                {
                    visitedTime[tox1][toy1][tox2][toy2] = visitedTime[now.x1][now.y1][now.x2][now.y2] + 1;
                    que.push({tox1, toy1, tox2, toy2});
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}