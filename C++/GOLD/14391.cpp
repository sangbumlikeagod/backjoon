#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int pann[5][5];
int dp[5][5];
int prefixRow[5][5];
int prefixColumn[5][5];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("14391.txt", ios_base::in);
    int M, N;
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        char inp[N];
        cin >> inp;

        for (int j = 0; j < N; j++)
        {
            // cin >> pann[i][j];
            pann[i][j] = inp[j] - '0';
            int prefixrow = j ? prefixRow[i][j - 1] : 0;
            int prefixcolumn = i ? prefixColumn[i - 1][j] : 0;

            prefixRow[i][j] = prefixrow * 10 + pann[i][j];
            prefixColumn[i][j] = prefixcolumn * 10 + pann[i][j];
        }
    }
    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << prefixRow[i][j] << ' ' << prefixColumn[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }

    // dp[0][0] = pann[0][0];
    for (int i = 0; i < N; i++)
    {
        dp[0][i] = prefixRow[0][i];
    }
    for (int i = 0; i < M; i++)
    {
        dp[i][0] = prefixColumn[i][0];
    }

    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << dp[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // 지금 내 i * j 덩어리의 최대값은 내가 i번째 줄의 prefix에 들어갈때 i - 1, j 의 dp값 을 더한 것 또는 j번째 열에 들어갈때 i j - 1 의 dp값을 더한것중에서 정해진다
            // int ifRow = j ? prefixRow[i + 1][j] : 0;
            int ifRow = prefixRow[i + 1][j];
            int ifColumn = prefixColumn[i][j + 1];
            // int ifColumn = i ? prefixColumn[i][j + 1] : 0;
            dp[i + 1][j] = max(dp[i][j] + ifRow, dp[i + 1][j]);
            dp[i][j + 1] = max(dp[i][j] + ifColumn, dp[i][j + 1]);
        }
    }

    // for (int i = 0; i < M; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << dp[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }

    cout << dp[M - 1][N - 1];
}