#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;


unordered_set<int> ismalfunction;

int isPossible(int val){

    if (val == 100) return 0;
    int btn = 0;
    if (!val) { if (ismalfunction.count(0)) { return -1;} else { return 1; } }
    while (val){
    if (ismalfunction.count(val % 10)) {
        return -1;
    }
    btn++;
    val /= 10;
    }
    return btn;
    
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1107.txt", ios_base::in);    
    int start;
    cin >> start;
    int malfunction;
    cin >> malfunction;
    
    for (int i = 0; i < malfunction; i++)
    {
        int j;
        cin >> j;
        ismalfunction.insert(j);
    }
    int ans = 0;
    int startleft = start, startright = start;
    while (true){
        int tmpLeft = isPossible(startleft);
        int tmpRight = isPossible(startright);
        if (tmpLeft != -1 || tmpRight != -1){
            // cout << tmpLeft << '\t' << tmpRight << '\n';
            if (tmpLeft != -1 && tmpRight == -1){
                ans += tmpLeft;

            }
            else if (tmpLeft == -1 && tmpRight != -1) {
                ans += tmpRight;

            }
            else {
                ans += min(tmpLeft, tmpRight);
            }
            break;
        }
        if (startleft) startleft--;
        startright++;
        ans++;
        // cout << startleft << '\t' << startright << '\n';

    }
    ans = min(abs(100 - start), ans);
    cout << ans;



}