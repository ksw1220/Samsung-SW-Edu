// 5607543	ksw1220	2613	정답!	5,672 KB	133 ms	CPP	1765 B	2022-03-28 14:28:52
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tomato
{
    int x, y;
};
vector<vector<int>> arr;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

queue<Tomato> tomatoes, candidates;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int N, M, answer = 0;
    cin >> M >> N;
    arr.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                candidates.push({i, j});
            }
        }
    }

    while (!candidates.empty())
    {
        while (!candidates.empty())
        {
            tomatoes.push(candidates.front());
            candidates.pop();
        }

        answer++;
        while (!tomatoes.empty())
        {
            Tomato now = tomatoes.front();
            tomatoes.pop();

            for (int dir = 0; dir < 4; dir++)
            {
                int tox = now.x + dx[dir];
                int toy = now.y + dy[dir];
                if (tox < 0 || toy < 0 || tox >= N || toy >= M || arr[tox][toy] != 0)
                    continue;
                arr[tox][toy] = arr[now.x][now.y] + 1;
                candidates.push({tox, toy});
            }
        }
    }

    bool chk = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                chk = false;
                break;
            }
        }
    }
    if (chk)
    {
        cout << answer - 1 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}