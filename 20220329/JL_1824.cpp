// 5609124	ksw1220	1824	정답!	1,392 KB	11 ms	CPP	1711 B	2022-03-29 15:46:18
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(9, vector<int>(9, 0));
vector<pair<int, int>> pos;

int N;
bool checked = false;

bool isPossible(int x, int y, int num)
{
    int startX = x - x % 3;
    int startY = y - y % 3;

    // 가로 세로 확인
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == num || board[i][y] == num)
        {
            return false;
        }
    }

    // 박스 확인
    for (int i = startX; i < startX + 3; i++)
    {
        for (int j = startY; j < startY + 3; j++)
        {
            if (board[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

void dfs(int now)
{
    // 이미 해를 찾았다면 리턴
    if (checked)
    {
        return;
    }
    // 모든 pos를 채운 경우
    else if (now == pos.size())
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        checked = true;
        return;
    }
    else
    {
        // 9개의 숫자를 모두 확인해본다.
        for (int i = 1; i <= 9; i++)
        {
            if (isPossible(pos[now].first, pos[now].second, i))
            {
                board[pos[now].first][pos[now].second] = i;
                dfs(now + 1);
                board[pos[now].first][pos[now].second] = 0;
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
            {
                pos.push_back({i, j});
            }
        }
    }

    dfs(0);
    return 0;
}