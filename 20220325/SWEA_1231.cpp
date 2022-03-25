#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    int leftChild, rightChild;
    string alphabet;
};

vector<Node> tree;

// 문자열 처리를 위한 코드
void addNode(int nodeIdx, string input)
{
    Node tmpNode;
    tmpNode.leftChild = tmpNode.rightChild = 0;
    input += " ";
    int idx = input.find(" ");
    input = input.substr(idx + 1, input.length() - idx - 1);

    idx = input.find(" ");
    tmpNode.alphabet = input.substr(0, idx);
    input = input.substr(idx + 1, input.length() - idx - 1);

    if (!input.empty())
    {
        idx = input.find(" ");
        tmpNode.leftChild = stoi(input.substr(0, idx));
        input = input.substr(idx + 1, input.length() - idx - 1);
    }
    if (!input.empty())
    {
        idx = input.find(" ");
        tmpNode.rightChild = stoi(input.substr(0, idx));
        input = input.substr(idx + 1, input.length() - idx - 1);
    }

    tree[nodeIdx]=tmpNode;
}

void inorderTraversal(int n)
{
    Node now = tree[n];

    if (now.leftChild)
    {
        inorderTraversal(now.leftChild);
    }
    cout << now.alphabet;
    if (now.rightChild)
    {
        inorderTraversal(now.rightChild);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, idx;
    string input;

    for (int testCase = 1; testCase <= 10; testCase++)
    {
        tree.clear();
        tree.assign(N+1,{0,0,"0"});
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin>>idx;
            getline(cin, input);
            addNode(idx, input);
        }
        cout<<"#"<<testCase<<" ";
        inorderTraversal(1);
        cout<<endl;
    }

    return 0;
}