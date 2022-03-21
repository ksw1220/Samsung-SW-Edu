#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> suffixArray;
vector<int> LCP;
int getLCP(string a, string b)
{
    int idx = 0;
    int minLen = min(a.length(), b.length());
    while (idx <= minLen)
    {
        if (a[idx] != b[idx])
        {
            break;
        }
        idx++;
    }
    return idx;
}
int main()
{
    int T, K;
    string str, answer;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> K;
        cin >> str;

        int len = str.length();
        answer = "none";

        suffixArray.resize(len);
        LCP.resize(len);

        for (int i = 0; i < len; i++)
        {
            suffixArray[i] = str.substr(i, len - i);
        }

        sort(suffixArray.begin(), suffixArray.end());

        LCP[0] = 0;
        for (int i = 1; i < len; i++)
        {
            LCP[i] = getLCP(suffixArray[i - 1], suffixArray[i]);
        }

        for (int i = 0; i < len; i++)
        {
            int numOfSubstr = (suffixArray[i].length() - LCP[i]);
            // cout << suffixArray[i] << " " << numOfSubstr <<" "<< K<<endl;
            if (K > numOfSubstr)
            {
                K -= numOfSubstr;
            }
            else
            {
                answer = suffixArray[i].substr(0, LCP[i] + K);
                break;
            }
        }
        // for(int i=0;i<len;i++){
        //     cout<<suffixArray[i]<<" "<<LCP[i]<<endl;
        // }

        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}