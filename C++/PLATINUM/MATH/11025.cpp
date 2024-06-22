#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("11025.txt", ios_base::in);
    int N, K;
    cin >> N >> K;
    int ans = 1;
    for (int index = 1; index < N; index++)
    {
        ans += (K % (index + 1));
        // ans %= (index + 1);
        if (ans > index + 1)
        {
            ans -= index + 1;
        }
        // cout << ans << '\n';
    }
    cout << ans;
}