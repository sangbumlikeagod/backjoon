#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <cstring>
using namespace std;

vector<int> dp[10] = {};

bool isPrime(int gal)
{
    if (gal == 2 || gal == 3 || gal == 5 || gal == 7)
    {
        return true;
    }
    for (int i = 2; i * i<= gal ; i++)
    {
        if (gal % i == 0)
        {
            return false;
        }
    }
    return isPrime(gal / 10);
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("2023.txt", ios_base::in);
    
    int N;
    cin >> N;


    dp[1] = {2, 3, 5, 7};
    for (int i = 1; i < N; i++)
    {
        for (int j : dp[i])
        {
            // cout << j << '\n';
            for (int prime = 1; prime < 10; prime += 2)
            {
                // cout << j * 10 + prime << '\n';
                if (isPrime(j * 10 + prime))
                {
                    dp[i + 1].push_back(j * 10 + prime);
                    // cout << j * 10 + prime <j < '\n';
                }
            }
        }
    }

    for (int cand : dp[N])
    {
        cout << cand << '\n';
    }
    
    
}