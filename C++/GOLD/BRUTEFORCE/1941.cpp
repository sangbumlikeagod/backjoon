#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int classTable[5][5] = {0};
int visited;
int ans = 0;

vector<int> backtrackingSerializer;

void backtracking(int n, int S, int Y, int st)
{
    if (backtrackingSerializer.size() == 7)
    {
        if (isConnected())
        {
            ans++;
        }
    }
}

bool isConnected()
{
    for (int i : backtrackingSerializer)
    {
        bool Found = false;
        for (int j : backtrackingSerializer)
        {
            if (abs(i - j) == 1 || abs(i - j) == 5)
            {
                Found = true;
            }
        }
        if (!Found)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1941.txt", ios_base::in);

    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++)
        {
            classTable[i][j] = s[j];
        }
    }
}