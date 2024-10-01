#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("13275.txt", ios_base::in);
    string s;
    cin >> s;

    int maxVal = 0;
    int r = 0;
    int c = 0;
    vector<char> manacher{};
    vector<int> dp{};
    for (char c : s)
    {
        manacher.push_back('#');
        manacher.push_back(c);
    }
    manacher.push_back('#');
    int tSize = manacher.size();
    dp = vector<int>(tSize, -1);
    for (int i = 0; i < tSize; i++)
    {
        if (i < r)
        {
            dp[i] = min(r - i - 1, dp[2 * c - i]);
        }
        while (i - (dp[i] + 1) >= 0 && i + (dp[i] + 1) < tSize && manacher[i - (dp[i] + 1)] == manacher[i + (dp[i] + 1)])
        {
            dp[i]++;
        }
        if (i + dp[i] > r)
        {
            r = dp[i] + i;
            c = i;
        }
        maxVal = max(maxVal, dp[i]);
    }

    for (int i = 0; i < tSize; i++)
    {
        cout << dp[i] << '\t';
    }
    cout << '\n';

    cout << maxVal;
}