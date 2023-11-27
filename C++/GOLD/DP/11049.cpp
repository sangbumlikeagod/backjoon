#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int matrix[501][501] = {0, };
pair<int, int> matrixNum[501];
int max_val = pow(2, 31) - 1;

int getMinimum(int index_start, int index_end){
    if (matrix[index_start][index_end]){
        return matrix[index_start][index_end];
    };
    if (index_end - index_start == 1){
        matrix[index_start][index_end] =matrixNum[index_start].first * matrixNum[index_start].second * matrixNum[index_end].second;
        return matrix[index_start][index_end];
    } else if (index_end == index_start) {
        return 0;
    }

    int res = max_val;
    int tmp = 0;

    for (int i = index_start + 1; i <= index_end; i++){
        tmp = (matrixNum[index_start].first) * (matrixNum[i - 1].second) * (matrixNum[index_end].second) + getMinimum(index_start, i - 1) + getMinimum(i, index_end);
        cout << i << '\t' << tmp << '\n';

        if (tmp < res) {res = tmp;}
    }
    // cout << res;
    matrix[index_start][index_end] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("11049.txt", ios_base::in);    
    
    int N;
    cin >> N;
    int res;
    for (int i = 0; i < N; i++){
        int r, c;
        cin >> r >> c;

        matrixNum[i] = make_pair(r, c);
    }

    cout << getMinimum(0, N - 1) << '\n'; 
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j ++){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }


}