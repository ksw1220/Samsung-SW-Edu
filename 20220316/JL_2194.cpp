#include <iostream>
#include <vector>

using namespace std;
vector<int> C, Y;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, S;
    long long answer = 0;
    cin >> N >> S;
    C.resize(N);
    Y.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> C[i] >> Y[i];
    }
    answer += C[0] * Y[0];

    for (int i = 1; i < N; i++)
    {
        // i-1번째 가격으로 구매
        if (C[i] > C[i - 1] + S)
        {
            C[i] = C[i - 1] + S;
        }
        answer += C[i] * Y[i];
    }

    cout << answer << endl;
    return 0;
}