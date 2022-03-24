#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int start, end;
    double weight;

    // weight에 대한 오름차순
    bool operator<(const Edge &edge) const
    {
        return weight > edge.weight;
    }
};
vector<vector<double>> dist;
vector<double> xs, ys;
vector<int> parent;
priority_queue<Edge> pq;

int find(int n)
{
    if (n == parent[n])
    {
        return n;
    }
    else
    {
        return parent[n] = find(parent[n]);
    }
}

long long answer;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed;
    cout.precision(0);
    int T, N;
    double E;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        // 벡터 초기화
        answer = 0.0;
        cin >> N;
        xs.resize(N);
        ys.resize(N);
        dist.assign(N, vector<double>(N, 0.0));
        parent.resize(N);

        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
        }

        // 입력
        for (int i = 0; i < N; i++)
        {
            cin >> xs[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> ys[i];
        }
        cin >> E;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    dist[i][j] = ((xs[i] - xs[j]) * (xs[i] - xs[j]) + (ys[i] - ys[j]) * (ys[i] - ys[j]));
                }
            }
        }
        
        // 0번 좌표를 기준으로 1~N-1번 과의 Edge를 pq에 푸쉬 

        for (int i = 1; i < N; i++)
        {
            pq.push({0, i, dist[0][i]});
        }

        while (!pq.empty())
        {
            Edge now = pq.top();
            pq.pop();

            int pStart = find(now.start);
            int pEnd = find(now.end);

            if (pStart != pEnd)
            {
                answer += now.weight;
                parent[pEnd] = pStart;
                for (int i = 0; i < N; i++)
                {
                    if (now.end != i)
                    {
                        pq.push({now.end, i, dist[now.end][i]});
                    }
                }
            }
        }

        cout << "#" << testCase << " " << answer * E << endl;
    }

    return 0;
}