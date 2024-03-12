#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> adjacentList[1001];
int visited[1001] = {0};

int dfs(int s, int e)
{
    if (s == e)
        return 0;
    // cout << s << '\n';
    int retVal = 1000000000;
    for (pair<int, int> arg : adjacentList[s])
    {
        /* code */
        if (visited[arg.first] == 0)
        {
            visited[arg.first] = 1;
            int tmp = dfs(arg.first, e);
            // cout << "\t 지금 여기는 " << tmp << " \n ";
            visited[arg.first] = 0;
            if (tmp != 1000000000)
            {
                return arg.second + tmp;
            }
        }
    }
    return retVal;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1240.txt", ios_base::in);

    int N, M;
    cin >> N >> M;
    for (int j = 0; j < N - 1; j++)
    {
        int left, right, cost;
        cin >> left >> right >> cost;
        adjacentList[left].push_back(make_pair(right, cost));
        adjacentList[right].push_back(make_pair(left, cost));
    }
    for (int i = 0; i < M; i++)
    {
        // for (int j = 0; j < N; j++)
        // {
        //     visited[j] = 0;
        // }
        int A, B;
        cin >> A >> B;
        // cout << A << '\t' << B << '\n';
        visited[A] = 1;
        cout << dfs(A, B) << '\n';
        visited[A] = 0;
    }
}
