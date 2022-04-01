// 5616909	ksw1220	1151	정답!	976 KB	26 ms	CPP	2011 B	2022-04-01 16:05:33
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

struct poi
{
    int x, y;
};
int ccw(poi a, poi b, poi c)
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
vector<poi> points;
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

stack<poi> st;
int main()
{
    int N, x, y, startIdx, answer = 0;
    poi start = {10001, 10001};
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

    points.erase(points.begin() + startIdx);
    points.insert(points.begin(), start);

    // poinst[0]에 대한 기울기로 정렬
    sort(points.begin() + 1, points.end(), cmp);

    // convex hull 생성
    st.push(points[0]);
    st.push(points[1]);
    st.push(points[2]);
    poi top, nextToTop;
    for (int i = 3; i < N; i++)
    {
        top = st.top();
        st.pop();
        nextToTop = st.top();
        while (ccw(nextToTop, top, points[i]) <= 0)
        {
            st.pop();
            top = nextToTop;
            nextToTop = st.top();
        }
        st.push(top);
        st.push(points[i]);
    }
    top = st.top();
    st.pop();
    nextToTop = st.top();
    while (st.size() > 1)
    {
        answer += ccw(points[0], nextToTop, top);
        st.pop();
        top = nextToTop;
        nextToTop = st.top();
    }
    answer /= 2;
    printf("%d\n", answer);
    return 0;
}