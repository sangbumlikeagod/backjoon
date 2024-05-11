#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    // ifstream cin("14658.txt", ios_base::in);
    
    int n, m, l, k;
    int ans = 0;
    vector<pair<int, int>> stars;
    cin >> n >> m >> l >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        stars.push_back({a, b});
    }
    for (int x = 0; x < k; x++)
    {
        for (int y = 0; y < k; y++)
        {
            if (x == y) continue;
            // cout << "(" << stars[x].first << ", " << stars[x].second << "), " <<   "(" << stars[y].first << ", " << stars[y].second << ")" << '\n';

            if (max(stars[x].first , stars[y].first) - min(stars[x].first, stars[y].first) > l || max(stars[x].second , stars[y].second) - min(stars[x].second, stars[y].second) > l)
            {
                continue;
            }
            else if (stars[x].first > stars[y].first || stars[x].second > stars[y].second)
            {
                continue;
            }
            // cout << "(" << stars[x].first << ", " << stars[x].second << "), " <<   "(" << stars[y].first << ", " << stars[y].second << ")" << '\n';
            int tmp = 0;
            int nx = stars[x].first + l;
            int ny = stars[y].second - l;
            for (int i = 0; i < k; i++)
            {
                int tx = stars[i].first;
                int ty = stars[i].second;
                if (nx >= tx && tx >= stars[x].first && ny <= ty && ty <= stars[y].second)
                {
                    tmp++;
                }
            }
            ans = max(ans, tmp);       
        }
        int tmp = 0;
        int nx = stars[x].first + l;
        int ny = stars[x].second - l;
        for (int i = 0; i < k; i++)
        {
            int tx = stars[i].first;
            int ty = stars[i].second;
            if (nx >= tx && tx >= stars[x].first && ny <= ty && ty <= stars[x].second)
            {
                tmp++;
            }
        }
        ans = max(ans, tmp);   
    }
    cout << k - ans;
    
}