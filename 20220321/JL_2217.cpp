#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> DNA;
vector<bool> checked;
int N, answer = 987654321;

// 두 문자열의 공통된 길이를 구하는 함수
int getCommonLen(string now, string next)
{
    int nowLen = now.length(), nextLen = next.length();
    int len = min(nowLen, nextLen);
    int cnt;
    for (cnt = len; cnt > 0; cnt--)
    {
        if (now.substr(nowLen - cnt, cnt) == next.substr(0, cnt))
        {
            break;
        }
    }
    return cnt;
}
// 순열에 따르며 문자열을 이어 나가는 함수
void mergeDNA(int idx, int cnt, string now)
{
    if (cnt == N)
    {
        answer = min(answer, (int)now.length());
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!checked[i])
        {
            string next = DNA[i];
            checked[i] = true;
            int commonLen = getCommonLen(DNA[idx], DNA[i]);
            mergeDNA(i, cnt + 1, now + DNA[i].substr(commonLen, DNA[i].length() - commonLen));
            checked[i] = false;
        }
    }
}
int main()
{
    vector<int> v;
    cin >> N;
    DNA.resize(N);
    checked.assign(N, false);
    for (int i = 0; i < N; i++)
    {
        cin >> DNA[i];
    }

    for (int i = 0; i < N; i++)
    {
        checked[i] = true;
        mergeDNA(i, 1, DNA[i]);
        checked[i] = false;
    }
    cout << answer << endl;
    return 0;
}
