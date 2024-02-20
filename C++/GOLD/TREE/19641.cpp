#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> relatedList[100001];
int leftlist[100001] = {0};
int rightlist[100001] = {0};

int dfs(int node, int val)
{
    leftlist[node] = val;
    for (int i : relatedList[node])
    {
        if (!leftlist[i])
        {
            val = dfs(i, val + 1);
        }
    }
    rightlist[node] = val + 1;
    return val + 1;
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("19641.txt", ios_base::in);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;

        int c;
        while (1)
        {
            cin >> c;
            if (c == -1)
            {
                break;
            }
            relatedList[n].push_back(c);
        }
        sort(
            relatedList[n].begin(), relatedList[n].end(), [](int a, int b)
            { return a < b; });
    }

    int s;
    cin >> s;
    dfs(s, 1);
    for (int i = 1; i <= N; i++)
    {
        cout << i << ' ' << leftlist[i] << ' ' << rightlist[i] << '\n';
    }
}