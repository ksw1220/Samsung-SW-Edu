#include <stdio.h>
#include <vector>

using namespace std;

int N, groupNum;
vector<vector<int>> arr, group;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

// dfs를 돌면서 도착한 점을 groupNum에 속하도록 한다.
void dfs(int x, int y)
{
    group[x][y] = groupNum;
    for (int dir = 0; dir < 4; dir++)
    {
        int tox = x + dx[dir];
        int toy = y + dy[dir];
        if (tox < 1 || toy < 1 || tox > N || toy > N || arr[tox][toy] || group[tox][toy])
        {
            continue;
        }
        dfs(tox, toy);
    }
}
int main()
{
    int T, M, a, b, c, d, answer;
    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d %d", &N, &M);
        arr.assign(N + 1, vector<int>(N + 1, 0));
        group.assign(N + 1, vector<int>(N + 1, 0));
        groupNum = 0;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                // arr의 값이 0이고 group에 속하지 않는다면 새로운 그룹을 시작
                if (!arr[i][j] && !group[i][j])
                {
                    groupNum++;
                    dfs(i, j);
                }
            }
        }

        printf("#%d ", testCase);
        while (M--)
        {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            // 같은 그룹에 속한다면 이어져있다.
            printf("%d ", group[a][b] == group[c][d]);
        }
        printf("\n");
    }
    return 0;
}