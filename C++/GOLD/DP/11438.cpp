#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int logStore[100001][20];

// int findNthParent(int N, int node)
// {
// int maxInThisProblem = 20;
//
// if (node == 1)
// return 0;
// if (N == 0)
// return logStore[node][1];
// return findNthParent(N - 1, logStore[node][N - 1]);
// }
//
int visited[100001];
int depth[100001];
vector<int> adjList[100001];

void dfs(int n, int dep)
{
    visited[n] = 1;
    depth[n] = dep;

    for (int i : adjList[n])
    {
        if (!visited[i])
        {
            logStore[i][0] = n;
            dfs(i, dep + 1);
        }
        /* code */
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("11438.txt", ios_base::in);
    int N;
    cin >> N;

    // cout << maxLog << '\n';
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        // cout << a << '\t' << b << '\n';
        // logStore[b][1] = a;
        adjList[b].push_back(a);
        adjList[a].push_back(b);
    }
    dfs(1, 0);
    // for (int i = 1; i < N; i++)
    // {
    //     if (logStore[i][1] == 0)
    //     {
    //         logStore[i][1] = 1;
    //     }
    // }

    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            logStore[j][i] = logStore[logStore[j][i - 1]][i - 1];
        }
    }
    //
    // for (int i = 1; i <= N; i++)
    // {
    // cout << logStore[i][0] << '\t';
    // }
    //
    // cout << '\n';
    // for (int i = 1; i <= N; i++)
    // {
    // cout << logStore[i][1] << '\t';
    // }
    // cout << '\n';
    // for (int i = 1; i <= N; i++)
    // {
    // cout << logStore[i][2] << '\t';
    // }
    // cout << '\n';
    // for (int i = 1; i <= N; i++)
    // {
    // cout << logStore[i][3] << '\t';
    // }
    //
    int numOfOutput;
    cin >> numOfOutput;
    for (int output = 0; output < numOfOutput; output++)
    {
        int small, large;
        cin >> small >> large;
        if (depth[small] > depth[large])
        {
            swap(small, large);
        }
        while (depth[small] < depth[large])
        {
            // cout << depth[small] << '\t' << depth[large] << '\t' << depth[logStore[large][0]] << '\n';
            for (int changable = 19; changable >= 0; changable--)
            {
                if (logStore[large][changable] != 0 && depth[logStore[large][changable]] >= depth[small])
                {
                    // cout << depth[logStore[large][changable]] << '\t' << depth[small] << '\n';
                    large = logStore[large][changable];
                }
            }
        }
        // cout << "높이맞추기 결과" << small << large << '\n';
        if (small == large)
        {
            cout << small << '\n';
        }
        else
        {
            for (int changable = 19; changable >= 0; changable--)
            {
                if (logStore[small][changable] != 0 && logStore[small][changable] != logStore[large][changable])
                {
                    // cout << small << '\t' << large << '\t' << changable << '\n';
                    small = logStore[small][changable];
                    large = logStore[large][changable];
                }
            }
            // cout << "부모 같을 때까지 돌린결과 결과" << small << large << '\n';
            cout << logStore[small][0] << '\n';
        }

        // if (small > large)
        // {
        //     swap(small, large);
        // }
        // while (small != large)
        // {
        //     // cout << small << large << '\n';
        //     while (small < large)
        //     {
        //         bool isChanged = false;
        //         cout << '\t' << small << '\t' << large << '\n';
        //         for (int changable = 20; changable >= 0; changable--)
        //         {
        //             if (logStore[large][changable] > small)
        //             {
        //                 large = logStore[large][changable];
        //                 isChanged = true;
        //                 break;
        //             }
        //         }
        //         if (isChanged == false)
        //         {
        //             large = logStore[large][0];
        //         }
        //     }
        //     if (small > large)
        //     {
        //         swap(small, large);
        //     }
        // }
        // cout << small << '\n';
    }
}