#include <iostream>
#include <vector>

#define SIZE 18
using namespace std;
vector<int> isPrime = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0};
vector<vector<int>> comb;

void initComb()
{
    comb.assign(SIZE + 1, vector<int>(SIZE + 1, 0));
    for (int i = 0; i <= SIZE; i++)
    {
        comb[i][0] = comb[i][i] = 1;
    }
    for (int i = 2; i <= SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

int main()
{
    cout << fixed;
    cout.precision(6);
    int T;
    double answer, skillOfMasterA, skillOfMasterB, probabilityOfMasterA, probabilityOfMasterB;
    double proprobabilityPrimeA, proprobabilityPrimeB, tmpA, tmpB;

    initComb();

    cin >> T;
    for (int testCase = 1; testCase <= T; testCase++)
    {
        cin >> skillOfMasterA >> skillOfMasterB;

        probabilityOfMasterA = skillOfMasterA / 100;
        probabilityOfMasterB = skillOfMasterB / 100;

        proprobabilityPrimeA = proprobabilityPrimeB = 0;

        for (int i = 0; i <= SIZE; i++)
        {
            if (!isPrime[i])
                continue;

            tmpA = tmpB = (double)comb[SIZE][i];
            for (int j = 0; j < i; j++)
            {
                tmpA *= probabilityOfMasterA;
                tmpB *= probabilityOfMasterB;
            }
            for (int j = i; j < SIZE; j++)
            {
                tmpA *= (1 - probabilityOfMasterA);
                tmpB *= (1 - probabilityOfMasterB);
            }

            proprobabilityPrimeA += tmpA;
            proprobabilityPrimeB += tmpB;
        }

        answer=proprobabilityPrimeA+proprobabilityPrimeB-proprobabilityPrimeA*proprobabilityPrimeB;
        cout << "#" << testCase << " " << answer << endl;
    }
    return 0;
}