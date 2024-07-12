#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> relations(100001, vector<int>{});
vector<vector<int>> valFirstSecond(100001, vector<int>{0, 10000000});
vector<int> visited(100001, 0);

int checkMyMax(int parents, int myself)
{
    visited[myself] = 1;
    if (parents && relations[myself].size() == 1)
    {
        valFirstSecond[myself][0] = myself;
        valFirstSecond[myself][1] = 0;
        return 0;
    }
    int childMax;
    for (int child : relations[myself])
    {
        if (visited[child])
        {
            continue;
        }
        int myFirst = checkMyMax(myself, child) + myself;
        int mySecond = valFirstSecond[child][0];

        if (myFirst - mySecond > valFirstSecond[myself][0] - valFirstSecond[myself][1])
        {
            valFirstSecond[myself][0] = myFirst;
            valFirstSecond[myself][1] = mySecond;
            childMax = mySecond;
        }
        // childMax = min(childMax, valFirstSecond[child][0]);
    }
    return childMax;
};

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        relations[s].push_back(e);
        relations[e].push_back(s);
    }
    checkMyMax(0, 1);

    for (int i = 1; i <= N; i++)
    {
        cout << (valFirstSecond[i][0] >= valFirstSecond[i][1]) << '\n';
    }
}
