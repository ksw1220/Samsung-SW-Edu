// 5616909	ksw1220	1151	정답!	976 KB	26 ms	CPP	2011 B	2022-04-01 16:05:33
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

struct poi
{
    int x, y;
};
int ccw(poi a, poi b, poi c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
vector<poi> points, convexHull;
bool cmp(poi a, poi b)
{
    int ccwTmp = ccw(points[0], a, b);
    // 선분 (p[0],a) 와 선분 (p[0],b) 가 일직선 상에 있는 경우
    if (ccwTmp == 0)
    {
        return (points[0].x - a.x) * (points[0].x - a.x) + (points[0].y - a.y) * (points[0].y - a.y) < (points[0].x - b.x) * (points[0].x - b.x) + (points[0].y - b.y) * (points[0].y - b.y);
    }
    else
    {
        return ccwTmp > 0;
    }
}

int main()
{
    int T, N, Q, x, y, startIdx, answer;
    scanf("%d", &T);
    for (int testCase = 1; testCase <= T; testCase++)
    {
        poi start = {MAX + 1, MAX + 1};
        convexHull.clear();
        answer = 0;
        scanf("%d", &N);
        points.resize(N);
        for (int i = 0; i < N; i++)
        {
            scanf("%d %d", &points[i].x, &points[i].y);
            if ((start.y > points[i].y) || (start.y == points[i].y && start.x > points[i].x))
            {
                start = points[i];
                startIdx = i;
            }
        }

        points[startIdx] = points[0];
        points[0] = start;

        // poinst[0]에 대한 기울기로 정렬
        sort(points.begin() + 1, points.end(), cmp);

        // convex hull 생성
        convexHull.push_back(points[0]);
        convexHull.push_back(points[1]);
        convexHull.push_back(points[2]);

        poi top, nextToTop;
        for (int i = 3; i < N; i++)
        {
            top = convexHull.back();
            nextToTop = convexHull[convexHull.size() - 2];
            while (ccw(nextToTop, top, points[i]) <= 0)
            {
                convexHull.pop_back();
                top = nextToTop;
                nextToTop = convexHull[convexHull.size() - 2];
            }
            convexHull.push_back(points[i]);
        }

        scanf("%d", &Q);
        while (Q--)
        {
            scanf("%d %d", &x, &y);
            int len = convexHull.size();
            // 말뚝이 추가되는지 확인
            for (int i = 0; i < len - 1; i++)
            {
                int tmpCcw = ccw(convexHull[i], convexHull[i + 1], {x, y});
                // 같은 기울기를 갖는 경우 x,y좌표의 절댓값 차이로 길이 비교
                if (tmpCcw == 0)
                {
                    if (abs(convexHull[i].x - x) + abs(convexHull[i].y - y) >
                        abs(convexHull[i].x - convexHull[i + 1].x) + abs(convexHull[i].y - convexHull[i + 1].y))
                    {
                        answer++;
                        break;
                    }
                }
                else if (ccw(convexHull[i], convexHull[i + 1], {x, y}) < 0)
                {
                    answer++;
                    break;
                }
            }
        }
        printf("#%d %d\n", testCase, answer);
    }
    return 0;
}