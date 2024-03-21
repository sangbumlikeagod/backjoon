// #include <iostream>
// #include <fstream>
// #include <queue>
// #include <vector>
// #include <map>
// using namespace std;

// int main(){
//     ifstream cin("1735.txt", ios_base::in);
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    ifstream cin("1735.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    int V, E, K;

    cin >> V >> E;
    cin >> K;

    int inf = 20000 * 10;
    vector<int> ans(V, 0); 
    vector<vector<pair<int, int>>> lst(V, vector<pair<int, int>>{});

    
    for (int i = 0; i < V; i ++){
        ans[i] = inf;
    }
    for (int i = 0; i < E; i++ ){
        int s, e, w;
        cin >> s >> e >> w;
        // printf("%d %d %d \n", s, e, w);
        // if (lst[s - 1].empty() == false){
        //     if (w < lst[s - 1][0].second){
        //         lst[s - 1].pop_back();
        //         lst[s - 1].push_back(make_pair(e - 1, w));
        //     }
        // } else {
        //     lst[s - 1].push_back(make_pair(e - 1, w));
        // }
        lst[s - 1].push_back(make_pair(e - 1, w));

        // printf("%d %d %d \n", s, e, lst[s][e]);
    }
    
    
    // for (int i = 0; i < V; i++){
    //     for (int j = 0; j < V; j++){
    //         // printf("%d %d \n", i, j );
    //         printf("%d ", lst[i][j]);
    //     }  
    //     printf("\n");
    // }

    // cout << ' '; 
    // visited[K] = 1;

    ans[K - 1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> hq;
    hq.push(make_pair(0, K - 1));
    while (hq.empty() == false){
        int val = hq.top().first;
        int node = hq.top().second;
        hq.pop();
        for(pair<int, int> arg : lst[node]){
            // printf("%d \n", lst[node][i]);
            if(arg.second != 0 && val + arg.second < ans[arg.first] ){
                ans[arg.first] = val + arg.second;
                hq.push(make_pair(val + arg.second, arg.first));
            }
        }
        
    }
    for (int arg : ans){
        if (arg != inf){
        cout << arg << '\n';}
        else {
            cout << "INF" << '\n';
        }
    }
}