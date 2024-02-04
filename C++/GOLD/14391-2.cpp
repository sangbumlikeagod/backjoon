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
    masking[i][j] = mask;
    if (i == M - 1 && j == N - 1)
    {
        for (int i = 0; i < M * N; i++)
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
        for (int i = 0; i < M * N; i++)
        {
            tmpAns += ansAr[i];
        }
        cout << tmpAns << '\n';
        Ans = max(Ans, tmpAns);
        return;
    }

    int ni = 0;
    int nj = 0;
    int nm = 0;
    ni = i == M - 1 ? 0 : i + 1;
    nj = i == M - 1 ? j + 1 : j;
    nm = i == M - 1 ? mask + 1 : mask;
    if (!masking[ni][nj])
    {
        if (i != M - 1)
        {
            // 아래 쪽으로 더 갈 수 있을 때
            if (j == 0 || masking[i][j - 1] != masking[i][j])
                tracking(ni, nj, nm);
            tracking(ni, nj, nm + 1);
        }
        else
        {
            tracking(ni, nj, nm);
        }
        masking[ni][nj] = 0;
    }

    ni = j == N - 1 ? i + 1 : i;
    nj = j == N - 1 ? 0 : j + 1;
    nm = j == N - 1 ? mask + 1 : mask;
    if (!masking[ni][nj])
    {
        // tracking(ni, nj, nm);
        // if (j != N - 1)
        //     tracking(ni, nj, nm + 1);

        if (j != N - 1)
        {
            // 아래 쪽으로 더 갈 수 있을 때
            if (i == 0 || masking[i - 1][j] != masking[i][j])
                tracking(ni, nj, nm);
            tracking(ni, nj, nm + 1);
        }
        else
        {
            tracking(ni, nj, nm);
        }
        masking[ni][nj] = 0;
    }
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