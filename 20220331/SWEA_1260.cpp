#include <stdio.h>
#include <vector>
#include <algorithm>
#include<iostream>
#define INF 987654321
using namespace std;

int N, answer, matCnt;
int arr[100][100];
bool isFindPermutation;
// 각 subtmatrix를 row,col와 해당 row,col을 가진 matrix의 cnt와 함께 저장
struct SutMatrix
{
    int row, col, cnt;
};
vector<SutMatrix> subMatrixes;
vector<vector<int>> M;
vector<int> permutation;

void addMatrix(int x, int y)
{
    int row = 1, col = 1;
    while (x + row < N)
    {
        if (arr[x + row][y] == 0)
            break;
        row++;
    }
    while (y + col < N)
    {
        if (arr[x][y + col] == 0)
            break;
        col++;
    }

    for (int i = x; i < x + row; i++)
    {
        for (int j = y; j < y + col; j++)
        {
            arr[i][j] = 0;
        }
    }

    int len = subMatrixes.size();
    bool find = false;

    // row,col인 submatrix가 이미 존재한다면 cnt++
    for (int i = 0; i < len; i++)
    {
        if (row == subMatrixes[i].row && col == subMatrixes[i].col)
        {
            subMatrixes[i].cnt++;
            find = true;
            break;
        }
    }
    // 존재하지 않는다면 cnt를 1로 하여 추가
    if (!find)
    {
        subMatrixes.push_back({row, col, 1});
    }
}

int getMCM()
{
    int Size = permutation.size() - 1;
    M.assign(Size + 1, vector<int>(Size + 1, 0));

    for (int r = 2; r <= Size; r++)
    {
        for (int i = 1; i <= Size - r + 1; i++)
        {
            int j = i + r - 1;
            M[i][j] = INF;
            for (int k = i; k < j; k++)
            {
                M[i][j] = min(M[i][j], M[i][k] + M[k + 1][j] + permutation[i - 1] * permutation[k] * permutation[j]);
            }
        }
    }
    return M[1][Size];
}
void makePermutation(int now, int cnt)
{
    if(isFindPermutation){
        return;
    }
    else if (cnt == matCnt)
    {
        answer = min(answer, getMCM());
        isFindPermutation=true;
    }
    else
    {
        int len = subMatrixes.size();
        for (int i = 0; i < len; i++)
        {
            // i번째 subMat가 개수가 남아있고, now의 col과 다음 subMat의 row가 일치하여 곱할 수 있는지 확인한다.
            if (subMatrixes[i].cnt && subMatrixes[now].col == subMatrixes[i].row)
            {
                subMatrixes[i].cnt--;
                permutation.push_back(subMatrixes[i].col);
                makePermutation(i, cnt + 1);
                permutation.pop_back();
                subMatrixes[i].cnt++;
            }
        }
    }
}
int main()
{
    int T, a, b;
    scanf("%d", &T);

    for (int testCase = 1; testCase <= T; testCase++)
    {
        scanf("%d", &N);
        answer = INF;
        matCnt = 0;
        isFindPermutation=false;
        permutation.clear();
        subMatrixes.clear();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        // submatrix 찾기
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (arr[i][j])
                {
                    addMatrix(i, j);
                    matCnt++;
                }
            }
        }

        // 가능한 행렬곱 순열 생성
        // 첫번째 행렬을 반복문으로 넣어주어 makePermutation 함수에서 이전 행렬의 col을 확인하며 행렬곱이 가능한지 확인하는 과정에서,
        // 이전 행렬이 존재하는지 확인하는 과정을 없애주기 위해 첫번째 행렬을 반복문으로 넣어주며 시작한다.
        int len = subMatrixes.size();
        for (int i = 0; i < len&&!isFindPermutation; i++)
        {
            subMatrixes[i].cnt--;
            permutation.push_back(subMatrixes[i].row);
            permutation.push_back(subMatrixes[i].col);
            makePermutation(i, 1);
            permutation.pop_back();
            permutation.pop_back();
            subMatrixes[i].cnt++;
        }

        printf("#%d %d\n", testCase, answer);
    }

    return 0;
}