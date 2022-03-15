#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<string> code;
map<string, int> codeToInt;
vector<int> getNumbers(int x, int y)
{
    vector<int> numbers;
    for (int i = 0; i < 8; i++)
    {
        string tmp = code[x].substr(y + i * 7, 7);
        numbers.push_back(codeToInt[tmp]);
    }
    return numbers;
}

void init()
{
    codeToInt["0001101"] = 0;
    codeToInt["0011001"] = 1;
    codeToInt["0010011"] = 2;
    codeToInt["0111101"] = 3;
    codeToInt["0100011"] = 4;
    codeToInt["0110001"] = 5;
    codeToInt["0101111"] = 6;
    codeToInt["0111011"] = 7;
    codeToInt["0110111"] = 8;
    codeToInt["0001011"] = 9;
}

int isValid(vector<int> &numbers)
{
    int valid = (numbers[0] + numbers[2] + numbers[4] + numbers[6]) * 3;
    valid += numbers[1] + numbers[3] + numbers[5] + numbers[7];

    if (valid % 10 == 0)
    {
        return numbers[0] + numbers[2] + numbers[4] + numbers[6] + numbers[1] + numbers[3] + numbers[5] + numbers[7];
    }
    else
        return 0;
}
int main()
{
    int T, N, M;
    scanf("%d", &T);
    init();
    for (int test_case = 1; test_case <= T; test_case++)
    {
        vector<int> numbers;
        int x, y;
        bool chk = false;
        scanf("%d %d", &N, &M);
        code.resize(N);
        for (int i = 0; i < N; i++)
        {
            cin >> code[i];
        }

        // find loc(linear)

        for (int i = 0; i < N; i++)
        {
            if (chk)
                break;
            for (int j = M - 1; j >= 0; j--)
            {
                if (code[i][j] == '1')
                {
                    numbers = getNumbers(i, j - 55);
                    chk = true;
                    break;
                }
            }
        }

        cout << "#" << test_case << " " << isValid(numbers) << endl;
    }
    return 0;
}