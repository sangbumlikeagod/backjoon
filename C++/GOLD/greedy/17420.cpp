#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int duration[100001];
int willuse[100001];
// pair<int, int> schedule[100001];
vector<pair<int, int>> schedule {};
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("17420.txt", ios_base::in);    
    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> duration[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> willuse[i];
    }
    for (int i = 0; i < N; i++)
    {
        schedule.push_back(make_pair(willuse[i], duration[i]));
        // 이때 사용될 것 // 남은 기한
    }
    sort(schedule.begin(), schedule.end());

    int maxVal = schedule[0].second;
    int maxDuration = schedule[0].first;
    int prevmaxVal = 0;
    int prevmasDuration = 0;
    for (int i = 0; i < N; i++)
    {
        if (maxDuration != schedule[i].first){

            if ( schedule[i].second < maxVal || schedule[i].second < schedule[i].first){

                int tmpMax = max(schedule[i].first, maxVal);    

                
                
                int num = abs(schedule[i].second - tmpMax) / 30 + bool(abs(schedule[i].second - tmpMax) % 30);
                ans += num;

                prevmaxVal = maxVal;
                prevmasDuration = maxDuration;
                maxVal = num * 30 + schedule[i].second;
                maxDuration = schedule[i].first;

            }
            else 
            {
                // 
                maxVal = max(maxVal, schedule[i].second);
            }
        } 
        else 
        {
            if ( schedule[i].second < prevmaxVal || schedule[i].second < schedule[i].first){
                int tmpMax = max(schedule[i].first, prevmaxVal); 
                int num = abs(schedule[i].second - tmpMax) / 30 + bool(abs(schedule[i].second - tmpMax) % 30);
                ans += num;
                maxVal = max(num * 30 + schedule[i].second, maxVal);
            }   
            maxVal = max(maxVal, schedule[i].second);

        }
        // cout << ans << ' ' << maxVal << '\n';
    }
    
    cout << ans;



}