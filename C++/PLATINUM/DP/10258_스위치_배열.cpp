#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("10258.txt", ios_base::in);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        int init = pow(2, s.length() - 1);
        int ans = 0;
        char expected = '0';
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] != expected)
            {
                ans += init;
                expected = '1';
            }
            else
                expected = '0';
            init /= 2;
        }
        cout << ans << '\n';
    }
}