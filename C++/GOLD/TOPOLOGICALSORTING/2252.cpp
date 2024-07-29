#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2252.txt", ios_base::in);

    queue<int> thisQ;
    queue<int> nextQ;

    vector<vector<int>> adjList(32001, vector<int>{});
    vector<int> biggerCount(32001, 0);

    int isSorted = 0;
    vector<int> answer{};

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        biggerCount[b]++;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!biggerCount[i])
        {
            thisQ.push(i);
        }
    }

    while (isSorted < N)
    {
        while (!thisQ.empty())
        {
            int thisArg = thisQ.front();
            thisQ.pop();
            isSorted++;
            answer.push_back(thisArg);

            for (int nextArg : adjList[thisArg])
            {
                biggerCount[nextArg]--;
                if (!biggerCount[nextArg])
                {
                    nextQ.push(nextArg);
                }
            }
        }
        swap(thisQ, nextQ);
    }

    for (int ans : answer)
    {
        cout << ans << ' ';
    }
}