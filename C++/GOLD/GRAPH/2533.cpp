#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;


int parents[1000000] = {0, };
int visited[1000000] = {0, };
unordered_map<int, int> map;

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2533.txt", ios_base::in);    
    
    int N;
    cin >> N;
    vector<int> childs;


    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        parents[b] = a;
        if (map.find(a) != map.end())
        {
            map.erase(a);
        }
        map[b] = 1;
    }

    for (unordered_map<int, int>::iterator i = map.begin(); i != map.end(); i++)
    {
        childs.push_back(i -> first);
    }
    int ans = 0;
    for (int i : childs)
    {
        visited[i] = 1;
    }
    
    while (!childs.empty())
    {
        vector<int> newChild;

        for (int child : childs)
        {   
            // 0일 경우 그리고 
            if (visited[child] = 1)
            {
                if (!visited[parents[child]])
                { 
                    ans++;
                    visited[parents[child]] = 2;
                }
                if (parents[child] != 0) newChild.push_back(parents[child]);
                cout << child << endl;
            }
            else
            {  
               if (!visited[parents[child]])
               {
                visited[parents[child]] = 1;
                cout << child << endl;
                // 루트가 아닐떄만 
                if (parents[child] != 0) newChild.push_back(parents[child]);
                ans++;

               }
            }

        }
        childs = newChild;
    }
    
    cout << ans;
    // 한번도 불린적이 없는 애들만 모으기 
    

    
}