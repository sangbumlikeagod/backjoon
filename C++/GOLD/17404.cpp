#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int inputCosts[3][1001];
int FirstColoredIndex[3][3][1001];
int MAXVAL = 1000000;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("17404.txt", ios_base::in);

    int N;
    cin >> N;
    for (int first = 0; first < 3; first++)
    {
        for (int colored = 0; colored < 3; colored++)
        {
            for (int Index = 0; Index < 1001; Index++)
            {
                FirstColoredIndex[first][colored][Index] = MAXVAL;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> inputCosts[j][i];
        }
    }

    FirstColoredIndex[0][0][0] = inputCosts[0][0];
    FirstColoredIndex[1][1][0] = inputCosts[1][0];
    FirstColoredIndex[2][2][0] = inputCosts[2][0];

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (FirstColoredIndex[j][k][i] != MAXVAL)
                {
                    if (k != 0)
                    {
                        FirstColoredIndex[j][0][i + 1] = min(FirstColoredIndex[j][0][i + 1], FirstColoredIndex[j][k][i] + inputCosts[0][i + 1]);
                    }
                    if (k != 1)
                    {
                        FirstColoredIndex[j][1][i + 1] = min(FirstColoredIndex[j][1][i + 1], FirstColoredIndex[j][k][i] + inputCosts[1][i + 1]);
                    }
                    if (k != 2)
                    {
                        FirstColoredIndex[j][2][i + 1] = min(FirstColoredIndex[j][2][i + 1], FirstColoredIndex[j][k][i] + inputCosts[2][i + 1]);
                    }
                }
            }
        }
    }
    for (int startColor = 0; startColor < 3; startColor++)
    {
        for (int nthColor = 0; nthColor < 3; nthColor++)
        {
            if (startColor != nthColor)
            {
                MAXVAL = min(MAXVAL, FirstColoredIndex[startColor][nthColor][N - 1]);
                // cout << FirstColoredIndex[startColor][nthColor][N - 1] << '\n';
            }
        }
    }
    cout << MAXVAL;
}