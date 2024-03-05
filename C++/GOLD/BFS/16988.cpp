#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int M;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int badukPlate[20][20] = {0};
int visited[20][20] = {0};

void bfs(int x, int y, vector<pair<int, int>> &whereOneCanPut) {

    queue<pair<int, int>> q;
    visited[x][y] = 98;
    q.push(make_pair(x, y));

    while (q.empty() == false)
    {
        /* code */
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == 0)
            {
                if (badukPlate[nx][ny] == 2)
                {
                    visited[nx][ny] = 98;
                    q.push(make_pair(nx, ny));
                }
                else if (badukPlate[nx][ny] == 0)
                {
                    visited[nx][ny] = 99;
                    whereOneCanPut.push_back(make_pair(nx, ny));
                }
            }
        }
    }
}

int bfs2(int x, int y) {

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int cnt = 0;
    // cout << '\n';
    visited[x][y] = 98;
    while (q.empty() == false)
    {

        int x = q.front().first;
        int y = q.front().second;
        cnt++;
        // cout << x << y << '\n';
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && visited[nx][ny] == 0)
            {
                if (badukPlate[nx][ny] == 2)
                {
                    visited[nx][ny] = 98;
                    q.push(make_pair(nx, ny));
                }
                else if (badukPlate[nx][ny] == 0)
                {
                    return 0;
                }
            }
        }
        // cout << '\n';
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("16988.txt", ios_base::in);
    cin >> N >> M;    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> badukPlate[i][j];
        }
    }
    vector<pair<int, int>> baduk_set {};
    vector<pair<int, int>> whereOneCanPut {};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == 0 && badukPlate[i][j] == 2) 
            {
                baduk_set.push_back(make_pair(i, j));
                bfs(i, j, whereOneCanPut);
            }       
        }
    }

   
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = 0;
        }   
    } 

    int maxAns = 0;
    if (whereOneCanPut.size() == 1)
    {
        int x1 = whereOneCanPut[0].first;
        int x2 = whereOneCanPut[0].second;
        badukPlate[x1][x2] = 1;
        int tmpAns = 0;
        for (int k = 0; k < baduk_set.size(); k++)
        {
            // cout << baduk_set[k].first << ' ' << baduk_set[k].second << '\t';
            // cout << '\n';
            tmpAns += bfs2(baduk_set[k].first, baduk_set[k].second);
            // cout << tmpAns << '\n';
        }
        if (tmpAns > maxAns) {maxAns = tmpAns;}

    }
    else
    {
        for (int i = 0; i < whereOneCanPut.size(); i++)
        {
            for (int j = i + 1; j < whereOneCanPut.size(); j++)
            {
                int x1 = whereOneCanPut[i].first;
                int x2 = whereOneCanPut[i].second;
                int tmpAns = 0;
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < M; j++)
                    {
                        visited[i][j] = 0;
                    }   
                }
                int y1 = whereOneCanPut[j].first;
                int y2 = whereOneCanPut[j].second;
                // cout << baduk_set.size() << '\n';
                // cout << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << '\n';
                badukPlate[x1][x2] = 1;
                badukPlate[y1][y2] = 1;
                for (int k = 0; k < baduk_set.size(); k++)
                {
                    // cout << baduk_set[k].first << ' ' << baduk_set[k].second << '\t';
                    // cout << '\n';
                    tmpAns += bfs2(baduk_set[k].first, baduk_set[k].second);
                    // cout << tmpAns << '\n';
                }
                if (tmpAns > maxAns){maxAns = tmpAns;} 
                badukPlate[x1][x2] = 0;
                badukPlate[y1][y2] = 0;
            }
            // for (int ai = 0; ai < N; ai++)
            // {
            //     for (int aj = 0; aj < M; aj++)
            //     {
            //         cout << badukPlate[ai][aj] << ' ';
            //     }
            //     cout << '\n';
            // }
        }
    }
    cout << maxAns;
    

}