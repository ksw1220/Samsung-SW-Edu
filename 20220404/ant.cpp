#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Ant
{
    int x, y, d, idx;
};
struct RightAnt
{
    int x, y, idx;

    bool operator<(const RightAnt &t) const
    {
        if (x == t.x)
        {
            return y < t.y;
        }
        else
        {
            return x > t.x;
        }
    }
};

int N;
vector<Ant> ants;
// 오른쪽으로 이동하는 개미만을 저장하는 rightAnts
vector<RightAnt> rightAnts;

int getAntIdx(int now, int limitTime)
{
    int collsionTime = 0, tmpCollsionTime, idx;
    // 가독성을 위한 변수
    int x, y, nx, ny;
    x = ants[now].x;
    y = ants[now].y;
    for (int i = 0; i < N; i++)
    {
        nx = ants[i].x;
        ny = ants[i].y;
        tmpCollsionTime = 0;
        if (i == now)
            continue;

        // 충돌 여부와 확인과 collsionTime을 갱신
        if (ants[now].d == 1)
        {
            if (ants[i].d == 2 && x == nx)
            {
                tmpCollsionTime = ny - y;
            }
            else if (ants[i].d == 3 && x - nx == y - ny)
            {
                tmpCollsionTime = nx - x;
            }
            else if (ants[i].d == 4 && x - nx == ny - y)
            {

                tmpCollsionTime = x - nx;
            }
        }
        else if (ants[now].d == 2)
        {
            if (ants[i].d == 1 && x == nx)
            {
                tmpCollsionTime = y - ny;
            }
            else if (ants[i].d == 3 && x - nx == ny - y)
            {
                tmpCollsionTime = nx - x;
            }
            else if (ants[i].d == 4 && x - nx == y - ny)
            {
                tmpCollsionTime = x - nx;
            }
        }
        else if (ants[now].d == 3)
        {
            if (ants[i].d == 4 && y == ny)
            {
                tmpCollsionTime = x - nx;
            }
            else if (ants[i].d == 1 && x - nx == y - ny)
            {
                tmpCollsionTime = nx - x;
            }
            else if (ants[i].d == 2 && x - nx == ny - y)
            {
                tmpCollsionTime = x - nx;
            }
        }
        else
        {
            if (ants[i].d == 3 && y == ny)
            {
                tmpCollsionTime = nx - x;
            }
            else if (ants[i].d == 1 && x - nx == ny - y)
            {
                tmpCollsionTime = nx - x;
            }
            else if (ants[i].d == 2 && x - nx == y - ny)
            {
                tmpCollsionTime = nx - x;
            }
        }

        // now번째 개미가 충돌한 개미 중 limitTime 이전에 충돌하였고 가장 마지막에 충돌한 개미의 index를 저장
        if (tmpCollsionTime < limitTime && tmpCollsionTime > collsionTime)
        {
            collsionTime = tmpCollsionTime;
            idx = i;
        }
    }

    // now번째 개미가 limitTime 전에 충돌한 개미가 없으므로 now를 리턴한다.
    if (collsionTime == 0)
    {
        return now;
    }
    // 충돌한 개미가 존재한다면 idx를 기준으로 재귀함수를 실행한다.
    else
    {
        return getAntIdx(idx, collsionTime);
    }
}
int main()
{
    int T, M, K, answer, answerTime;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> M >> N >> K;
        ants.assign(N, {0, 0, 0});
        rightAnts.clear();
        for (int i = 0; i < N; i++)
        {
            cin >> ants[i].x >> ants[i].y >> ants[i].d;
            ants[i].idx = i;
            if (ants[i].d == 4)
            {
                rightAnts.push_back({ants[i].x, ants[i].y, i});
            }
        }

        sort(rightAnts.begin(), rightAnts.end());
        if (K > rightAnts.size())
        {
            answer = answerTime = 0;
        }
        else
        {
            Ant start = ants[rightAnts[K - 1].idx];

            int limitTime = answerTime = M - start.x;

            // 0번 인덱스 부터 시작했으므로 1을 더해준다.
            answer = getAntIdx(start.idx, limitTime) + 1;
        }
        cout << "#" << testCase << " " << answerTime << " " << answer << endl;
    }
    return 0;
}