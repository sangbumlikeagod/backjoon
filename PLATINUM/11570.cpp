#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int arr[2001] = {0, };
int dp_arr[2001][2001] = {0, };
int N;
int dp(int i, int j){
    // 항상 i가 j보다 크게
    if (dp_arr[i][j]) {return dp_arr[i][j];}
    int res = 2000 * 1000000;
    for(int i_i = j + 1; i_i <= i; i_i++ ){
        for (int j_j = 0; j_j < i_i; j_j++){
            int tmp = dp(i_i, j_j) + abs(arr[i] - arr[i_i]) + abs(arr[j] - arr[j_j]);
            if (res > tmp) {res = tmp;}
        }
    }
    dp_arr[i][j] = res;
    return res;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("11570.txt", ios_base::in);
    fill_n(&dp_arr[0][0], 2001 * 4, 0);
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
        // if (i > 1) {
        //     dp[0][i] = dp[0][i - 1];
        //     if (arr[i] < arr[i - 1]) {
        //         dp[0][i] -= arr[i] - arr[i - 1];
        //     } else {
        //         dp[0][i] += arr[i] - arr[i - 1];
        //     }
        // }
    }
    int res = 2000 * 1000000;
    for (int i = 0; i < N; i++){
        int tmp = dp(N, i);
        if (res > tmp) res = tmp;
    }
    cout << res;
}