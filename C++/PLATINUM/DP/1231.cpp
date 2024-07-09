#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dp[11][500001] = {0};
int arr[51][11] = {0};
int C, D, M;
int maxVal;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1231.txt", ios_base::in);
    cin >> C >> D >> M;
    maxVal = M;
    for (int stock = 0; stock < C; stock++)
    {
        for (int day = 0; day < D; day++)
        {
            cin >> arr[stock][day];
        }
    }

    for (int day = 0; day < D - 1; day++)
    {
        for (int money = 0; money <= maxVal; money++)
        {
            for (int stock = 0; stock < C; stock++)
            {
                if (arr[stock][day + 1] - arr[stock][day] > 0 && arr[stock][day] <= money)
                {
                    dp[day][money] = max(dp[day][money], dp[day][money - arr[stock][day]] + arr[stock][day + 1] - arr[stock][day]);
                }
            }
        }
        maxVal = dp[day][maxVal] + maxVal;
    }
    cout << maxVal;
}
