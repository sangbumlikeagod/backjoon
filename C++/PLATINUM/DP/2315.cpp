#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#define maxNum 1000000000;
using namespace std;

int dp[1001][1001][2]{0};
int prefixSum[1001]{0};
int position[1001];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2315.txt", ios_base::in);

    int N, M;
    cin >> N >> M;
    for (int index = 1; index <= N; index++)
    {
        int c, d;
        cin >> c >> d;
        position[index] = c;
        prefixSum[index] = prefixSum[index - 1] + d;
    }

    for (int index = 1; index < 1001; index++)
    {
        for (int indexes = 1; indexes < 1001; indexes++)
        {
            dp[index][indexes][0] = maxNum;
            dp[index][indexes][1] = maxNum;
        }
    }
    dp[M][M][0] = 0;

    for (int difference = 0; difference <= N; difference++)
    {
        int left = max(1, M - difference);
        int right = M;
        for (int index = left; index <= right; index++)
        {
            if (dp[index][index + difference][0] != 1000000000)
            {
                // cout << index << '\n';
                if (index > 1)
                {
                    dp[index - 1][index + difference][0] = min(dp[index - 1][index + difference][0], dp[index][index + difference][0] + (prefixSum[N] - (prefixSum[index + difference] - prefixSum[index - 1])) * (position[index] - position[index - 1]));
                }
                if (index + difference + 1 <= N)
                {
                    dp[index][index + difference + 1][1] = min(dp[index][index + difference + 1][1], dp[index][index + difference][0] + (prefixSum[N] - (prefixSum[index + difference] - prefixSum[index - 1])) * (position[index + difference + 1] - position[index]));
                }
            }
            if (dp[index][index + difference][1] != 1000000000)
            {
                // cout << index << '\n';
                if (index > 1)
                {
                    dp[index - 1][index + difference][0] = min(dp[index - 1][index + difference][0], dp[index][index + difference][1] + (prefixSum[N] - (prefixSum[index + difference] - prefixSum[index - 1])) * (position[index + difference] - position[index - 1]));
                }
                if (index + difference + 1 <= N)
                {
                    dp[index][index + difference + 1][1] = min(dp[index][index + difference + 1][1], dp[index][index + difference][1] + (prefixSum[N] - (prefixSum[index + difference] - prefixSum[index - 1])) * (position[index + difference + 1] - position[index + difference]));
                }
            }
        }
    }
    cout << min(dp[1][N][0], dp[1][N][1]);
}