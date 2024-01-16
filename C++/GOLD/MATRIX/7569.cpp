#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int box[100][100][100] = {0, };
queue<tuple<int, int, int>> q;
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("7569.txt", ios_base::in);    
    int M, N, H;
    cin >> N >> M >> H;
    int ans = 0;
    int remains = 0;
    for (int z = 0; z < H; z++)
    {
        for (int x = 0; x < M; x++)
        {
            for (int y = 0; y < N; y++)
            {
                int tmp;
                cin >> tmp;
                if (tmp == 1){
                    q.push(make_tuple(x, y, z));
                }
                else if (tmp == 0){
                    remains++;
                }
                box[x][y][z] = tmp;

            }
            
        }
        
    }
    while (true){
        queue<tuple<int, int, int>> nq;
        while (!q.empty()){
            tuple<int, int, int> arg = q.front();
            int x = get<0>(arg);
            int y = get<1>(arg);
            int z = get<2>(arg);
            q.pop();
            for (int i = 0; i < 6; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if ((0 <= nx && nx < M) &&(0 <= ny && ny < N) && (0 <= nz && nz < H) && box[nx][ny][nz] == 0)
                {
                    remains--;
                    nq.push(make_tuple(nx, ny, nz));
                    box[nx][ny][nz] = 1;
                    cout << nx << ' ' << ny << ' ' << nz << '\t';
                }
            }
        }
        cout << '\n';
        if (nq.empty()){
            break;
        }
        else {
            q = nq;
            ans++;
        }
    }

    if (remains){
        cout << -1;
    } else {
        cout << ans;
    }

}   