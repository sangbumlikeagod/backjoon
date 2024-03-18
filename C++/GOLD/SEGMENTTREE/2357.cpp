#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXVAL = 2000000000;
int inpArray[100001];
pair<int, int> minMaxSegmentTree[(2 << 17) - 1];

pair<int, int> construct(int left, int right, int idx)
{
    if (left == right)
    {
        minMaxSegmentTree[idx] = make_pair(inpArray[left], inpArray[left]);
        // cout << idx << "는  " << inpArray[left] << "입니다" << '\n';
        return minMaxSegmentTree[idx];
    }
    int mid = (left + right) / 2;
    pair<int, int> leftminMax = construct(left, mid, idx * 2);
    pair<int, int> rightminMax = construct(mid + 1, right, idx * 2 + 1);
    minMaxSegmentTree[idx] = make_pair(min(leftminMax.first, rightminMax.first), max(leftminMax.second, rightminMax.second));
    // cout << idx << '\t' << '\t' << minMaxSegmentTree[idx].first << ' ' << minMaxSegmentTree[idx].second << '\n';
    return minMaxSegmentTree[idx];
}

pair<int, int> getMinMax(int left, int right, int idx, int start, int end)
{
    //
    // cout << '\t' << left << ' ' << right << ' ' << start << ' ' << end << ' ' << idx << '\n';
    if (left > end || right < start)
    {
        return make_pair(MAXVAL, 0);
    }
    if (left == right)
    {
        return minMaxSegmentTree[idx];
    }

    if (left >= start && end >= right)
    {
        return minMaxSegmentTree[idx];
    }
    int mid = (left + right) / 2;
    pair<int, int> leftminMax = getMinMax(left, mid, idx * 2, start, end);
    pair<int, int> rightminMax = getMinMax(mid + 1, right, idx * 2 + 1, start, end);
    return make_pair(min(leftminMax.first, rightminMax.first), max(leftminMax.second, rightminMax.second));
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2357.txt", ios_base::in);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> inpArray[i];
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << inpArray[i] << '\t';
    // }
    // cout << '\n';
    construct(0, N - 1, 1);

    // for (int i = 0; i <= N; i++)
    // {
    //     cout << minMaxSegmentTree[i].first << ' ' << minMaxSegmentTree[i].second << '\t';
    // }
    // cout << '\n';

    for (int i = 0; i < K; i++)
    {
        int j, k;
        cin >> j >> k;
        // cout << j << ' ' << k << '\n';
        pair<int, int> ans = getMinMax(0, N - 1, 1, j - 1, k - 1);
        cout << ans.first << ' ' << ans.second << '\n';
    }
}