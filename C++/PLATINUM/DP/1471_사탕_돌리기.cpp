#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited{};
vector<int> DP{};
vector<int> DPP{};

int N;

pair<int, int> DFS(int cord)
{
    printf("%d 먼저 실행합니다 \n", cord);
    if (visited[cord])
    {
        if (!DPP[cord])
        {
            printf("case 1 \n");
            DPP[cord] = cord;
            return {DPP[cord], 1};
        }
        return {DPP[cord], 0};
    }
    else
    {
        visited[cord]++;
    }
    int next = cord;
    int cordCopy = cord;
    while (cordCopy)
    {
        next += cordCopy % 10;
        cordCopy /= 10;
    }
    if (next > N)
    {
        next -= N;
    }
    if (next == cord)
    {
        printf("case 1 \n");
        DPP[cord] = cord;
        DP[cord]++;
        return {DPP[cord], 0};
    }
    pair<int, int> tmp = DFS(next);

    if (tmp.second)
    {
        if (tmp.first == cord)
        {
            DP[cord]++;
            return {cord, 0};
        }
        DPP[cord] = tmp.first;
        DP[tmp.first]++;
        printf("case 3 \n");
    }
    else
    {
        DPP[cord] = cord;
        if (DPP[next] == next)
        {
            DP[cord] = DP[next] + 1;
        }
        else
        {
            DP[cord] = DP[DPP[next]] + 1;
        }
        printf("case 4 \n");
    }
    return tmp;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1471.txt", ios_base::in);

    cin >> N;

    visited = vector<int>(N + 1, 0);
    DP = vector<int>(N + 1, 0);
    DPP = vector<int>(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }

    int MVal = 0;
    for (int i = 1; i <= N; i++)
    {
        printf("DPP와 DP %d { %d, %d } \n", i, DPP[i], DP[i]);
        MVal = max(MVal, DP[i]);
    }
    cout << MVal;
}