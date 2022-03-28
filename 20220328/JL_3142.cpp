// 5607809	ksw1220	3142	정답!	5,800 KB	2126 ms	CPP	2045 B	2022-03-28 15:51:52
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
std::map<string, int>::iterator it;

map<string, int> members;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, cmd, loginCnt = 0;
    string ID;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cmd >> ID;
        it = members.find(ID);
        if (cmd == 1)
        {
            if (it != members.end())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (cmd == 2)
        {
            if (it != members.end() && (*it).second==2)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (cmd == 3)
        {
            if (it == members.end())
            {
                members[ID] = 1;
            }
            cout << members.size() << endl;
        }
        else if (cmd == 4)
        {
            if (it != members.end())
            {
                if ((*it).second == 2)
                {
                    loginCnt--;
                }
                members.erase(it);
            }
            cout << members.size() << endl;
        }
        else if (cmd == 5)
        {
            if (it != members.end())
            {
                if ((*it).second == 1)
                {
                    (*it).second = 2;
                    loginCnt++;
                }
            }
            cout << loginCnt << endl;
        }
        else if (cmd == 6)
        {
            if (it != members.end())
            {
                if ((*it).second == 2)
                {
                    (*it).second = 1;
                    loginCnt--;
                }
            }
            cout << loginCnt << endl;
        }
    }
    return 0;
}
