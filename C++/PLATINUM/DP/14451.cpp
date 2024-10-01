#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> Game_Map;
vector<vector<vector<int>>> DP_MAIN;
vector<vector<vector<int>>> DP_RIGHT;
vector<vector<vector<int>>> DP_UP;

// 북 동 남 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("14451.txt", ios_base::in);
    cin >> N;
    string s;

    Game_Map = vector<vector<int>>(N, vector<int>(N, 0));
    DP_MAIN = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(4, 0)));
    DP_RIGHT = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(16, 0)));
    DP_UP = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(16, 0)));
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            if (s[j] == 'H')
            {
                Game_Map[i][j] = 1;
            }
        }
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    // 비용, x, y, 방향
    q.push({0,
            0,
            N - 1,
            2});
    q.push({0,
            0,
            N - 1,
            3});

    // 오른쪽 방향에서 시작하는
    while (!q.empty())
    {
        vector<int> tmp = q.top();
        q.pop();

        int cost = tmp[0], x = tmp[1], y = tmp[2], direction = tmp[3];
        // printf("상세 %d, (%d, %d), %d \n", tmp[0], tmp[1], tmp[2], tmp[3]);
        // 반시계
        int nDirection = direction == 0 ? 3 : direction - 1;
        if (!DP_MAIN[x][y][(nDirection + 2) % 4])
        {
            DP_MAIN[x][y][(nDirection + 2) % 4] = cost + 1;
            q.push({cost + 1,
                    x,
                    y,
                    nDirection});
        }
        // 시계
        nDirection = direction == 3 ? 0 : direction + 1;
        if (!DP_MAIN[x][y][(nDirection + 2) % 4])
        {
            DP_MAIN[x][y][(nDirection + 2) % 4] = cost + 1;
            q.push({cost + 1,
                    x,
                    y,
                    nDirection});
        }
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && !Game_Map[nx][ny])
        {
            if (!DP_MAIN[nx][ny][(direction + 2) % 4])
            {
                DP_MAIN[nx][ny][(direction + 2) % 4] = cost + 1;
                q.push({cost + 1,
                        nx,
                        ny,
                        direction});
            }
        }
    }

    int limit = 10000;
    // 북쪽 먼저
    q = priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>();
    q.push({0,
            N - 1,
            0,
            1,
            N - 1,
            0,
            0});

    // 동쪽으로 이동하는 것 먼저
    while (!q.empty())
    {
        vector<int> tmp = q.top();
        q.pop();

        int cost = tmp[0], x = tmp[1], y = tmp[2], direction = tmp[3], sX = tmp[4], sY = tmp[5], sDirection = tmp[6];
        // 반시계

        if (cost > limit)
            break;

        if (x == 0 && y == N - 1)
        {
            limit = min(limit, cost + DP_MAIN[sX][sY][sDirection]);
            printf("섹스 상세 %d, (%d, %d), %d, (%d, %d), %d , 결과 : %d \n", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6], cost + DP_MAIN[sX][sY][sDirection]);

            continue;
        }
        printf("섹스 상세 %d, (%d, %d), %d, (%d, %d), %d \n", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6]);

        int nDirection = direction == 0 ? 3 : direction - 1;
        int nSDirection = sDirection == 0 ? 3 : sDirection - 1;
        if (!DP_RIGHT[x][y][nDirection * 4 + nSDirection])
        {
            DP_RIGHT[x][y][nDirection * 4 + nSDirection] = cost + 1;
            q.push({
                cost + 1,
                x,
                y,
                nDirection,
                sX,
                sY,
                nSDirection,
            });
        }
        // 시계
        nDirection = direction == 3 ? 0 : direction + 1;
        nSDirection = sDirection == 3 ? 0 : sDirection + 1;
        if (!DP_RIGHT[x][y][nDirection * 4 + nSDirection])
        {
            DP_RIGHT[x][y][nDirection * 4 + nSDirection] = cost + 1;
            q.push({
                cost + 1,
                x,
                y,
                nDirection,
                sX,
                sY,
                nSDirection,
            });
        }
        int nx = x + dx[direction];
        int ny = y + dy[direction];

        int nsX = sX + dx[sDirection];
        int nsY = sY + dy[sDirection];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && !Game_Map[nx][ny])
        {
            if (!DP_RIGHT[nx][ny][direction * 4 + sDirection])
            {
                DP_RIGHT[nx][ny][direction * 4 + sDirection] = cost + 1;

                if (!(0 <= nsX && nsX < N && 0 <= nsY && nsY < N && !Game_Map[nsX][nsY]))
                {
                    nsX = sX;
                    nsY = sY;
                }

                q.push({cost + 1,
                        nx,
                        ny,
                        direction,
                        nsX,
                        nsY,
                        sDirection});
            }
        }
    }

    q = priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>();
    q.push({0,
            N - 1,
            0,
            0,
            N - 1,
            0,
            1});

    while (!q.empty())
    {
        vector<int> tmp = q.top();
        q.pop();

        int cost = tmp[0], x = tmp[1], y = tmp[2], direction = tmp[3], sX = tmp[4], sY = tmp[5], sDirection = tmp[6];
        // 반시계

        if (cost > limit)
            break;

        if (x == 0 && y == N - 1)
        {
            limit = min(limit, cost + DP_MAIN[sX][sY][sDirection]);
            printf("상세 %d, (%d, %d), %d, (%d, %d), %d , 결과 : %d \n", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6], cost + DP_MAIN[sX][sY][sDirection]);
            continue;
        }
        printf("시발 상세 %d, (%d, %d), %d, (%d, %d), %d \n", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4], tmp[5], tmp[6]);

        int nDirection = direction == 0 ? 3 : direction - 1;
        int nSDirection = sDirection == 0 ? 3 : sDirection - 1;
        if (!DP_UP[x][y][nDirection * 4 + nSDirection])
        {
            DP_UP[x][y][nDirection * 4 + nSDirection] = cost + 1;
            q.push({
                cost + 1,
                x,
                y,
                nDirection,
                sX,
                sY,
                nSDirection,
            });
        }
        // 시계
        nDirection = direction == 3 ? 0 : direction + 1;
        nSDirection = sDirection == 3 ? 0 : sDirection + 1;
        if (!DP_UP[x][y][nDirection * 4 + nSDirection])
        {
            DP_UP[x][y][nDirection * 4 + nSDirection] = cost + 1;
            q.push({
                cost + 1,
                x,
                y,
                nDirection,
                sX,
                sY,
                nSDirection,
            });
        }
        int nx = x + dx[direction];
        int ny = y + dy[direction];

        int nsX = sX + dx[sDirection];
        int nsY = sY + dy[sDirection];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && !Game_Map[nx][ny])
        {
            if (!DP_UP[nx][ny][direction * 4 + sDirection])
            {
                DP_UP[nx][ny][direction * 4 + sDirection] = cost + 1;

                if (!(0 <= nsX && nsX < N && 0 <= nsY && nsY < N && !Game_Map[nsX][nsY]))
                {
                    nsX = sX;
                    nsY = sY;
                }

                q.push({cost + 1,
                        nx,
                        ny,
                        direction,
                        nsX,
                        nsY,
                        sDirection});
            }
        }
    }

    cout << limit << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP_RIGHT[i][j][0] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP_RIGHT[i][j][1] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP_RIGHT[i][j][2] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP_RIGHT[i][j][3] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// for (int i = 0; i < N; i++)
// {
//     for (int j = 0; j < N; j++)
//     {
//         cout << Game_Map[i][j] << ' ';
//     }
//     cout << '\n';
// }
// cout << '\n';