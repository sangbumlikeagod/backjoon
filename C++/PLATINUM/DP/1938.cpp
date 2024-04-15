#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <cstring>
using namespace std;

int pann[51][51][2] {};
char ground[51][51] {};
int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};


int N;

queue<vector<int>> q;


bool isInBound(int isMain, int x, int y, int isRow)
{
    int lowBound = isMain ? 1 : 0;
    int highBound = isMain ? N - 2 : N - 1;
    // 가로라면 0행에 갈 수 있어야해
    if (isRow == 2)
    {
        return lowBound <= x && x <= highBound  && lowBound  <= y && y <= highBound ;
    }
    return lowBound - (isRow == 1) <= x && x <= highBound + (isRow == 1) && lowBound - !(isRow == 1) <= y && y <= highBound + !(isRow == 1);
}

bool checkSideNotOne(int x, int y, int isRow)
{
    if (isRow)
    {
        return ground[x][y - 1] != '1' && ground[x][y + 1] != '1';
    }
    else
    {
        return ground[x - 1][y] != '1' && ground[x + 1][y] != '1';
    }
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("1938.txt", ios_base::in);

    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++)
        {
            ground[i][j] = s[j];
        }
    }

    vector<int> start;
    vector<int> end;
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            if (ground[i][j] == 'B')
            {
                for(int k = 0; k < 2; k++)
                {
                    pair<int, int> tmpOne = {i + dx[k], j + dy[k]};
                    pair<int, int> tmpTwo = {i + dx[3 - k], j + dy[3 - k]};
                    if (isInBound(0, tmpOne.first, tmpOne.second, 2) && isInBound(0, tmpTwo.first, tmpTwo.second, 2) && ground[tmpOne.first][tmpOne.second] == 'B' && ground[tmpTwo.first][tmpTwo.second] == 'B')
                    {
                        start = {i, j, k, 0};
                    }
                }
            }
            else if (ground[i][j] == 'E')
            {
                for(int k = 0; k < 2; k++)
                {
                    pair<int, int> tmpOne = {i + dx[k], j + dy[k]};
                    pair<int, int> tmpTwo = {i + dx[3 - k], j + dy[3 - k]};
                    if (isInBound(0, tmpOne.first, tmpOne.second, 2) && isInBound(0, tmpTwo.first, tmpTwo.second, 2) && ground[tmpOne.first][tmpOne.second] == 'E' && ground[tmpTwo.first][tmpTwo.second] == 'E')
                    {

                        end = {i, j, k, 0};
                    }
                }

            }
        }
        
    }
        
    // k는 0이 세로, 1이 가로
    q.push(start);

    int ans = 0;
    pann[start[0]][start[1]][start[2]] = 1;
    while (q.empty() == false)
    {
        vector<int> next = q.front();
        cout << next[0] << ' ' << next[1] << ' ' << next[2] << ' ' <<  next[3] <<  '\n';

        if (next[0] == end[0] && next[1] == end[1] && next[2] == end[2])
        {
            ans = next[3];
            break;
        }
        q.pop();
        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                if (isInBound(1, next[0] - 1, next[1], next[2]) && pann[next[0] - 1][next[1]][next[2]] == 0 && checkSideNotOne(next[0] - 1, next[1], next[2])) 
                {
                    // 얘 기준 두칸 : 0일떄 , 1칸 : 1일때 위가 1인지 확인
                    if ( ground[next[0] - (1 + !next[2])][next[1]] != '1')
                    {
                        // cout << "SEXSEX" << '\n';
                        pann[next[0] - 1][next[1]][next[2]] = 1;
                        q.push(vector<int> {next[0] - 1, next[1], next[2], next[3] + 1});
                    }
                }                
            }
            else if (i == 1)
            {
                if (isInBound(1, next[0] + 1, next[1], next[2]) && pann[next[0] + 1][next[1]][next[2]] == 0 && checkSideNotOne(next[0] + 1, next[1], next[2])) 
                {
                    if (ground[next[0] + (1 + !next[2])][next[1]] != '1') 
                    {
                        // cout << "SEXSEX" << '\n';
                        // cout << next[0]  + (1 + !next[2]) << '\t' <<  next[1] << '\n' << '\t' << '\t' << ground[next[0] + (1 + !next[2])][next[1]] << '\n';
                        pann[next[0] + 1][next[1]][next[2]] = 1;
                        q.push(vector<int> {next[0] + 1, next[1], next[2], next[3] + 1});
                    }
                }
            }
            else if (i == 2)
            {
                if (isInBound(1, next[0], next[1] - 1, next[2]) && pann[next[0]][next[1] - 1][next[2]] == 0 && checkSideNotOne(next[0], next[1] - 1, next[2])) 
                {
                    if (ground[next[0]][next[1] - (1 + next[2])] != '1')
                    {
                        pann[next[0]][next[1] - 1][next[2]] = 1;
                        q.push(vector<int> {next[0], next[1] - 1, next[2], next[3] + 1});
                    }
                }
            }
            else if (i == 3)
            {
                if (isInBound(1, next[0], next[1] + 1, next[2]) && pann[next[0]][next[1] + 1][next[2]] == 0 && checkSideNotOne(next[0], next[1] + 1, next[2])) 
                {
                    // cout << "sex" << ' ';
                    // cout << next[0] << ' ' << next[1] + 1 << '\n';
                    if (ground[next[0]][next[1] + (1 + next[2])] != '1')
                    {
                        pann[next[0]][next[1] + 1][next[2]] = 1;
                        q.push(vector<int> {next[0], next[1] + 1, next[2], next[3] + 1});
                    }
                }
            }
            else 
            {
                bool isPossible = true;
                if (pann[next[0]][next[1] + 1][!next[2]] == 1) continue;
                for (int k = 0; k < 8; k++)
                {
                    if (isInBound(0, next[0] + dx[k], next[1] + dy[k], 2))
                    {
                        if (ground[next[0] + dx[k]][next[1] + dy[k]] == '1')
                        {
                            isPossible = false;
                            break;
                        }   
                    }
                    else
                    {
                        isPossible = false;
                        break;

                    }
                }
                if (isPossible)
                {
                    pann[next[0]][next[1]][!next[2]] = 1;
                    q.push(vector<int> {next[0], next[1], !next[2], next[3] + 1});
                }
            }
        }
        
    }
    cout << ans;

}