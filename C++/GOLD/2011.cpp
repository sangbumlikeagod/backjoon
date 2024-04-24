#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int testify[5001];

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("2011.txt", ios_base::in);
    string s;
    cin >> s;
    testify[0] = 1;
    bool right = true;

    for (int i = 0; i < s.length(); i++)
    {
        // cout << i << '\t' << testify[i] << '\n';
        if (s[i] == '0')
        {
            if ((i == 0 || (s[i - 1] != '1' && s[i - 1] != '2')))
            {
                right = false;
                break;
            }
            continue;
        }
        
        if (s[i] == '1')
        {
            testify[i + 2] += testify[i];
            testify[i + 2] %= 1000000;
            // cout << testify[i + 2] << '\n' << '\n';
        }  
        else if (s[i] == '2' && i != s.length() - 1 && s[i + 1] - '0' < 7)
        {
            testify[i + 2] += testify[i];
            testify[i + 2] %= 1000000;
            //  cout << testify[i + 2] << '\n' << '\n';
        }
        if (i == s.length() - 1 || s[i + 1] != '0')
        {
            testify[i + 1] += testify[i];
            testify[i + 1] %= 1000000;
            //  cout << testify[i + 1] << '\n' << '\n'; 
        }
    }
    if (right)
    {
        cout << testify[s.length()] % 1000000;
    }
    else 
    {
        cout << 0;
    }

}