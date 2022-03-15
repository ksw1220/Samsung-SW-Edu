#include <iostream>
#include <vector>
#include <string>
#define SIZE 8
using namespace std;

vector<string> board;

int findPalindromeVertical(int x, int y, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        if (board[x + i][y] != board[x + len - 1 - i][y])
        {
            return 0;
        }
    }
    return 1;
}
int findPalindromeHorizontal(int x, int y, int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        if (board[x][y + i] != board[x][y + len - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{

    for (int test_case = 1; test_case <= 10; test_case++)
    {
        int N, answer = 0;

        board.resize(SIZE);
        cin >> N;
        for (int i = 0; i < SIZE; i++)
        {
            cin >> board[i];
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i + N <= SIZE)
                {
                    answer += findPalindromeVertical(i, j, N);
                }
                if (j + N <= SIZE)
                {
                    answer += findPalindromeHorizontal(i, j, N);
                }
            }
        }

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}