// 5617243	ksw1220	3336	정답!	42,448 KB	52 ms	CPP	1695 B	2022-04-01 17:18:38
#include <stdio.h>
#include <vector>
using namespace std;

#define EXTRA 500000
#define MAX 1000002
vector<pair<int, int>> points;
vector<int> vertical, horizontal;
int main()
{
    int N, x, y, h = 0, v = 0, hTmp = 0, vTmp = 0;
    int maxV, minV;
    points.assign(N, {0, 0});
    vertical.assign(MAX, 0);
    horizontal.assign(MAX, 0);
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        points[i] = {x + EXTRA, y + EXTRA};
    }

    for (int i = 0; i < N; i++)
    {
        int x = points[i].first;
        int y = points[i].second;
        int nextX = points[(i + 1) % N].first;
        int nextY = points[(i + 1) % N].second;

        // 수직 선분
        if (x == nextX)
        {
            if (y > nextY)
            {
                maxV = y;
                minV = nextY;
            }
            else
            {
                maxV = nextY;
                minV = y;
            }
            horizontal[minV]++;
            horizontal[maxV]--;
        }
        // 수평 선분
        else
        {
            if (x > nextX)
            {
                maxV = x;
                minV = nextX;
            }
            else
            {
                maxV = nextX;
                minV = x;
            }
            vertical[minV]++;
            vertical[maxV]--;
        }
    }

    for (int i = 0; i < MAX; i++)
    {
        vTmp += vertical[i];
        v = v > vTmp ? v : vTmp;
    }
    for (int i = 0; i < MAX; i++)
    {
        hTmp += horizontal[i];
        h = h > hTmp ? h : hTmp;
    }
    printf("%d\n", h > v ? h : v);
    return 0;
}