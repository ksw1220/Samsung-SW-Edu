// 5599735	ksw1220	1726	정답!	2,916 KB	610 ms	CPP	1733 B	2022-03-25 17:22:42
#include <iostream>
#include <vector>

using namespace std;

typedef long long dtype;
vector<dtype> arr;
class SegmentTree
{
public:
    vector<dtype> tree;
    int s;

    SegmentTree(int n)
    {
        for (s = 1; s < n; s *= 2)
        {
        }
        tree.resize(s * 2);
        for (int i = 1; i <= s; i++)
        {
            tree[i] = 0;
        }
    }

    void insert(vector<dtype> &d)
    {
        for (int i = s; i < s + d.size(); i++)
        {
            tree[i] = d[i - s];
        }

        for (int i = s - 1; i >= 0; i--)
        {
            tree[i] = tree[i * 2] > tree[i * 2 + 1] ? tree[i * 2] : tree[i * 2 + 1];
        }
    }

    dtype getMax(int Left, int Right)
    {
        int l = Left + s - 1, r = Right + s - 1;
        dtype rval = 0;
        while (l <= r)
        {
            if (l % 2 == 0)
            {
                l /= 2;
            }
            else
            {
                rval = rval > tree[l] ? rval : tree[l];
                l = l / 2 + 1;
            }
            if (r % 2 == 1)
            {
                r /= 2;
            }
            else
            {
                rval = rval > tree[r] ? rval : tree[r];
                r = (r / 2) - 1;
            }
        }
        return rval;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q;
    int a, b;
    cin >> N >> Q;

    arr.assign(N, 0);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    SegmentTree t(N);
    t.insert(arr);

    while (Q--)
    {
        cin >> a >> b;
        cout << t.getMax(a, b) << endl;
    }
    return 0;
}