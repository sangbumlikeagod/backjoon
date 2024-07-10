#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    int N, M;
    vector<int> arr(10001, 0);
    vector<int> arr_copy(10001, 0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr_copy[i] = arr[i];
    }

    for (int index = 0; index < M; index++)
    {
        int i, j, k;
        cin >> i >> j >> k;
        sort(&arr[i - 1], &arr[j]);
        cout << arr[i - 2 + k] << '\n';
        for (int p = i - 1; p < j; p++)
        {
            arr[p] = arr_copy[p];
            // cout << arr[p] << '\t';
        }
        // cout << '\n';
    }
}
