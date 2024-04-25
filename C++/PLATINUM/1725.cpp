#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int container[100001] = {0};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1725.txt", ios_base::in);
    int left[100001] = {0};
    int right[100001] = {0};

    int N;
    int ans = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> container[i];
    }
    left[0] = -1;
    // cout << "씨발" << '\n';
    for (int lIdx = 1; lIdx < N; lIdx++)
    {
        int llIdx = lIdx - 1;
        while (llIdx >= 0 && container[llIdx] >= container[lIdx])
        {
            llIdx = left[llIdx];
        }
        left[lIdx] = llIdx;
    }
    right[N - 1] = N;
    for (int rIdx = N - 1; rIdx; rIdx--)
    {
        int rrIdx = rIdx + 1;
        while (rrIdx < N && container[rrIdx] >= container[rIdx])
        {
            rrIdx = right[rrIdx];
        }
        right[rIdx] = rrIdx;
        ans = max(ans, container[rIdx] * (right[rIdx] - left[rIdx] - 1));
    }
    cout << ans;
}