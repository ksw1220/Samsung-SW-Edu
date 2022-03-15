#include <iostream>
#include <vector>
#define SIZE 19
#define INF 20
using namespace std;

vector<vector<int>> board;
int checkOmok(int x, int y, int color)
{
    // vertical

    int len = 1;
    while (x + len < SIZE && board[x + len][y] == color)
    {
        len++;
    }
    // 확인하는 반대 방향도 같은 색이라면 고려하지 않기 위해 len에 INF를 넣는다.
    if (x - 1 >= 0 && board[x - 1][y] == color)
    {
        len = INF;
    }
    if (len == 5)
    {
        return color;
    }

    // horizontal
    len = 1;
    while (y + len < SIZE && board[x][y + len] == color)
    {
        len++;
    }
    // 확인하는 반대 방향도 같은 색이라면 고려하지 않기 위해 len에 INF를 넣는다.
    if (y - 1 >= 0 && board[x][y - 1] == color)
    {
        len = INF;
    }
    if (len == 5)
    {
        return color;
    }

    // diagonal
    len = 1;
    while (x + len < SIZE && y + len < SIZE && board[x + len][y + len] == color)
    {
        len++;
    }
    // 확인하는 반대 방향도 같은 색이라면 고려하지 않기 위해 len에 INF를 넣는다.
    if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == color)
    {
        len = INF;
    }
    if (len == 5)
    {
        return color;
    }

    len = 1;
    while (x - len >= 0 && y + len < SIZE && board[x - len][y + len] == color)
    {
        len++;
    }
    // 확인하는 반대 방향도 같은 색이라면 고려하지 않기 위해 len에 INF를 넣는다.
    if (x + 1 < SIZE && y - 1 >= 0 && board[x - 1][y] == color)
    {
        len = INF;
    }
    if (len == 5)
    {
        return color;
    }

    return 0;
}
int main()
{
    board.assign(SIZE, vector<int>(SIZE, 0));

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j])
            {
                int re = checkOmok(i, j, board[i][j]);
                if (re)
                {
                    cout << re << endl;
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << 0 << endl;
    return 0;
}