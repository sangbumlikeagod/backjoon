#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> forOverlap;
unordered_map<int, int> forMinus;

vector<int> container;
int ans = 0;
int binarySearch(int start, int end, int target)
{
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (container[mid] == target)
        {
            return 1;
        }
        else if (container[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return container[start] == target;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1253.txt", ios_base::in);

    int N;
    int countForZero = 0;
    int comple = 0;
    cin >> N;
    for (int inp = 0; inp < N; inp++)
    {
        int in;
        if (in == 0)
        {
            countForZero++;
        }
        else if (in < 0)
        {
            forMinus[in]++;
            if (forMinus[in] == 2)
            {
                comple++;
            }
        }
        
        cin >> in;
        container.push_back(in);
    }

    sort(container.begin(), container.end());

    for (int start = 0; start < N - 1; start++)
    {
        for (int end = N - 1; end > start + 1; end--)
        {
            int tmpAns = binarySearch(start + 1, end - 1, container[end] - container[start]);
            if (tmpAns)
            {
                if (forOverlap.find(end) == forOverlap.end())
                {
                    cout << start  <<  ' ' << end << ' ' << container[end] - container[start]  << '\n';
                    forOverlap[end]++;
                    ans++;
                }
            }
        }
    }
    if (countForZero > 2)
    {
        comple += 2;
    }
    if (countForZero >= 1)
    {
        ans += comple;
    }
    cout << ans;
}
