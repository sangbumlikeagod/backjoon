#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<int, int> sortedValue;
int playerArray[100001] = {0};
int valueIndexing[1000001] = {0};
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("27172.txt", ios_base::in);
    // memset(valueIndexing, -1, 1000001 * sizeof(int));
    for (int i = 0; i < 1000001; i++)
    {
        valueIndexing[i] = -1000000;
    }

    int N;
    cin >> N;
    for (int inpNum = 0; inpNum < N; inpNum++)
    {
        int inpVal;
        cin >> inpVal;
        valueIndexing[inpVal] = 0;
        playerArray[inpNum] = inpVal;
    }

    // cout << valueIndexing[15] << ' ' << valueIndexing[24] << '\n';
    for (int inpNum = 0; inpNum < N; inpNum++)
    {
        int multifyingNum = playerArray[inpNum];
        int multifyingFactor = 2;
        int testifying = 10;
        while (multifyingNum * multifyingFactor <= 1000000)
        {

            if (valueIndexing[multifyingNum * multifyingFactor] == -1000000)
            {
                multifyingFactor++;
                continue;
            }
            if (testifying)
            {
                // cout << multifyingNum * multifyingFactor << '\t' << valueIndexing[multifyingNum * multifyingFactor] << '\n';
                testifying--;
            }
            valueIndexing[multifyingNum * multifyingFactor]--;
            valueIndexing[multifyingNum]++;
            multifyingFactor++;
        }
        // 이미 했다면 안해도된다. 자기가 이기는 경우는 전부다 세졌
        // cout << '\n';
    }

    for (int inpNum = 0; inpNum < N; inpNum++)
    {
        cout << valueIndexing[playerArray[inpNum]] << ' ';
    }
}