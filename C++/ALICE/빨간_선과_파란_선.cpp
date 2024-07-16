#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> sortedIndex(31, 0);
vector<int> sortedValue(31, 0);
vector<vector<int>> adjList(31, vector<int>(31, 0));
int isConnected[31][31] = {0};
int N;

int findAddConnection(int x, int y)
{
    int answer = 0;
    for (int uIndex = 0; uIndex < N; uIndex++)
    {
        if (!adjList[x][uIndex])
        {
            continue;
        }
        for (int vIndex = 0; vIndex < N; vIndex++)
        {
            if (!adjList[y][vIndex])
            {
                continue;
            }

            if (!isConnected[uIndex][vIndex])
            {
                // cout << "안녕하세요 " << uIndex << ' ' << vIndex << '\n';
                // adjList[uIndex][vIndex] = 1;
                // adjList[vIndex][uIndex] = 1;
                // sortedValue[uIndex]++;
                // sortedValue[vIndex]++;
                answer++;
            }
        }
    }
    return answer;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("빨간_선과_파란_선.txt", ios_base::in);
    int answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        adjList[i][i] = 1;
        isConnected[i][i] = 1;
    }

    for (int i = 0; i < N - 1; i++)
    {
        int isBlue;
        cin >> isBlue;
        int u = 0;
        int v = 1;
        int timeValue = isBlue ? 0 : 100000000;
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < x; y++)
            {
                if (!isConnected[x][y])
                {
                    int addNum = findAddConnection(x, y);
                    cout << x << ' ' << y << '\n';
                    cout << '\t' << addNum << '\n';
                    if (isBlue)
                    {
                        if (addNum > timeValue)
                        {
                            u = x;
                            v = y;
                            timeValue = addNum;
                        }
                    }
                    else
                    {
                        if (addNum < timeValue)
                        {
                            // cout << "뒤집" << '\n';
                            u = x;
                            v = y;
                            timeValue = addNum;
                        }
                    }
                }
            }
        }
        // cout << u << v << '\n';
        isConnected[u][v] = 1;
        isConnected[v][u] = 1;
        adjList[u][v] = 1;
        adjList[v][u] = 1;
        if (!isBlue)
        {
            answer += timeValue;
        }
        cout << u << ' ' << v << '\n';
        cout << timeValue << ' ' << answer << '\n';
        for (int uIndex = 0; uIndex < N; uIndex++)
        {
            if (!adjList[u][uIndex])
            {
                continue;
            }
            for (int vIndex = 0; vIndex < N; vIndex++)
            {
                if (!adjList[v][vIndex])
                {
                    continue;
                }
                if (!adjList[uIndex][vIndex])
                {
                    adjList[uIndex][vIndex] = 1;
                    adjList[vIndex][uIndex] = 1;
                    isConnected[vIndex][uIndex] = 1;
                    isConnected[uIndex][vIndex] = 1;
                }
            }
        }
        // for (int x = 0; x < N; x++)
        // {
        //     for (int y = 0; y < N; y++)
        //     {
        //         cout << adjList[x][y] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    cout << answer;
}
