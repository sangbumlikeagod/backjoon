#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<int> storedDesign(100001, 0);
vector<vector<int>> commands(100001, vector<int>{});

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2357.txt", ios_base::in);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int tm;
        cin >> tm;
        storedDesign[i] = tm;
    }
}