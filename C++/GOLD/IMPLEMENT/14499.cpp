#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int Land[20][20];
int dice[6] = {0, 0, 0, 0, 0, 0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int command[6][4][4] = {
    {
        {1, 4, 2, 3},
        {2, 3, 4, 1},
        {3, 2, 1, 4},
        {4, 1, 3, 2}
    },
    {
        {3, 2, 5, 0},
        {5, 0, 2, 3},
        {0, 5, 3, 2},
        {2, 3, 0, 5}
    },
    {
        {1, 4, 5, 0},
        {4, 1, 0, 5},
        {5, 0, 4, 1},
        {0, 5, 1, 4}
    },
    {
        {5, 0, 1, 4},
        {0, 5, 4, 1},
        {1, 4, 0, 5},
        {4, 1, 5, 0}
    },
    {
        {0, 5, 2, 3},
        {2, 3, 5, 0},
        {5, 0, 3, 2},
        {3, 2, 0, 5}
    },
    {
        {3, 2, 4, 1},
        {4, 1, 2, 3},
        {1, 4, 3, 2},
        {2, 3, 1, 4}
    },
};


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("14499.txt", ios_base::in);
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Land[i][j];
        }
    }
    
    int diceFace = 0;
    int* next_command = command[0][2];
    for (int asp = 0; asp < K; asp++)
    {
        int cmd = 0;
        cin >> cmd;
        cmd--;
        
        // 범위에서 벗어날 시 그냥 continue
        int nx = x + dx[cmd];
        int ny = y + dy[cmd];

        if (0 <= nx && nx < N && 0 <= ny && ny < M)
        {
            x = nx;
            y = ny;
            int nextDiceFace = *(next_command + cmd);
            int thisDiceFaceWillbeAt = cmd % 2 ? cmd - 1 : cmd + 1;
            // 3일경우 2가되고 0일경우 1이되고 반대도 가능하게
            
            for (int i = 0; i < 4; i++)
            {
                if (command[nextDiceFace][i][thisDiceFaceWillbeAt] == diceFace)
                {
                    next_command = command[nextDiceFace][i];
                    break;
                }
            }
            diceFace = nextDiceFace;
            if (Land[nx][ny])
            {
                dice[diceFace] = Land[nx][ny];
                Land[nx][ny] = 0;
            }
            else 
            {
                Land[nx][ny] = dice[diceFace];
                // dice[diceFace] = 0;
            }
            cout << dice[5 - diceFace] << '\n';
        // 남쪽 커맨드일시 다음 다이스 커맨드에서 북쪽으로 이동하는게 지금인 경우가 
        } 

    }
    
    
}