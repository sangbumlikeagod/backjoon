#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;


int selective[12][2048] = {0};
char grounded [12][11] = {};
unordered_map<string, int> howMuch;



int N;
int maxNRange;
void BackTracking(int checkimPossible, int row, int y, int val, int state)
{
    int maxRange = (1 << y);

    // 다 도달했을때.
    if (y == N)
    {
        selective[row + 1][maxNRange - 1 - checkimPossible] = max(val + selective[row][state], selective[row + 1][maxNRange - 1 - checkimPossible]);
        // cout << '\n';
        return;
    }

    // 지금 내가 살 수 있는 경우에만
    if ((state & maxRange) == maxRange && grounded[row][y] != 'F')
    {
        // 오른쪽으로 갈 경우
        string product;
        product += grounded[row][y];
        if (y < N - 1 && grounded[row][y + 1] != 'F' && ((state & maxRange * 2) == maxRange * 2))
        {
            BackTracking(checkimPossible, row, y + 2, val + howMuch[product + grounded[row][y + 1]], state);
        }
        // 아래쪽을 참조할 경우
        if (grounded[row + 1][y] != 'F')
        {
            BackTracking(checkimPossible + maxRange, row, y + 1, val + howMuch[product + grounded[row + 1][y]], state);
        }
    }
    BackTracking(checkimPossible, row, y + 1, val, state);
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("10937.txt", ios_base::in);

    cin >> N;
    maxNRange = (1 << N);
    howMuch["AA"] = 100;
    howMuch["AB"] = 70;
    howMuch["BA"] = 70;
    howMuch["BB"] = 50;
    howMuch["AC"] = 40;
    howMuch["CA"] = 40;
    howMuch["BC"] = 30;
    howMuch["CB"] = 30;
    howMuch["CC"] = 20;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            grounded[i][j] = s[j];
        }
    }

    for (int j = 0; j < N; j++)
    {
        grounded[N][j] = 'F';
    }
    
    // 모든 상황에서 state가 있어야함 
    // for (int i = 1; i < N; i++)
    // {
    //     for (int j = 0; j < maxNRange; j++)
    //     {
    //         selective[i][j] = -1;
    //     }
        
    // }
    
    

    for (int i = 0; i < N; i++)
    {
        for (int state = 0; state < maxNRange; state++)
        {

            BackTracking(0, i, 0, 0, state);
        }
    }

    int ans = 0;
    cout << selective[N][maxNRange - 1];
    for (int j = 0; j < maxNRange; j++)
    {
        ans = max(ans, selective[N][j]);
    }
    cout << ans << '\n'; 
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j < (1 << N); j++)
        {
            cout << selective[i][j] << '\t';
        }
        cout << '\n';
    }

}