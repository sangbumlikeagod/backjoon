#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[200000];
int arrSort[200000];

int binarySearch(int start, int end, int val)
{
    while (start < end)
    {
        int med = (start + end) / 2;
        if (arrSort[med] > val)
        {
            end = med - 1;
        }
        else if (arrSort[med] < val)
        {
            start = med + 1;
        }
        else
        {
            return med;
        }
    }
    return start;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("22965.txt", ios_base::in);
    int ans = 3;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
        arrSort[i] = a;
    }
    int chance = 2;
    sort(arrSort, arrSort + N);
    int idx = 0;

    while (chance)
    {
        int sortedIndex = binarySearch(0, N - 1, arr[idx]);
        while ((idx < N) && (sortedIndex < N) && (arr[idx] == arrSort[sortedIndex]))
        {
            idx++;
            sortedIndex++;
        }
        if (idx == N)
        {
            break;
        }
        else
        {
            chance--;
            continue;
        }
    }
    cout << ans - chance;
}