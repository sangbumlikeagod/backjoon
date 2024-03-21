#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;



int main(){
    ifstream cin("11066.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    int T;
    cin >> T;
    // cout << T;
    for (int i = 0; i < T; i++){
        int K;
        cin >> K;
        int total = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        // vector<int> vc(K, 0);
        for (int i = 0; i < K; i++){
            int p;
            cin >> p;
            pq.push(p);
        }
        while(true){
            int f = pq.top();
            pq.pop();
            if (pq.empty()){
                break;
            }
            f += pq.top();
            pq.pop();
            pq.push(f);
            total += f;
        }
        cout << total << '\n';
    }


}