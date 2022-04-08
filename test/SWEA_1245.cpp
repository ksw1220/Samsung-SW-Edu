#include <iostream>
#include <vector>
#define ERROR 1e-12
using namespace std;

vector<pair<double, double>> planetes;
vector<double> answer;
int main()
{
    cout << fixed;
    cout.precision(10);
    int T, N;
    double left, right, mid, gravity, dist;
    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> N;
        planetes.resize(N);
        answer.clear();
        for (int i = 0; i < N; i++)
        {
            cin >> planetes[i].first;
        }

        for (int i = 0; i < N; i++)
        {
            cin >> planetes[i].second;
        }

        for (int i = 0; i < N - 1; i++)
        {
            left = planetes[i].first;
            right = planetes[i + 1].first;
            while (right - left >= ERROR)
            {
                mid = (left + right) / 2;
                gravity = 0;

                for (int j = 0; j < N; j++)
                {
                    dist = planetes[j].first - mid;
                    if (dist > 0)
                    {
                        gravity += planetes[j].second / (dist) / (dist);
                    }
                    else if (dist < 0)
                    {
                        gravity -= planetes[j].second / (dist) / (dist);
                    }
                }
                if (gravity == 0)
                {
                    break;
                }
                else if (gravity > 0)
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
            answer.push_back(mid);
        }
        cout << "#" << testCase;
        for (int i = 0; i < answer.size(); i++)
        {
            cout << " " << answer[i];
        }
        cout << endl;
    }
    return 0;
}