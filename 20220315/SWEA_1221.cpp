#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> strToNum;
vector<int> numbers;
vector<string> numToStr = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
// map을 통해 1의 연산만으로 문자열을 숫자로 변환
void initMap()
{
    strToNum["ZRO"] = 0;
    strToNum["ONE"] = 1;
    strToNum["TWO"] = 2;
    strToNum["THR"] = 3;
    strToNum["FOR"] = 4;
    strToNum["FIV"] = 5;
    strToNum["SIX"] = 6;
    strToNum["SVN"] = 7;
    strToNum["EGT"] = 8;
    strToNum["NIN"] = 9;
}
int main()
{
    initMap();
    int T, N;
    string str, tmp;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        numbers.clear();
        cin >> tmp >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> str;
            numbers.push_back(strToNum[str]);
        }

        sort(numbers.begin(), numbers.end());

        cout << "#" << testCase << endl;
        for (int i = 0; i < N; i++)
        {
            cout << numToStr[numbers[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}