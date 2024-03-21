#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int arr[200000];
int visited[200000] = {0, };

int main()
{
    fill_n(arr, 200000, 200000);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("12851.txt", ios_base::in);    
    queue<pair<int, int>> que;
    int N, K;
    cin >> N >> K;
    arr[N] = 0;
    visited[N] = 1;
    que.push(make_pair(0, N));
    int round, location;
    bool isfirst = true;
    while (!que.empty()){
        round = que.front().first;
        location = que.front().second;
        if (location == K)
        {
            cout << round << '\n';
            cout << visited[location];
            break;
        }
        if (0 <= location * 2 && location * 2 < 200000 && round < arr[location * 2])
        {
            if (round + 1 < arr[location * 2]){
                arr[location * 2] = round + 1;
                visited[location * 2] += visited[location];
                que.push(make_pair(round + 1, location * 2));
            } else {
                visited[location * 2] += visited[location];
            }
        }
        if (0 <= location + 1 && location + 1 < 200000 && round < arr[location + 1])
        {
            if (round + 1 < arr[location + 1])
            {
            arr[location + 1] = round + 1;
            visited[location + 1] = visited[location];
            que.push(make_pair(round + 1, location + 1));
            } else {
            visited[location + 1] += visited[location];
            }
        }
        if (0 <= location - 1 && location - 1 < 200000 && round < arr[location - 1])
        {
            if (round + 1 < arr[location - 1]){
            arr[location - 1] = round + 1;
            visited[location - 1] += visited[location];
            que.push(make_pair(round + 1, location - 1));
        } else {
            visited[location - 1] += visited[location];
        }}
        que.pop();
    }
}

