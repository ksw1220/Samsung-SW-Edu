// 5616606	ksw1220	1129	정답!	908 KB	3 ms	CPP	1275 B	2022-04-01 14:49:04
#include <stdio.h>
#include <vector>

using namespace std;

struct poi
{
    int x, y;
    bool operator<(const poi &t) const
    {
        if (x == t.x)
            return y < t.y;
        return x < t.x;
    }
};
int ccw(poi a, poi m, poi b)
{
    int t = (a.x - m.x) * (b.y - m.y) - (a.y - m.y) * (b.x - m.x);
    return (t < 0) - (t > 0);
}

bool isCross(poi a, poi b, poi c, poi d)
{
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0)
    {
        if (b < a)
        {
            swap(a, b);
        }
        if (d < c)
        {
            swap(c, d);
        }
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}
vector<pair<poi, poi>> lines;
int main()
{
    int N, answer = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        poi tmp1, tmp2;
        scanf("%d %d %d %d", &tmp1.x, &tmp1.y, &tmp2.x, &tmp2.y);
        lines.push_back({tmp1, tmp2});
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            answer += isCross(lines[i].first, lines[i].second, lines[j].first, lines[j].second);
        }
    }
    printf("%d\n", answer);
    return 0;
}