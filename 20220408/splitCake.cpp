#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 300000
#define INF 300000000
using namespace std;

struct section
{
    int start, end, sum;

    bool operator<(const section &t) const
    {
        return sum < t.sum;
    }
};
vector<int> A, B;
priority_queue<section> pqA, pqB;
int main()
{
    int T, N, M, answer, acc, maxAcc, start, maxIdx;
    int left, right;
    scanf("%d", &T);
    A.assign(MAX, 0);
    B.assign(MAX, 0);

    for (int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++)
        {
            scanf("%d", &B[i]);
        }

        acc = start = maxIdx = 0;
        left = right = 0;
        maxAcc = -INF;
        while (left <= right)
        {
            // 오른쪽으로 구간을 늘리는 것이 이득이라면
            if (acc + A[right] > 0)
            {
                acc += A[right];
                if (maxAcc < acc)
                {
                    maxAcc = acc;
                    maxIdx = right;
                }
            }
            else{
                
            }
        }

        while (!pqA.empty())
        {
            printf("%d %d %d\n", pqA.top().start, pqA.top().end, pqA.top().sum);
            pqA.pop();
        }
    }
    return 0;
}