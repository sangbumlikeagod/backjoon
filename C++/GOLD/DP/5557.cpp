#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

long long VAL[21][101];
int TABLE[100];

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("5557.txt", ios_base::in);    

    int N;
    cin >> N;

    for (int i = 0; i < N; i++ ){
        cin >> TABLE[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (0 <= j + TABLE[i]  && j + TABLE[i] <= 20){
                VAL[j + TABLE[i]][i + 1] += VAL[j][i];
            }
            if (0 <= j - TABLE[i]  && j - TABLE[i] <= 20){
                VAL[j - TABLE[i]][i + 1] += VAL[j][i];
            }
        }
    }
    
    for (int i = 0; i < 21; i++){
        ans += VAL[i][N];
    }
    cout << ans;

}