#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int arr[2001] = {
    0,
};
int dp_arr[2001][2001] = {
    0,
};
int N;
int dp(int i, int j)
{
    if (dp_arr[i][j] != -1)
    {
        return dp_arr[i][j];
    }
    if (i <= 1)
    {
        dp_arr[i][j] = 0;
        return 0;
    }
    if (!j)
    {
        dp_arr[i][j] = dp(i - 1, j) + abs(arr[i] - arr[i - 1]);
        return dp_arr[i][j];
    }
    int res = 2000 * 1000000;

    if (i == j + 1)
    {
        int tmp = 0;
        int res1 = 0;
        int res2 = 0;
        for (int j_j = 0; j_j < j - 1; j_j++)
        {
            res1 = 0;
            res2 = 0;
            tmp = dp(i - 2, j_j);

            if (j_j)
            {
                res1 += abs(arr[j] - arr[j_j]);
                res2 += abs(arr[i] - arr[j_j]);
            }
            if (i - 2)
            {
                res1 += abs(arr[i] - arr[i - 2]);
                res2 += abs(arr[j] - arr[i - 2]);
            }
        }
        if (res > tmp + res1)
            res = tmp + res1;
        if (res > tmp + res2)
            res = tmp + res2;
    }
    else
    {
        int tmp = 0;
        for (int j_j = 0; j_j <= j; j_j++)
        {
            tmp = dp(i - 1, j_j);

            if (j_j)
            {
                tmp += abs(arr[j] - arr[j_j]);
            }
            if (i - 1)
            {
                tmp += abs(arr[i] - arr[i - 1]);
            }

            if (res > tmp)
            {
                res = tmp;
            }
        }
    }
    dp_arr[i][j] = res;
    return res;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("11570.txt", ios_base::in);
    fill_n(&dp_arr[0][0], 2001 * 2001, -1);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    int res = 2000 * 1000000;
    for (int i = N; i; i--)
    {
        int tmp = dp(N, i);
        if (res > tmp)
            res = tmp;
    }
    cout << res << '\n';

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= N; j++)
    //     {
    //         cout << dp_arr[i][j] << '\t';
    //     }
    //     cout << '\n';
    // }
}