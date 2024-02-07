#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

int mapp[100][10001];
int benefit[100] = {0};
int cost[100] = {0};
const int maxVal = 200000000;

// 내 효용과 비용을
// int dp(int n, int m)
// {
//     if (m <= cost[n])
//     {
//         return benefit[n];
//     }
//     if (n < 0 && m)
//         return maxVal;

//     if (mapp[n][m])
//     {
//         return mapp[n][m];
//     }
//     int ans = min(dp(n - 1, m - benefit[n]) + cost[n], dp(n - 1, m));
//     // 곧 올라간다.
//     mapp[n][m] = ans;
//     return ans;
// }
int N, M;
int main()
{
    ifstream cin("7579-2.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> benefit[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }
    int ans = maxVal;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10001; j++)
        {
            mapp[i][j] = -1;
        }
    }

    mapp[0][0] = 0;
    mapp[0][cost[0]] = benefit[0];
    bool isStopable = false;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 10000; j++)
        {
            if (mapp[i][j] >= M)
            {
                ans = min(ans, j);
                isStopable = true;
            }

            if (i != N - 1 && mapp[i][j] != -1)
            {
                mapp[i + 1][j + cost[i + 1]] = max(mapp[i + 1][j + cost[i + 1]], mapp[i][j] + benefit[i + 1]);
                mapp[i + 1][j] = max(mapp[i + 1][j], mapp[i][j]);
            }
        }
        if (isStopable)
            break;
    }

    cout << ans;
    // 메모리초과를 안나게 하려면 어디서 빼줘야함 이런 힙적인게 있지, 비용도 크고 메모리도 적다면 넣지 말아야하는거지 그러면 어떻게? 요용이 높은놈은 어디선가 필요해질 수 있고 효용이 낮은대신 비용도 낮은녀석 근데 효용이 작은녀석은 구별할 필요가
    // 없이 비용이 작은놈만 받아들이면 된다. 문제는 그니까 효용이크고 비용이 큰놈 효용이 작은대신 비용이 작은놈은 그 효용에 필요한 경우가 있을 수도 있음 그러면 그렇게 변화시키면서 하면 되겠다.
}