#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define INF 987654321
using namespace std;

vector<pair<int, int>> locations;
vector<bool> visited;

int N, answer;
void dfs(int now, int cnt, int dist)
{
    if (dist > answer)
    {
        return;
    }
    else if (cnt == N)
    {
        answer = min(answer, dist + abs(locations[now].first - locations[N + 1].first) + abs(locations[now].second - locations[N + 1].second));
        return;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                dfs(i, cnt + 1, dist + abs(locations[now].first - locations[i].first) + abs(locations[now].second - locations[i].second));
                visited[i] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;

    cin >> T;

    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N;
        locations.resize(N + 2);
        visited.assign(N + 1, false);
        answer = INF;

        // locations[0] 에는 집의 좌표, locations[N+1]에는 회사의 좌표
        cin >> locations[0].first >> locations[0].second >> locations[N + 1].first >> locations[N + 1].second;
        for (int i = 1; i <= N; i++)
        {
            cin >> locations[i].first >> locations[i].second;
        }

        dfs(0, 0, 0);

        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}