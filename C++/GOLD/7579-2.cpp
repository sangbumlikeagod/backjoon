#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

map<int, int> DP;
int benefit[100] = {0};
int cost[100] = {0};
const int maxVal = 200000000;

// 내 효용과 비용을
int N, M;
int main()
{
    ifstream cin("7579-2.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> benefit[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i];
    }
    int ans = maxVal;
    DP[0] = 0;
    for (int i = 0; i <= N; i++)
    {
        for (map<int, int>::iterator p = DP.begin(); p != DP.end(); p++)
        {
            // int maxEffect = DP.empty() ? 0 : (--DP.end())->first;
            // int maxCost = DP.empty() ? 0 : (--DP.end())->second;
            // int minEffect = DP.empty() ? maxVal : (DP.begin())->first;
            // int minCost = DP.empty() ? maxVal : (DP.begin())->second;
            // cout << p->first << ' ' << p->second << '\n';
            if (p->second >= M)
            {
                ans = min(ans, p->first);
            }
            else
            {
                // if (i != N && (p->first + benefit[i] > maxEffect && p->second + cost[i] >= maxCost) || (p->first + benefit[i] <= minEffect && p->second + cost[i] < minCost))
                if (i != N)
                {
                    if (DP.find(p->first + benefit[i]) == DP.end())
                    {
                        DP[p->first + cost[i]] = 0;
                    }
                    DP[p->first + cost[i]] = max(DP[p->first + cost[i]], p->second + benefit[i]);
                    if (DP.find(p->first) == DP.end())
                    {
                        DP[p->first] = 0;
                    }
                    DP[p->first] = max(DP[p->first], p->first);
                }
            }
        }
    }
    cout << ans;
    // 메모리초과를 안나게 하려면 어디서 빼줘야함 이런 힙적인게 있지, 비용도 크고 메모리도 적다면 넣지 말아야하는거지 그러면 어떻게? 요용이 높은놈은 어디선가 필요해질 수 있고 효용이 낮은대신 비용도 낮은녀석 근데 효용이 작은녀석은 구별할 필요가
    // 없이 비용이 작은놈만 받아들이면 된다. 문제는 그니까 효용이크고 비용이 큰놈 효용이 작은대신 비용이 작은놈은 그 효용에 필요한 경우가 있을 수도 있음 그러면 그렇게 변화시키면서 하면 되겠다.
}