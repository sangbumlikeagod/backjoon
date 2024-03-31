#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int chessBoard[12][12] = {0};
int N;
int maxVal = 0;
int maxVal2 = 0;
bool check(int x, int y)
{
    return (0 <= x && x < N && 0 <= y && y < N);
}
void BackTracking(int x, int y, int numOfBisshop)
{
    // cout << x << ' ' << y << '\n';
    if (x == N)
    {
        if (y % 2)
        {
            // cout << 1 << '\n';
            // cout << '\n'
            //  << numOfBisshop << '\n'
            //  << '\n';
            maxVal = max(maxVal, numOfBisshop);
        }
        else
        {
            // cout << 2 << '\n';
            maxVal2 = max(maxVal2, numOfBisshop);
        }

        return;
    }

    if (chessBoard[x][y] == 0)
    {
        // cout << "꺆" << '\n';
        int dx1 = x;
        int dy1 = y;
        int dx2 = x;
        int dy2 = y;
        while (true)
        {
            bool isPossible = false;

            dx1++;
            dy1++;
            if (check(dx1, dy1))
            {
                chessBoard[dx1][dy1]++;
                isPossible = true;
            }

            dx2++;
            dy2--;
            if (check(dx2, dy2))
            {
                chessBoard[dx2][dy2]++;
                isPossible = true;
            }
            if (isPossible == false)
            {
                break;
            }
        }

        if (y + 2 > N - 1)
        {
            if (y % 2)
            {
                BackTracking(x + 1, 0, numOfBisshop + 1);
            }
            else
            {
                BackTracking(x + 1, 1, numOfBisshop + 1);
            }
        }
        else
        {
            BackTracking(x, y + 2, numOfBisshop + 1);
        }

        dx1 = x;
        dy1 = y;
        dx2 = x;
        dy2 = y;
        while (true)
        {
            bool isPossible = false;

            dx1++;
            dy1++;
            if (check(dx1, dy1))
            {
                chessBoard[dx1][dy1]--;
                isPossible = true;
            }

            dx2++;
            dy2--;
            if (check(dx2, dy2))
            {
                chessBoard[dx2][dy2]--;
                isPossible = true;
            }
            if (isPossible == false)
            {
                break;
            }
        }
    }

    if (y + 2 > N - 1)
    {
        if (y % 2)
        {
            BackTracking(x + 1, 0, numOfBisshop);
        }
        else
        {
            BackTracking(x + 1, 1, numOfBisshop);
        }
    }
    else
    {
        BackTracking(x, y + 2, numOfBisshop);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1799.txt", ios_base::in);
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            int val = 0;
            cin >> val;
            if (val == 1)
            {
                val = 0;
            }
            else
            {
                val = 1;
            }

            chessBoard[x][y] = val;
        }
    }
    BackTracking(0, 0, 0);
    BackTracking(0, 1, 0);
    cout << maxVal + maxVal2;
}