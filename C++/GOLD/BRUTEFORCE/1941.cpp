#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <queue>
using namespace std;

int classTable[5][5] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = 0;

vector<int> backtrackingSerializer;

bool isConnected()
{
    queue<int> q;
    int ans = 1;
    int visited[5][5] = {0};
    q.push(backtrackingSerializer[0]);
    visited[backtrackingSerializer[0] / 5][backtrackingSerializer[0] % 5] = 1;
    while (q.empty() == false)
    {
        int next = q.front();
        q.pop();
        for (int i : backtrackingSerializer)
        {
            for (int d = 0; d < 4; d++)
            {
                int nx = (next / 5) + dx[d];
                int ny = (next % 5) + dy[d];
                if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && visited[nx][ny] == 0 && nx == i / 5 && ny == i % 5)
                {
                    visited[nx][ny] = 1;
                    q.push(i);
                    ans++;
                }
            }
        }
    }
    return ans == 7;
}

void backtracking(int n, int S, int Y)
{
    // cout << n << ' ' << S << ' ' << Y << '\n';
    if (Y == 4)
    {
        return;
    }
    if (backtrackingSerializer.size() == 7)
    {
        if (isConnected())
        {
            ans++;
            // for (int i : backtrackingSerializer)
            // {
            //     cout << i << '\t';
            // }
            // cout << '\n';
        }
        return;
    }

    backtrackingSerializer.push_back(n);
    backtracking(n + 1, S + (classTable[n / 5][n % 5] == 'S'), Y + (classTable[n / 5][n % 5] == 'Y'));
    backtrackingSerializer.pop_back();
    if (25 - n != 7 - backtrackingSerializer.size())
    {
        backtracking(n + 1, S, Y);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1941.txt", ios_base::in);

    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++)
        {
            classTable[i][j] = s[j];
        }
    }

    backtracking(0, 0, 0);
    cout << ans;
}