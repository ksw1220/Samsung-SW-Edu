#include <iostream>
#include <vector>
#include <stdio.h>

#define SIZE 100

using namespace std;
vector<vector<int>> arr(SIZE, vector<int>(SIZE, 0));
vector<vector<bool>> visited;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};

int startX, startY, destX, destY, answer;

void dfs(int x, int y)
{
    if (answer == 1)
    {
        return;
    }
    else if (x == destX && y == destY)
    {
        answer = 1;
        return;
    }
    else
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int tox = x + dx[dir];
            int toy = y + dy[dir];
            if (tox < 0 || toy < 0 || tox >= SIZE || toy >= SIZE || arr[tox][toy] == 1 || visited[tox][toy])
                continue;

            visited[tox][toy] = true;
            dfs(tox, toy);
        }
    }
}
using namespace std;
int main()
{
    int N;
    for (int testCase = 1; testCase <= 10; testCase++)
    {
        cin >> N;
        answer = 0;
        visited.assign(SIZE, vector<bool>(SIZE, false));
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                scanf("%1d", &arr[i][j]);
                if (arr[i][j] == 2)
                {
                    startX = i;
                    startY = j;
                }
                else if (arr[i][j] == 3)
                {
                    destX = i;
                    destY = j;
                }
            }
        }

        visited[startX][startY] = true;
        dfs(startX, startY);

        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}