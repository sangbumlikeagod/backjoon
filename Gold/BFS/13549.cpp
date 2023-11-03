#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

vector<int> visited(200000, 0);

int main(){
    ifstream cin("13549.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    
    int s;
    int e;
    cin >> s >> e;
    visited[s] = 1;
    int round;
    int location;

    que.push(make_pair(0, s));
    while (!que.empty())
    {
        round, location = que.top().first, que.top().second;
        if (location > 0){
            if (location * 2 < 200000 && !visited[location * 2]){
                visited
            }
        }

        que.pop();
    }
    


}