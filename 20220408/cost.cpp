#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct pos
{
    int x, y, cost;

    bool operator<(const pos &t) const
    {
        return cost > t.cost;
    }
};
vector<int> dx = {0, -1, 1, 0, 0};
vector<int> dy = {0, 0, 0, -1, 1};
vector<int> opposite = {0, 2, 1, 4, 3};

vector<vector<int>> arr, minCost;
priority_queue<pos> pq;
int main()
{
    int T, N, M, answer;
    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N >> M;
        arr.assign(N, vector<int>(M, 0));
        minCost.assign(N, vector<int>(M, INF));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> arr[i][j];
            }
        }
        minCost[0][0] = 0;
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            pos now = pq.top();
            pq.pop();

            // pq를 cost로 정렬했기 때문에 가장 먼저 이 조건문을 만족한 cost가 최솟값임을 확신할 수 있다.
            if (now.x == N - 1 && now.y == M - 1)
            {
                answer = now.cost;
                break;
            }
            for (int dir = 1; dir <= 4; dir++)
            {
                int tox = now.x + dx[dir];
                int toy = now.y + dy[dir];
                int addCost = 1;
                // addCost를 1로 초기화하여 90도 회전은 if처리를 생략할 수 있도록 함

                if (tox < 0 || toy < 0 || tox >= N || toy >= M)
                    continue;

                // 같은 방향이면 addCost는 0
                if (dir == arr[tox][toy])
                {
                    addCost = 0;
                }
                // 반대 방향이면 addCost는 2
                else if (dir == opposite[arr[tox][toy]])
                {
                    addCost = 2;
                }
                // 위의 두 조건문 모두 걸리지 않는다면 디폴트 값인 1

                // minCost에 최솟값을 저장하면서 이 최솟값보다 작다면 pq에 push
                if (now.cost + addCost < minCost[tox][toy])
                {
                    minCost[tox][toy] = now.cost + addCost;
                    pq.push({tox, toy, minCost[tox][toy]});
                }
            }
        }
        // pq 초기화
        while (!pq.empty())
        {
            pq.pop();
        }

        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}