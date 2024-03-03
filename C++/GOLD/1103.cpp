#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int pann[50][50] = {0};
int dp[50][50] = {0};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int M, N;

int Dp(int i, int j)
{
    // cout << i << j << '\n';
    if (dp[i][j])
        return dp[i][j];
    if (pann[i][j] == -1)
        return -1;
    int nx, ny;
    int ans = 1;
    int save = pann[i][j];
    pann[i][j] = -1;
    for (int z = 0; z < 4; z++)
    {
        nx = dx[z] * save + i;
        ny = dy[z] * save + j;
        d
            // cout << nx << ' ' << ny << '\n';
            if (0 <= nx && nx < M && 0 <= ny && ny < N && pann[nx][ny] != 24)
        {
            int beforeCompare = Dp(nx, ny) + 1;
            if (beforeCompare == 0)
            {
                return -1;
            }

            ans = max(ans, beforeCompare);
        }
    }
    pann[i][j] = save;
    dp[i][j] = ans;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1103.txt", ios_base::in);

    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        char inp[N];
        cin >> inp;
        for (int j = 0; j < N; j++)
        {
            pann[i][j] = inp[j] - '0';
        }
    }

    cout << Dp(0, 0);
}