#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, T, target;
    cin >> N;

    numbers.assign(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> target;
        int idx = lower_bound(numbers.begin(), numbers.end(), target) - numbers.begin();
        if (idx < N && numbers[idx] == target)
        {
            cout << idx + 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}