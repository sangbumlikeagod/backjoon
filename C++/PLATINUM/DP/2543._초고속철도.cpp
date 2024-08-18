#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MODULO = 20070713;

vector<vector<int>> points;
vector<int> dp;

auto comp = [](const int &a, const vector<int> &b)
{
    return a < b[0];
};

int DP(int N)
{
    if (N == dp.size())
    {
        return 1;
    }
    if (dp[N] != -1)
        return dp[N];
    dp[N] = (DP(N + 1) +
             DP(upper_bound(points.begin(), points.end(), points[N][1], comp) -
                points.begin())) %
            MODULO;

    return dp[N];
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2543.txt", ios_base::in);
    int N;
    cin >> N;
    points = vector<vector<int>>(N, vector<int>{0, 0});
    dp = vector<int>(N, -1);
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        points[i][0] = a;
        points[i][1] = b;
    }
    sort(points.begin(), points.end(), [](vector<int> a, vector<int> b)
         { return a[0] < b[0]; });

    DP(0);
    cout << dp[0];
}