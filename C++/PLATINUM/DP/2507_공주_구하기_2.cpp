#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int routes[501][501] = {0};
int distances[501];
int jumpPower[501];
int allowedTwo[501];
int N;

int DP(int N)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            if (x == N - 1 && y == N - 1)
            {
                return 1;
            }
            if (x == y && x != 0)
                return 0;

            cout << x << ' ' << y << '\n';
            if (routes[x][y])
            {
                return routes[x][y];
            }

            int xMax = distances[x] + jumpPower[x];
            for (int i = x + 1; i <= N && distances[i] <= xMax; i++)
            {
                if (i == y)
                    continue;
                routes[x][y] += 1;
                if (i == N - 1)
                    break;
            }

            int yMax = distances[y] + jumpPower[y];
            for (int j = y + 1; j <= x + 1 && distances[j] <= yMax; j++)
            {
                if (!allowedTwo[j])
                    continue;
                routes[x][y] += DP(x, j);
                if (j >= N - 1)
                    break;
            }
            printf("(%d, %d) 상황에서 x쪽 %d, y쪽 %d 총 합해 %d 가 되었도다 \n", x, y, xMax, yMax, routes[x][y]);
            return routes[x][y];
        }
    }

    // if (x != N - 1 && distances[x + 1] <= distances[x] + jumpPower[x])
    // {
    //     routes[x][y] += DP(x + 1, y);
    // }
    // if (y != N - 1 && distances[y + 1] <= distances[y] + jumpPower[y] && !allowedTwo[y + 1])
    // {
    //     routes[x][y] += DP(x, y + 1);
    // }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2507.txt", ios_base::in);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> distances[i] >> jumpPower[i] >> allowedTwo[i];
    }
    routes[N - 1][N - 1] = 1;
    cout << N << '\n';
    cout << DP(0, 0);
}