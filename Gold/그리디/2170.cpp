#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;


int main(){
    ifstream cin("2170.txt", ios_base::in);
    int N;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);

    for (int li; li < N; li++){
        int S, E;
        cin >> S >> E;
        pq.push(make_pair(S, E));
    }
    int end = pq.top().first - 1;
    int total = 0;
    while(pq.empty() == false){
        cout << pq.top().first << ' ' << pq.top().second << '\n';
        if (pq.top().first > end){
            total += pq.top().second - pq.top().first;
            end = pq.top().second;
        } else if (pq.top().second > end) {
            total += pq.top().second - end;
            end = pq.top().second;
        } 
        pq.pop();
    }
    cout << total;

}