#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<bool>> checked;
int answer, exchangedCnt;

void exchange(string number, int cnt)
{
    if (cnt == exchangedCnt)
    {
        answer = max(answer, stoi(number));
        return;
    }
    string exchangedString;
    char tmp;
    int exchangedNumber;
    for (int i = 0; i < number.length() - 1; i++)
    {
        for (int j = i + 1; j < number.length(); j++)
        {
            exchangedString = number;
            exchangedString[i] = number[j];
            exchangedString[j] = number[i];
            exchangedNumber = stoi(exchangedString);

            if (!checked[exchangedNumber][cnt])
            {
                checked[exchangedNumber][cnt] = true;
                exchange(exchangedString, cnt + 1);
            }
        }
    }
}
int main()
{
    int T, size;
    string number;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> number >> exchangedCnt;
        size = 1;
        answer = 0;
        for (int i = 0; i < number.length(); i++)
        {
            size *= 10;
        }
        checked.assign(size, vector<bool>(exchangedCnt + 1, false));
        checked[stoi(number)][0] = true;
        exchange(number, 0);

        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}