#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> dummy;
int main()
{
    string s, number, answer;
    int p, m, idx;
    bool isValid = true;
    cin >> s >> p >> m;

    s += "-";
    while (!s.empty())
    {
        idx = s.find("-");
        number = s.substr(0, idx);
        if (number.length() > 4)
        {
            isValid = false;
            break;
        }
        while (number.length() < 4)
        {
            number = "0" + number;
        }
        dummy.push_back(number);
        s = s.substr(idx + 1, s.length() - idx - 1);
    }
    if (!isValid)
    {
        answer = "INPUT ERROR!";
    }
    else
    {
        string target = dummy[m - 1];
        int len = target.length();
        for (int i = 0; i < len; i++)
        {
            answer += to_string((target[i] - '0' + p) % 10);
        }
    }
    cout << answer << endl;
    return 0;
}