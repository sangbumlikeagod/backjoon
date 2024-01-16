#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int matrix[500][500];
int visited[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N = 0;
int dfs(int x, int y){
    if (visited[x][y]){
        return visited[x][y];
    }
    int ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ((0 <= nx && nx < N) && (0 <= ny && ny < N) && (matrix[nx][ny] > matrix[x][y])){
            if (visited[nx][ny]){
                ret = max(ret, visited[nx][ny] + 1);
            }
            else {
                ret = max(ret, dfs(nx, ny) + 1);
            }
        }
    }
    visited[x][y] = ret;
    return ret;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1937.txt", ios_base::in);    
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    


}