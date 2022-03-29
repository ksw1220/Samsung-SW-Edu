// 5608974	ksw1220	1889	정답!	1,456 KB	853 ms	CPP	997 B	2022-03-29 15:33:21
#include <iostream>
#include <vector>

using namespace std;

// 각 행에 퀸이 몇번 열에 위치하는지 나타내는 벡터
vector<int> cols;
int N, answer = 0;
bool isPossible(int x, int y)
{
    int len = cols.size();
    for (int i = 0; i < len; i++)
    {
        // i번째 퀸의 좌표는 (i,cols[i]).
        // 현재까지 배치된 len개의 퀸의 좌표와 비교하며 (x,y)에 새로운 퀸이 배치가능한지 확인한다.

        if (y == cols[i] || i - cols[i] == x - y || i + cols[i] == x + y)
        {
            return false;
        }
    }

    return true;
}
void backTracking(int row)
{
    if (row == N)
    {
        answer++;
        return;
    }
    else
    {
        // (row,i)에 퀸을 배치할수 있는지 확인
        for (int i = 0; i < N; i++)
        {
            if (isPossible(row, i))
            {
                cols.push_back(i);
                backTracking(row + 1);
                cols.pop_back();
            }
        }
    }
}
int main()
{
    cin >> N;
    backTracking(0);

    cout << answer << endl;
    return 0;
}