#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

vector<int> visited(200000, 100001);

int main(){
    ifstream cin("13549.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    
    int s;
    int e;
    cin >> s >> e;
    visited[s] = 0;
    int round;
    int location;
    que.push(make_pair(0, s));
    while (!que.empty())
    {
        round = que.top().first;
        location = que.top().second;
        // cout << round <<' ' << location << '\n';  
        que.pop();
        if (location == e) {
            cout << round;
            break;
        }
        if (location * 2 < e * 2 && round < visited[location * 2]){
            visited[location * 2] = round;
            que.push(make_pair(round, location * 2));
        }
        if (location + 1 < 200000 && round + 1 < visited[location + 1]){
            visited[location + 1] = round + 1;
            que.push(make_pair(round + 1, location + 1));
        }
        if (location - 1 >= 0 && round + 1 < visited[location - 1]){
            visited[location - 1] = round + 1;
            // cout << location - 1 << '\n';
            que.push(make_pair(round + 1, location - 1));
        }
    }

}