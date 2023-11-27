#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int arr[2001] = {0,};
int dp_arr[2001][2001] = {0,};


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("11570.txt", ios_base::in);
    
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    int res = 2000 * 1000000;
    fill_n(&dp_arr[0][0], 2001 * 2001, res);
    dp_arr[1][0] = 0;
    
    for (int i = 1; i < N; i++){
        for (int j = 0; j < i; j++){
            dp_arr[i + 1][j] = min(dp_arr[i + 1][j], dp_arr[i][j] + abs(arr[i + 1] - arr[i]));
            dp_arr[i + 1][i] = min(dp_arr[i + 1][i], dp_arr[i][j] + abs(arr[i + 1] - arr[j]) * (j != 0));
        } 
    }
    for (int j = 0; j < N; j++) {res = min(res, dp_arr[N][j]);}

    cout << res;
}