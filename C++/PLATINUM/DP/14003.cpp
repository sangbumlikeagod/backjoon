#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int MAXNUM = 1000000;
pair<int, int> dp[MAXNUM + 1];
int nums[MAXNUM + 1];
int prevv[MAXNUM + 1];
int ans[MAXNUM + 1];
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("14003.txt", ios_base::in);    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }
    
    int size = 0;
    for (int k = 0; k < N; k++)
    {
        int i = 0, j = size;
        while (i != j)
        {
            int m = (i + j) / 2;
            if (dp[m].first < nums[k]){
                i = m + 1;
            } else {
                j = m;
            }
        }
        if (i != 0) {prevv[k] = dp[i - 1].second;}
        dp[i] = make_pair(nums[k], k);
        if (i == size) size++;
    }
    

    cout << size << '\n';
    int ptr = dp[size - 1].second;

    for (int i = size; i; i--)
    {
        ans[i - 1] = nums[ptr];
        // cout << ptr << '\n';
        ptr = prevv[ptr];
    }

    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << ' ';
    }
    
    
    

}