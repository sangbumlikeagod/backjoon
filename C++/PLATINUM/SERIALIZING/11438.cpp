#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int logStore[100001][21];

int maxLog = 1;
int findNthParent(int N, int node)
{
    int maxInThisProblem = maxLog - 1;

    if (node == 1) return 1;
    if (N == 0) return logStore[node][1];

    return findNthParent(N - 1, logStore[node][N - 1]);
    
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("11438.txt", ios_base::in);
    int N;
    cin >> N;

    int maxContainable = 1;
    while (maxContainable < N)
    {
        maxContainable *= 2;
        maxLog++;
    }
    // cout << maxLog << '\n';
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b) {swap(a, b);}
        // cout << a << '\t' << b << '\n';
        logStore[b][1] = a;
    }
    for (int i = 0; i < N; i++)
    {
        if (logStore[i][1] == 0)
        {
            logStore[i][1] = 1;
        }
    }

    for (int nThparent = 1; nThparent < maxContainable; nThparent++)
    {
        for (int i = N; i >= 0; i--)
        {
            logStore[i][nThparent + 1] = findNthParent(nThparent , i);
        }
    }
    
    

    int numOfOutput;
    cin >> numOfOutput;
    for (int output = 0; output < numOfOutput; output++)
    {
        int small, large;
        cin >> small >> large;
        if (small > large)
        {
            swap(small, large);
        }
         while (small != large)
        {
            while (small < large)
            {
                bool isChanged = false;
                for (int changable = maxLog; changable > 0; changable--)
                {
                    if (logStore[large][changable] > small)
                    {
                        large = logStore[large][changable];
                        isChanged = true;
                        break;
                    }
                } 
                if (isChanged == false) 
                {
                    large = logStore[large][1];
                }
            }
            if (small > large)
            {
                swap(small, large);
            }
        }
        cout << small << '\n';
    }
    

    
    
}