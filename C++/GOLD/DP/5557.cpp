#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

long long VAL[21][101];
int TABLE[101];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("5557.txt", ios_base::in);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> TABLE[i];
    }
    VAL[TABLE[0]][1] = 1;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (0 <= j + TABLE[i] && j + TABLE[i] <= 20)
            {
                VAL[j + TABLE[i]][i + 1] += VAL[j][i];
            }
            if (0 <= j - TABLE[i] && j - TABLE[i] <= 20)
            {
                VAL[j - TABLE[i]][i + 1] += VAL[j][i];
            }
        }
    }

    cout << VAL[TABLE[N - 1]][N - 1];
}