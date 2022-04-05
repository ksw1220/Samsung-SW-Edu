#include <iostream>
#include <vector>

#define MAX_N 1000000
#define MOD 100000007
using namespace std;

vector<long long> dp, accEven;
int main()
{
    int T, N, X, Y, answer;

    dp.assign(MAX_N + 1, 0);
    dp = {1,0,3,2,};
    accEven.assign(MAX_N + 1, 0);
    accEven[0] = 1;
    // dp 배열 초기화
    for (int i = 4; i <= MAX_N; i++)
    {
        if (i % 2 == 0)
        {
            dp[i] = (dp[i - 1] + dp[i - 2] * 3) % MOD;
        }
        else
        {
            dp[i] = (dp[i - 2] + dp[i - 3] * 2) % MOD;
        }
    }
    // dp 배열의 짝수 누적합 accEven을 초기화
    for (int i = 2; i <= MAX_N; i += 2)
    {
        accEven[i] = (accEven[i - 2] + dp[i]) % MOD;
    }

    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N >> X >> Y;
        int left = X, right = N - X + 1;
        if (left % 2 != right % 2)
        {
            answer = 0;
        }
        // left%2 == right%2 가 보장되므로 left의 나머지만 확인
        else if (left % 2 == 1)
        {
            if (Y == 2)
            {
                answer = 0;
            }
            else
            {
                answer = dp[left - 1] * accEven[right - 1] % MOD + dp[right - 1] * accEven[left - 1] % MOD;
                // dp[left - 1] * dp[right - 1]이 중복하여 더해졌으므로 빼 준다.
                // 이 때 answer에서 빼준 값이 음수가되어 나머지 연산값이 음수가 나오는 것을 피하기 위해 MOD를 더한 후 연산을 한다.
                answer = answer + MOD - (dp[left - 1] * dp[right - 1]) % MOD;
            }
        }
        else
        {
            if (Y == 2)
            {
                answer = (accEven[left - 2] * accEven[right - 2]) % MOD * 2;
            }
            else
            {
                answer = 0;
            }
        }
        cout << "#" << testCase << " " << answer % MOD << endl;
    }
    return 0;
}