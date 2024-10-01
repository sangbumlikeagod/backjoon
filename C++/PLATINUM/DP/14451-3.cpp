#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> Game_Map;
vector<vector<vector<int>>> DP_MAIN;
int DP_TABLE[20][20][4][20][20][4] = {0};

// 북 동 남 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

void dfs(priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> &nq, int &answer)
{
    while (!nq.empty())
    {
        vector<int> tmp = nq.top();
        nq.pop();
        int cost = tmp[0], x = tmp[1], y = tmp[2], direction = tmp[3], sx = tmp[4], sy = tmp[5], sdirection = tmp[6];
        if ((x == 0 && y == N - 1))
        {
            cout << sx << ' ' << sy << ' ' << sdirection << ' ' << cost << ' ' << DP_MAIN[sx][sy][sdirection] << '\n';
            answer = min(answer, cost + DP_MAIN[sx][sy][sdirection]);
            continue;
        }
        // cout << x << ' ' << y << ' ' << direction << ' ' << answer << '\n';
        int nDirection = direction == 0 ? 3 : direction - 1;
        int nSDirection = sdirection == 0 ? 3 : sdirection - 1;
        if (!DP_TABLE[x][y][nDirection][sx][sy][nSDirection])
        {
            DP_TABLE[x][y][nDirection][sx][sy][nSDirection] = 1;
            nq.push({cost + 1,
                     x,
                     y,
                     nDirection,
                     sx,
                     sy,
                     nSDirection});
        }
        // 시계
        nDirection = direction == 3 ? 0 : direction + 1;
        nSDirection = sdirection == 3 ? 0 : sdirection + 1;
        if (!DP_TABLE[x][y][nDirection][sx][sy][nSDirection])
        {
            DP_TABLE[x][y][nDirection][sx][sy][nSDirection] = 1;
            nq.push({cost + 1,
                     x,
                     y,
                     nDirection,
                     sx,
                     sy,
                     nSDirection});
        }
        int nx = x + dx[direction];
        int ny = y + dy[direction];
        int nsX = sx + dx[sdirection];
        int nsY = sy + dy[sdirection];
        if (0 <= nx && nx < N && 0 <= ny && ny < N && !Game_Map[nx][ny])
        {
            if (!(0 <= nsX && nsX < N && 0 <= nsY && nsY < N && !Game_Map[nsX][nsY]))
            {
                nsX = sx;
                nsY = sy;
            }
            if (!DP_TABLE[nx][ny][direction][nsX][nsY][sdirection])
            {
                DP_TABLE[nx][ny][direction][nsX][nsY][sdirection] = 1;
                nq.push({cost + 1,
                         nx,
                         ny,
                         direction,
                         nsX,
                         nsY,
                         sdirection});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("14451.txt", ios_base::in);
    cin >> N;
    string s;

    Game_Map = vector<vector<int>>(N, vector<int>(N, 0));
    DP_MAIN = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(4, 1000000)));

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
        if (cost + 1 < DP_MAIN[x][y][(nDirection + 2) % 4])
        {
            DP_MAIN[x][y][(nDirection + 2) % 4] = cost + 1;
            q.push({cost + 1,
                    x,
                    y,
                    nDirection});
        }
        // 시계
        nDirection = direction == 3 ? 0 : direction + 1;
        if (cost + 1 < DP_MAIN[x][y][(nDirection + 2) % 4])
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
            if (cost + 1 < DP_MAIN[nx][ny][(direction + 2) % 4])
            {
                DP_MAIN[nx][ny][(direction + 2) % 4] = cost + 1;
                q.push({cost + 1,
                        nx,
                        ny,
                        direction});
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        DP_MAIN[0][N - 1][i] = 0;
    }
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> nq;
    nq.push({
        0,
        N - 1,
        0,
        0,
        N - 1,
        0,
        1,
    });

    nq.push({
        0,
        N - 1,
        0,
        1,
        N - 1,
        0,
        0,
    });

    int answer = 100000;
    dfs(nq, answer);
    cout << answer << '\n';

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP_MAIN[i][j][0] % 1000000 << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP_MAIN[i][j][1] % 1000000 << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP_MAIN[i][j][2] % 1000000 << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << DP_MAIN[i][j][3] % 1000000 << ' ';
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