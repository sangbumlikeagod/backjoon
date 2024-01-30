#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int factories[10000];
int dp[10000][3];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("18185.txt", ios_base::in);    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        
    }
    

    int N;
    cin >> N;

    int first, second;
    cin >> first >> second;
    int minval = min(first, second);
    dp[0][0] = first - minval;
    dp[0][1] = minval;
    dp[1][0] = second - minval;

    for (int i = 2; i < N; i++)
    {
        int now;
        cin >> now;

        minval = min(dp[i - 1][0], now);
        now -= minval;

        dp[i - 1][0] -= minval;
        dp[i - 1][1] += minval;

        if (now)
        {
            minval = min(dp[i - 2][1], now);
            now -= minval;
            dp[i - 2][1] -= minval;
            dp[i - 2][2] += minval;
        }
        dp[i][0] = now;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += (dp[i][0] * 3) + (dp[i][1] * 5) + (dp[i][2] * 7);
    }

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << dp[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }

    cout << ans;
}