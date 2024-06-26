#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("28136.txt", ios_base::in);
    static int sequences[1000001]{0};
    int index = 0, ans = 1, before = 0;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> sequences[i];
    }
    while (index < N)
    {
        if (before < sequences[index])
        {
            before = sequences[index];
        }
        else
        {
            cout << sequences[index] << '\n';
            before = sequences[index];
            ans++;
        }
        index++;
    }
    if (sequences[N - 1] < sequences[0])
    {
        ans--;
    }
    cout << ans;
}
