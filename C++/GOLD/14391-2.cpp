#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int pann[4][4];
int masking[4][4];
int ansAr[17] = {
    0,
};
int Ans;
int M, N;

void tracking(int i, int j, int mask)
{
    // cout << i << ' ' << j << ' ' << mask << '\n';
    if (i == M)
    {
        for (int i = 0; i < M * N + 1; i++)
        {
            ansAr[i] = 0;
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ansAr[masking[i][j]] *= 10;
                ansAr[masking[i][j]] += pann[i][j];
            }
        }
        int tmpAns = 0;
        for (int i = 0; i < M * N + 1; i++)
        {
            tmpAns += ansAr[i];
        }
        Ans = max(Ans, tmpAns);
        return;
    }
    masking[i][j] = mask;

    int ni, nj;
    ni = j == N - 1 ? i + 1 : i;
    nj = j == N - 1 ? 0 : j + 1;
    if (i)
    {
        if ((!j || masking[i - 1][j - 1] != masking[i - 1][j]) && (j == N - 1 || masking[i - 1][j + 1] != masking[i - 1][j]))
        {
            masking[i][j] = masking[i - 1][j];
            tracking(ni, nj, mask);
        }
    }
    if (j)
    {
        if ((!i || masking[i - 1][j - 1] != masking[i][j - 1]) && (i == M - 1 || masking[i + 1][j - 1] != masking[i][j - 1]))
        {
            masking[i][j] = masking[i][j - 1];
            tracking(ni, nj, mask);
        }
    }
    masking[i][j] = mask;
    tracking(ni, nj, mask + 1);
    // 옆에애가 위에 있을때로 변경
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("14391.txt", ios_base::in);
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        char inp[N];
        cin >> inp;

        for (int j = 0; j < N; j++)
        {
            // cin >> pann[i][j];
            pann[i][j] = inp[j] - '0';
        }
    }
    tracking(0, 0, 1);

    cout << Ans;
}