#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MODULO = 1000000000;
int lisT[102][1024][10] = {0};



int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1562.txt", ios_base::in);    
    
    int N;
    cin >> N;

    for (int i = 1; i < 10; i++)
    {
        int tmp = 1 << i;
        lisT[1][tmp][i] = 1;
    }

    for (int x = 1; x <= N; x++)
    {
        for (int i = 0; i <= 1023; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (j - 1 >= 0)
                {
                    lisT[x + 1][i | 1 << (j - 1)][j - 1] += lisT[x][i][j];
                    lisT[x + 1][i | 1 << (j - 1)][j - 1] %= MODULO;
                }
                if (j + 1 < 10)
                {
                    lisT[x + 1][i | 1 << (j + 1)][j + 1] += lisT[x][i][j];
                    lisT[x + 1][i | 1 << (j + 1)][j + 1] %= MODULO;
                }
            }               
        }
    }
    long long ans = 0;

    for (int i = 0; i < 10; i++)
    {
        ans += lisT[N][1023][i];
        ans %= MODULO;
    }
    
    cout << ans;
}