#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heights;

int getNumOfViews(int index)
{
    int min_height = max(max(heights[index - 1], heights[index - 2]), max(heights[index + 1], heights[index + 2]));
    if (heights[index] > min_height)
    {
        return heights[index] - min_height;
    }
    else
        return 0;
}
int main()
{
    int T = 10;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        int N, answer = 0;
        cin >> N;
        heights.resize(N, 0);

        for (int i = 0; i < N; i++)
        {
            cin >> heights[i];
        }

        for (int i = 2; i < N - 2; i++)
        {
            answer += getNumOfViews(i);
        }

        cout << "#" << test_case << " " << answer << endl;
    }
    return 0;
}