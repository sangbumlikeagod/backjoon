#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


short arr[100001][3] = {0, };
int visited[100001][3] = {0, }; 
int N;

int main(){
    ifstream cin("2096.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    cin >> N;
    for (int a = 1; a <= N; a++){
        cin >> arr[a][0] >> arr[a][1] >> arr[a][2];
    }
    for (int r = 1; r < N; r++){
        visited[r][0] = 0;
        visited[r][1] = 0;
        visited[r][2] = 0;
    }

    for (int r = 1; r <= N; r++){
        visited[r][0] = max(visited[r - 1][0] + arr[r][0], visited[r - 1][1] + arr[r][0]);
        visited[r][1] = max(max(visited[r - 1][0] + arr[r][1], visited[r - 1][1] + arr[r][1]), visited[r - 1][2] + arr[r][1]);
        visited[r][2] = max(visited[r - 1][2] + arr[r][2], visited[r - 1][1] + arr[r][2]);

        // visited[r][3] = min(visited[r - 1][3] + arr[r][0], visited[r - 1][4] + arr[r][0]);
        // visited[r][4] = min(min(visited[r - 1][3] + arr[r][1], visited[r - 1][4] + arr[r][1]), visited[r - 1][5] + arr[r][1]);
        // visited[r][5] = min(visited[r - 1][5] + arr[r][2], visited[r - 1][4] + arr[r][2]);
    }

    cout << max(max(visited[N][0], visited[N][1]), visited[N][2]) << ' ';

    for (int r = 1; r <= N; r++){
        visited[r][0] = min(visited[r - 1][0] + arr[r][0], visited[r - 1][1] + arr[r][0]);
        visited[r][1] = min(min(visited[r - 1][0] + arr[r][1], visited[r - 1][1] + arr[r][1]), visited[r - 1][2] + arr[r][1]);
        visited[r][2] = min(visited[r - 1][2] + arr[r][2], visited[r - 1][1] + arr[r][2]);

    }

    cout << min(min(visited[N][0], visited[N][1]), visited[N][2]);

    // pair<int, int> res = godown(-1, 1);

    // cout << res.first << ' ' << res.second;
    // cout << res.first << ' ' << res.second;
}