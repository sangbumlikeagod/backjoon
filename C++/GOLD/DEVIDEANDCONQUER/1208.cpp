#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

// map을 쓸까? 아니면 인접리스트?
map<int, int> goog[41];

int N, M;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1208.txt", ios_base::in);
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        goog[i][0] = 1;
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (map<int, int>::iterator i = goog[i].begin(); i != goog[i].end(); i++)
        {
            /* code */
        }
    }
}