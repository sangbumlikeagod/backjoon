#include <iostream>
#include <fstream>

#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

char apple[300000];
char cube[300000];
char ans[300000];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("16890.txt", ios_base::in);

    string s;

    cin >> s;
    int N;
    N = s.length();

    for (int i = 0; i < N; i++)
    {
        apple[i] = s[i];
    }
    cin >> s;

    for (int j = 0; j < N; j++)
    {
        cube[j] = s[j];
    }

    sort(apple, apple + N);
    sort(cube, cube + N);
    int x = 0;
    int y = N - 1;
    int leftend = 0;
    int rightend = N - 1;
    for (int i = 0; i < N; i++)
    {
        if (i % 2)
        {
            if (cube[y] < apple[x])
            {
                ans[rightend--] = cube[y--];
            }
            else
            {
                ans[leftend++] = cube[y--];
            }
        }
        else
        {
            if (apple[x] > cube[y])
            {
                ans[rightend--] = apple[x++];
            }
            else
            {
                ans[leftend++] = apple[x++];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i];
    }
}