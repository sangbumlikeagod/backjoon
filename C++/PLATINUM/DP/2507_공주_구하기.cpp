#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2507.txt", ios_base::in);

    int dp[501][501] = {0};
    int position[501] = {0};
    int jumpPower[501] = {0};
    int isNotOneWay[501] = {0};
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        position[i] = a;
        jumpPower[i] = b;
        isNotOneWay[i] = c;
    }

    dp[0][0] = 1;

    for (int k = 1; k < N; k++)
    {
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (i != j || (i == j && i == 0))
                {
                    if (i != k && jumpPower[i] + position[i] >= position[k] && dp[i][j])
                    {
                        dp[k][j] += dp[i][j];
                        dp[k][j] %= 1000;
                    }
                    if (j != k && isNotOneWay[k] && jumpPower[k] + position[j] >= position[k] && dp[i][j])
                    {
                        // cout << i << ' ' << j << ' ' << k << '\n';
                        dp[i][k] += dp[i][j];
                        // cout << dp[i][k] << '\n';
                        dp[i][k] %= 1000;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (position[N - 1] - position[i] <= jumpPower[i] && position[N - 1] - position[j] <= jumpPower[N - 1])
            {
                dp[N - 1][N - 1] += dp[i][j];
                dp[N - 1][N - 1] %= 1000;
            }
        }
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << dp[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }
    cout << dp[N - 1][N - 1];
}