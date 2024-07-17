#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> entry{};
vector<int> exitArray{};
int entryIndex = 0;
int exitArrayIndex = 0;
int dp[301][301][301] = {0};

int main()
{
    int N, M, K, T;
    cin >> N >> M >> K >> T;

    int prayer = 0;

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        entry.push_back(a);
        exitArray.push_back(b);
    }

    sort(entry.begin(), entry.end());
    sort(exitArray.begin(), exitArray.end());
    dp[0][0][K] = 1;

    for (int time = 0; time < N; time++)
    {
        while (entryIndex < M && entry[entryIndex] <= time + 1)
        {
            entryIndex++;
            prayer++;
        }
        while (exitArrayIndex < M && exitArray[exitArrayIndex] <= time + 1)
        {
            exitArrayIndex++;
            prayer--;
        }
        // cout << time << ' ' << prayer << '\n';
        for (int kOnFest = 0; kOnFest <= K; kOnFest++)
        {
            for (int kRemains = 0; kRemains <= K; kRemains++)
            {
                if (!dp[time][kOnFest][kRemains])
                    continue;

                if (prayer >= T)
                {
                    dp[time + 1][0][kRemains] = max(dp[time + 1][0][kRemains], dp[time][kOnFest][kRemains] + 1);
                    continue;
                }

                if (prayer + kOnFest >= T)
                {
                    dp[time + 1][kOnFest][kRemains] = max(dp[time + 1][kOnFest][kRemains], dp[time][kOnFest][kRemains] + 1);
                }
                else
                {
                    int supplement = (T - prayer - kOnFest);
                    dp[time + 1][kOnFest][kRemains] = max(dp[time + 1][kOnFest][kRemains], dp[time][kOnFest][kRemains]);
                    if (kRemains >= supplement)
                    {
                        dp[time + 1][kOnFest + supplement][kRemains - supplement] = max(dp[time + 1][kOnFest + supplement][kRemains - supplement], dp[time][kOnFest][kRemains] + 1);
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            answer = max(answer, dp[N][i][j]);
        }
    }

    cout << answer - 1;

    for (int i = 0; i <= K; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            answer = max(answer, dp[N][i][j]);
        }
    }
}
