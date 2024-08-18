#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<vector<ll>> dpMin;
vector<vector<ll>> dpMax;
vector<vector<ll>> points;
int N;
/*
abs(points[r][0] - points[r + 1][0])
abs(points[r][1] - points[r + 1][1])
abs(points[r][2] - points[r + 1][2])
abs(points[r][1] - points[r][2])
abs(points[r][0] - points[r][1])

dpMin[r + 1][6] = min(dpMin[r + 1][6], dpMin[r][c]);

 */
void DP(int r, int c, bool isMin)
{
    if ((isMin && dpMin[r][c] == 30000000001) || (!isMin && dpMax[r][c] == 30000000001))
        return;
    if (c == 0)
    {
        if (isMin)
        {
            dpMin[r + 1][1] = min(dpMin[r + 1][1], dpMin[r][c] + abs(points[r][2] - points[r + 1][2]) + abs(points[r][0] - points[r][1]));
            dpMin[r + 1][4] = min(dpMin[r + 1][4], dpMin[r][c] + abs(points[r][1] - points[r][2]) + abs(points[r][0] - points[r + 1][0]));
            if (r != N - 1)
            {
                dpMin[r + 2][0] = min(dpMin[r + 2][0], dpMin[r][c] + abs(points[r][0] - points[r + 1][0]) + abs(points[r][1] - points[r + 1][1]) + abs(points[r][2] - points[r + 1][2]));
            }
        }
        else
        {
            dpMax[r + 1][1] = max(dpMax[r + 1][1], dpMax[r][c] + abs(points[r][2] - points[r + 1][2]) + abs(points[r][0] - points[r][1]));
            dpMax[r + 1][4] = max(dpMax[r + 1][4], dpMax[r][c] + abs(points[r][1] - points[r][2]) + abs(points[r][0] - points[r + 1][0]));
            if (r != N - 1)
            {
                dpMax[r + 2][0] = max(dpMax[r + 2][0], dpMax[r][c] + abs(points[r][0] - points[r + 1][0]) + abs(points[r][1] - points[r + 1][1]) + abs(points[r][2] - points[r + 1][2]));
            }
        }
    }
    else if (c == 1)
    {
        if (isMin)
        {
            dpMin[r + 1][0] = min(dpMin[r + 1][0], dpMin[r][c] + abs(points[r][0] - points[r][1]));
            dpMin[r + 1][6] = min(dpMin[r + 1][6], dpMin[r][c] + abs(points[r][0] - points[r + 1][0]) + abs(points[r][1] - points[r + 1][1]));
        }
        else
        {
            dpMax[r + 1][0] = max(dpMax[r + 1][0], dpMax[r][c] + abs(points[r][0] - points[r][1]));
            dpMax[r + 1][6] = max(dpMax[r + 1][6], dpMax[r][c] + abs(points[r][0] - points[r + 1][0]) + abs(points[r][1] - points[r + 1][1]));
        }
    }
    else if (c == 2)
    {
        if (isMin)
        {
            dpMin[r + 1][5] = min(dpMin[r + 1][5], dpMin[r][c] + abs(points[r][0] - points[r + 1][0]) + abs(points[r][2] - points[r + 1][2]));
        }
        else
        {
            dpMax[r + 1][5] = max(dpMax[r + 1][5], dpMax[r][c] + abs(points[r][0] - points[r + 1][0]) + abs(points[r][2] - points[r + 1][2]));
        }
    }
    else if (c == 3)
    {
        if (isMin)
        {
            dpMin[r + 1][4] = min(dpMin[r + 1][4], dpMin[r][c] + abs(points[r][0] - points[r + 1][0]));
        }
        else
        {
            dpMax[r + 1][4] = max(dpMax[r + 1][4], dpMax[r][c] + abs(points[r][0] - points[r + 1][0]));
        }
    }
    else if (c == 4)
    {
        if (isMin)
        {
            dpMin[r + 1][0] = min(dpMin[r + 1][0], dpMin[r][c] + abs(points[r][1] - points[r][2]));
            dpMin[r + 1][3] = min(dpMin[r + 1][3], dpMin[r][c] + abs(points[r][2] - points[r + 1][2]) + abs(points[r][1] - points[r + 1][1]));
        }
        else
        {
            dpMax[r + 1][0] = max(dpMax[r + 1][0], dpMax[r][c] + abs(points[r][1] - points[r][2]));
            dpMax[r + 1][3] = max(dpMax[r + 1][3], dpMax[r][c] + abs(points[r][2] - points[r + 1][2]) + abs(points[r][1] - points[r + 1][1]));
        }
    }
    else if (c == 5)
    {
        if (isMin)
        {
            dpMin[r + 1][2] = min(dpMin[r + 1][2], dpMin[r][c] + abs(points[r][1] - points[r + 1][1]));
        }
        else
        {
            dpMax[r + 1][2] = max(dpMax[r + 1][2], dpMax[r][c] + abs(points[r][1] - points[r + 1][1]));
        }
    }
    else if (c == 6)
    {
        if (isMin)
        {
            dpMin[r + 1][1] = min(dpMin[r + 1][1], dpMin[r][c] + abs(points[r][2] - points[r + 1][2]));
        }
        else
        {
            dpMax[r + 1][1] = max(dpMax[r + 1][1], dpMax[r][c] + abs(points[r][2] - points[r + 1][2]));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1852.txt", ios_base::in);

    cin >> N;

    dpMin = vector<vector<ll>>(N + 1, vector<ll>(7, 30000000001));
    dpMax = vector<vector<ll>>(N + 1, vector<ll>(7, -30000000001));
    points = vector<vector<ll>>(N + 1, vector<ll>(3, 0));

    dpMax[0][0] = 0;
    dpMin[0][0] = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            DP(i, j, true);
            DP(i, j, false);
        }
    }
    ll answer = 0;
    answer = max(dpMax[N - 1][1] + abs(points[N - 1][0] - points[N - 1][1]), dpMax[N - 1][4] + abs(points[N - 1][1] - points[N - 1][2]));
    answer = max(answer, dpMax[N][0]);
    cout << answer << '\n';
    answer = min(dpMin[N - 1][1] + abs(points[N - 1][0] - points[N - 1][1]), dpMin[N - 1][4] + abs(points[N - 1][1] - points[N - 1][2]));
    answer = min(answer, dpMin[N][0]);
    cout << answer;
}
