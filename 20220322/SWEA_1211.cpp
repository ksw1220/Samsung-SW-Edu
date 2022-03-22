#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<vector<int>> arr(100, vector<int>(100, 0));

int getDistance(int x, int y, int prevY)
{
    if (x == 99)
    {
        return 1;
    }
    else if (y - 1 != prevY && y > 0 && arr[x][y - 1] == 1)
    {
        return getDistance(x, y - 1, y) + 1;
    }
    else if (y + 1 != prevY && y < 99 && arr[x][y + 1] == 1)
    {
        return getDistance(x, y + 1, y) + 1;
    }
    else
    {
        return getDistance(x + 1, y, y) + 1;
    }
}
int main()
{
    int N;
    int answer, minDist;
    for (int testCase = 1; testCase <= 10; testCase++)
    {
        minDist = INF;
        cin >> N;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < 100; i++)
        {
            if (arr[0][i])
            {
                int dist = getDistance(0, i, i);
                if (minDist > dist)
                {
                    minDist = dist;
                    answer = i;
                }
            }
        }
        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}