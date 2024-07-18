#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int maze[1001][1001];
pair<int, int> paths[5];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
const int MAXNUM = 2000001;
struct StateXX
{
    int x;
    int y;
    int cost;
    StateXX(int x, int y, int cost) : x(x), y(y), cost(cost){};
    bool operator<(const StateXX &ot) const
    {
        return cost > ot.cost;
    }
};

int dijkstra(int sx, int sy, int ex, int ey)
{
    int cost = 0;
    priority_queue<StateXX> q;
    q.push(StateXX(sx, sy, 0));
    int ov[1001][1001] = {};
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            ov[i][j] = MAXNUM;
        }
    }
    ov[sx][sy] = 0;

    while (true)
    {
        int x = q.top().x;
        int y = q.top().y;
        int cost = q.top().cost;
        q.pop();

        // cout << x << ' ' << y  << ' ' << cost << '\n';
        if (x == ex && y == ey)
        {
            // cout << "완" << '\n';
            return cost;
        }
        for (int idx = 0; idx < 4; idx++)
        {
            int nx = x + dx[idx];
            int ny = y + dy[idx];
            int nCost;
            if (!nx || nx > N || !ny || ny > N)
            {
                continue;
            }
            nCost = cost + maze[nx][ny] + maze[x][y];
            if (nCost >= ov[nx][ny])
            {
                continue;
            }
            // cout << nCost << '\n';
            ov[nx][ny] = nCost;
            q.push(StateXX(nx, ny, nCost));
        }
    }
    return cost;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> maze[i][j];
        }
    }

    for (int k = 0; k < 5; k++)
    {
        int a, b;
        cin >> a >> b;
        paths[k] = {a, b};
    }

    int commonCost = dijkstra(paths[1].first, paths[1].second, paths[2].first, paths[2].second) +
                     dijkstra(paths[2].first, paths[2].second, paths[3].first, paths[3].second);

    int firstRoute = dijkstra(1, 1, paths[0].first, paths[0].second) +
                     dijkstra(paths[0].first, paths[0].second, paths[1].first, paths[1].second) +
                     commonCost +
                     dijkstra(paths[3].first, paths[3].second, paths[4].first, paths[4].second);

    int secondRoute = dijkstra(1, 1, paths[4].first, paths[4].second) +
                      dijkstra(paths[4].first, paths[4].second, paths[1].first, paths[1].second) +
                      commonCost +
                      dijkstra(paths[3].first, paths[3].second, paths[0].first, paths[0].second);

    cout << min(firstRoute, secondRoute);
}
