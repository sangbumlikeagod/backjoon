#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int dp[10001][3] = {0};
int oneTaGon[10001][2] = {0};
int W;
void fillUpDp(int N)
{
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = 20001;
        }
    }
}

void takeDown(int column, int condition)
{
    if (condition == 2)
    {
        return;
    }
    if (oneTaGon[column][1] + oneTaGon[column + 1][1] <= W)
    {
        dp[column + 1][2] = min(dp[column][condition] + 2 - (condition >= 1), dp[column + 1][2]);
    }
};
void takeUp(int column, int condition)
{
    if (condition == 1)
    {
        return;
    }
    if (oneTaGon[column][0] + oneTaGon[column + 1][0] <= W)
    {
        dp[column + 1][1] = min(dp[column][condition] + 2 - (condition >= 1), dp[column + 1][1]);
    }
};

void takeNon(int column, int condition)
{
    if (condition != 0)
    {
        dp[column + 1][0] = min(dp[column + 1][0], dp[column][condition] + 1);
        return;
    }
    if (oneTaGon[column][0] + oneTaGon[column][1] <= W)
    {
        dp[column + 1][0] = min(dp[column][0] + 1, dp[column + 1][0]);
    }
    else
    {
        dp[column + 1][0] = min(dp[column][0] + 2, dp[column + 1][0]);
    }
};

void takeBoth(int column, int condition)
{
    if (condition != 0)
    {
        return;
    }
    if (oneTaGon[column][0] + oneTaGon[column + 1][0] <= W && oneTaGon[column][1] + oneTaGon[column + 1][1] <= W)
    {
        dp[column + 2][0] = min(dp[column][condition] + 2, dp[column + 2][0]);
    }
};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1006.txt", ios_base::in);
    int TC;
    cin >> TC;

    for (int tc = 0; tc < TC; tc++)
    {
        int N;
        cin >> N >> W;
        for (int i = 0; i < N; i++)
        {
            cin >> oneTaGon[i][0];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> oneTaGon[i][1];
        }
        int ans = 20001;

        // 위아래 둘다 뚫려있을 떄
        fillUpDp(N);
        dp[0][0] = 0;
        for (int column = 0; column < N - 1; column++)
        {
            for (int condition = 0; condition < 3; condition++)
            {
                if ((column == 0 && condition == 1) || (column == 0 && condition == 2))
                {
                    continue;
                }
                takeBoth(column, condition);
                takeDown(column, condition);
                takeNon(column, condition);
                takeUp(column, condition);
            }
        }
        ans = min(ans, oneTaGon[N - 1][0] + oneTaGon[N - 1][1] <= W ? dp[N - 1][0] + 1 : dp[N - 1][0] + 2);
        ans = min(ans, dp[N - 1][1] + 1);
        ans = min(ans, dp[N - 1][2] + 1);
        ans = min(ans, dp[N][0]);

        // for (int i = 0; i <= N; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         cout << dp[i][j] << '\t';
        //     }
        //     cout << '\n';
        // }

        //
        // cout << ans << '\n';

        // 위가 막혀있을 때
        if (oneTaGon[0][0] + oneTaGon[N - 1][0] <= W)
        {
            fillUpDp(N);
            dp[0][1] = 1;
            for (int column = 0; column < N - 1; column++)
            {
                for (int condition = 0; condition < 3; condition++)
                {
                    if ((column == 0 && condition == 0) || (column == 0 && condition == 2))
                    {
                        continue;
                    }
                    takeBoth(column, condition);
                    takeDown(column, condition);
                    takeNon(column, condition);
                    takeUp(column, condition);
                }
            }
            ans = min(ans, dp[N - 1][0] + 1);
            ans = min(ans, dp[N - 1][2]);
        }

        //
        // cout << ans << '\n';

        // for (int i = 0; i <= N; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         cout << dp[i][j] << '\t';
        //     }
        //     cout << '\n';
        // }

        // 밑이 막혔을 떄
        if (oneTaGon[0][1] + oneTaGon[N - 1][1] <= W)
        {
            fillUpDp(N);
            dp[0][2] = 1;
            for (int column = 0; column < N - 1; column++)
            {
                for (int condition = 0; condition < 3; condition++)
                {
                    if ((column == 0 && condition == 0) || (column == 0 && condition == 1))
                    {
                        continue;
                    }
                    takeBoth(column, condition);
                    takeDown(column, condition);
                    takeNon(column, condition);
                    takeUp(column, condition);
                }
            }
            ans = min(ans, dp[N - 1][0] + 1);
            ans = min(ans, dp[N - 1][1]);
        }
        //
        // cout << ans << '\n';

        // 위아래 둘다 막혔을 때
        if (oneTaGon[0][0] + oneTaGon[N - 1][0] <= W && oneTaGon[0][1] + oneTaGon[N - 1][1] <= W)
        {
            fillUpDp(N);
            dp[1][0] = 2;
            for (int column = 1; column < N - 1; column++)
            {
                for (int condition = 0; condition < 3; condition++)
                {
                    if ((column == 1 && condition == 1) || (column == 1 && condition == 2))
                    {
                        continue;
                    }
                    takeBoth(column, condition);
                    takeDown(column, condition);
                    takeNon(column, condition);
                    takeUp(column, condition);
                }
            }
            ans = min(ans, dp[N - 1][0]);
        }
        // for (int i = 0; i <= N; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         cout << dp[i][j] << '\t';
        //     }
        //     cout << '\n';
        // }

        cout << ans << '\n';
        // cout << '\n';
    }
}