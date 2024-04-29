#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <cstring>
using namespace std;

vector<int> dp[10] = {};
int palabb[100000000] = {0}; 

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("2023.txt", ios_base::in);
    
    int N;
    cin >> N;

    for (int i = 2; i < pow(10, N); i++)
    {
        if (palabb[i] == 0)
        {
            for (int j = i * 2; j < pow(10, N); j += i)
            {
                palabb[j] = 1;
            }
        }
    }

    dp[1] = {2, 3, 5, 7};
    for (int i = 1; i < N; i++)
    {
        for (int j : dp[i])
        {
            // cout << j << '\n';
            for (int prime = 1; prime < 10; prime += 2)
            {
                // cout << j * 10 + prime << '\n';
                if (palabb[j * 10 + prime] == 0)
                {
                    dp[i + 1].push_back(j * 10 + prime);
                    // cout << j * 10 + prime << '\n';
                }
            }
        }
    }

    for (int cand : dp[N])
    {
        cout << cand << '\n';
    }
    
    
}