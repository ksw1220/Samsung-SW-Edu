// 5591984	ksw1220	1695	정답!	1,588 KB	8 ms	CPP	1377 B	2022-03-22 16:34:30
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<int> complex;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int N;
int dfs(int x, int y)
{
    int re = 1;
    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];
        if (tox < 0 || toy < 0 || tox >= N || toy >= N || arr[tox][toy] == 0 || visited[tox][toy])
            continue;

        visited[tox][toy] = true;
        re += dfs(tox, toy);
    }
    return re;
}
int main()
{
    cin >> N;
    arr.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%1d", &arr[i][j]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                visited[i][j] = true;
                complex.push_back(dfs(i, j));
            }
        }
    }

    sort(complex.begin(), complex.end());

    int len = complex.size();

    cout << len << endl;
    for (int i = 0; i < len; i++)
    {
        cout << complex[i] << endl;
    }
    return 0;
}