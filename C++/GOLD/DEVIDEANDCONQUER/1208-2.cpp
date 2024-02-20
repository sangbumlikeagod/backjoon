#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
const int SETPOSITIVE = 2000000;
long long leftSide[4000001];
long long rightSide[4000001];
int numbers[41];
void backtracking(int idx, long long val, int limit, long long *container)
{
    if (idx == limit)
    {
        container[val + SETPOSITIVE]++;
        // cout << val + SETPOSITIVE << ' ';
        return;
    }
    backtracking(idx + 1, val + numbers[idx], limit, container);
    backtracking(idx + 1, val, limit, container);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1208.txt", ios_base::in);
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> numbers[i];
    }
    backtracking(0, 0, N / 2, leftSide);
    backtracking(N / 2, 0, N, rightSide);
    leftSide[SETPOSITIVE]--;
    rightSide[SETPOSITIVE]--;

    long long ans = 0;
    ans += leftSide[S + SETPOSITIVE];
    ans += rightSide[S + SETPOSITIVE];

    for (int i = 0; i < 100000 * N / 2 + SETPOSITIVE; i++)
    {
        if (leftSide[i] && rightSide[S - i + SETPOSITIVE * 2])
        {
            ans += leftSide[i] * rightSide[S - i + SETPOSITIVE * 2];
        }
    }

    cout << ans;
}