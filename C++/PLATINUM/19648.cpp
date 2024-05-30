#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;
const int MAXNUM = 1000000007;

vector<vector<int>> lines(14, vector<int>{});
long long dp[196][32][197] = {0};
int distances[14][14] = {0};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("19648.txt", ios_base::in);
    lines[0] = {5};
    lines[1] = {0, 5, 10};
    lines[2] = {1};
    lines[3] = {2};
    lines[4] = {3};
    lines[5] = {0, 9};
    lines[6] = {1, 3, 7, 11, 12};
    lines[7] = {3, 8};
    lines[8] = {3, 4};
    lines[9] = {10};
    lines[10] = {6, 11};
    lines[11] = {12};
    lines[12] = {7, 13};
    lines[13] = {8};

    int seconds;
    cin >> seconds;

    int logSize = 1;
    int logDigit = 2;
    while (logDigit <= seconds)
    {
        logSize++;
        logDigit *= 2;
    }

    for (int i = 0; i < 14; i++)
    {
        int visited[14] = {0};
        visited[i] = 1;
        queue<int> A;
        queue<int> B;
        A.push(i);
        int level = 1;
        while (!A.empty())
        {
            // cout << A.front() << '\n';
            int num = A.front();
            A.pop();
            for (int next : lines[num])
            {
                if (visited[next] == 0)
                {
                    distances[i][next] = level;
                    visited[next] = 1;
                    B.push(next);
                }
            }
            if (A.empty())
            {
                while (!B.empty())
                {
                    A.push(B.front());
                    B.pop();
                }
                level++;
            }
        }
    }

    // 모든 배열에서 1초뒤에 갈 수 있는 곳들을 적어놓음
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 14; j++)
        {
            if (distances[i][j] < 3 || distances[j][i] < 3)
            {
                // dp[i * 14 + j][0][i * 14 + j] = -1;
                continue;
            }
            else
            {
                for (int ii : lines[i])
                {
                    for (int jj : lines[j])
                    {
                        if (distances[ii][jj] < 3 || distances[jj][ii] < 3)
                        {
                            continue;
                        }
                        dp[i * 14 + j][0][ii * 14 + jj] = 1;
                    }
                }
            }
        }
    }
    // 4초 뒤라면 2초뒤의 모든 애들에 대해서
    // 현재 가 13, 13의 1초라면
    // 1ㅗㅊ뒤에 거기 갔다는건데 그럼 그 간놈의 1초뒤를 따라서 2초뒤로 더해줌
    for (int time = 1; time < logSize; time++)
    {
        for (int i = 0; i < 14; i++)
        {
            for (int j = 0; j < 14; j++)
            {
                // 다음
                for (int ii = 0; ii < 14; ii++)
                {
                    for (int jj = 0; jj < 14; jj++)
                    {
                        if (distances[ii][jj] < 3 || distances[jj][ii] < 3)
                        {
                            continue;
                        }

                        // if (dp[i * 14 + j][time][ii * 14 + jj])
                        // {
                        // i * 14 + j가  time 초 뒤에 ii * 14 + jj 칸에 있는 경우의수
                        for (int kk = 0; kk < 14; kk++)
                        {
                            for (int pp = 0; pp < 14; pp++)
                            {
                                if (distances[kk][pp] < 3 || distances[pp][kk] < 3)
                                {
                                    continue;
                                }
                                // ii, jj 칸에서 time 초 뒤에
                                long long val = dp[i * 14 + j][time - 1][ii * 14 + jj] * dp[ii * 14 + jj][time - 1][kk * 14 + pp];
                                long long nextThing = val % MAXNUM;
                                dp[i * 14 + j][time][kk * 14 + pp] += nextThing;
                                dp[i * 14 + j][time][kk * 14 + pp] %= MAXNUM;
                                // dp[kk * 13 + pp][time + 1][196] += dp[ii * 14 + jj][time][196];
                                // dp[kk * 13 + pp][time + 1][196] %= MAXNUM;

                                // cout << ii * 14 + jj << '\n';
                            }
                        }
                        // }
                    }
                }
            }
        }
    }

    // for (int i = 0; i < 14; i++)
    // {
    //     for (int j = 0; j < 14; j++)
    //     {
    //         for (int z = 1; z < 32; z++)
    //         {
    //             for (int a = 0; a < 14; a++)
    //             {
    //                 for (int y = 0; y < 14; y++)
    //                 {
    //                     if (dp[i * 14 + j][z][a * 14 + y])
    //                     {
    //                         cout << dp[i * 14 + j][z][a * 14 + y] << ' ';
    //                         cout << '\n';
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    // 그리고 누가 11111(2) 초뒤를 확인하려면 내자리에서 16초 뒤 그 모든 자리에서 모든 요소들의 8초뒤
    // 최대 196의
    long long answers[196] = {0};
    answers[21] = 1;
    int binary = 1;
    for (int fromLow = 0; fromLow < logSize; fromLow++)
    {
        long long tmp[196] = {0};
        if (binary & seconds)
        {
            // cout << binary << '\n';
            // 여기 모든 196개의 값을 뒤져서
            for (int o = 0; o < 196; o++)
            {
                // 걔가 갈 수 있 fromLow추 뒤에 갈 수 있는 곳의 경우의 수 * 그 값자체의 경우의수를 구함
                for (int d = 0; d < 196; d++)
                {
                    tmp[d] += answers[o] * dp[o][fromLow][d];
                    tmp[d] %= MAXNUM;
                    // if (answers[o] * dp[o][fromLow][d])
                    // {
                    //     printf("%d 숫자에서 %d에 가능 경우의 수 계산 중 일 \n", o, d);
                    //     cout << answers[o] * dp[o][fromLow][d] << '\n';
                    // }
                }
            }

            for (int i = 0; i < 196; i++)
            {
                // if (tmp[i])
                // {
                //     printf("tmp에서 %lld 의 숫자를 파악하기 위한 일 \n", tmp[i]);
                // }
                answers[i] = tmp[i];
            }
        }

        binary <<= 1;
    }

    long long ans = 0;
    for (int asdf = 0; asdf < 196; asdf++)
    {
        ans += answers[asdf];
        ans %= MAXNUM;
    }
    cout << ans;

    // 내 현재 위치에서 10111 만큼 이동했다면
    // 큰 수부터
}