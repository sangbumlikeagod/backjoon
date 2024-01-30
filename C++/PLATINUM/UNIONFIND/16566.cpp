#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct nonOverapSet
{

    vector<int> parents;
    nonOverapSet(int n)
    {
        parents.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
    };

    int find(int k)
    {
        if (k == parents[k])
        {
            return k;
        }
        // parents[k] = find(parents[k]);
        return parents[k] = find(parents[k]);
    };

    void Union(int m, int n)
    {
        int x = find(m);
        int y = find(n);

        if (x == y)
        {
            return;
        }

        parents[y] = x;
    };
};

vector<int> Cardset{};
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("16566.txt", ios_base::in);

    int N, M, K;
    cin >> N >> M >> K;

    Cardset.assign(M, 0);
    for (int i = 0; i < M; i++)
    {
        cin >> Cardset[i];
    }

    nonOverapSet act(N + 1);
    sort(Cardset.begin(), Cardset.end());

    for (int i = 0; i < K; i++)
    {
        int q;
        cin >> q;
        int start = 0;
        int end = M - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (act.find(Cardset[mid]) <= q)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        // cout << '\t' << end << '\n';
        cout << act.find(Cardset[end]) << '\n';
        act.Union(end == 0 ? 0 : Cardset[end - 1], Cardset[end]);
    }
}
