#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

struct Trie
{
    char val;
    Trie* SubTrie[10] = {nullptr, };
    Trie(char val) : val(val) {
        for (int i = 0; i < 10; i++)
        {
            SubTrie[i] = nullptr;
        }
    };
    bool SearchTrie(string val, bool madeByMe)
    {   
        // 지금 내 값을 나누기
        if (madeByMe == false)
        {
            bool NoSubStr = true;
            for (int i = 0; i < 10; i++)
            {
                if (SubTrie[i])
                {
                    NoSubStr = false;
                    break;
                }
            }
            if (NoSubStr)
            {
                return false;
            }
        }
        // cout << val << '\n';
        
        char nextTrie = val[0];
        string nextEnt;
        if (val.length() > 1)
        {
            nextEnt = val.substr(1);
        }
        else
        {
            char nextTrie = val[0];
            if (SubTrie[nextTrie - '0'])
            {
                return false;
            }
            else
            {
                SubTrie[nextTrie - '0'] = new Trie(nextTrie);
                return true;
            }
        }

    
    
        if (SubTrie[nextTrie - '0'])
        {
            // cout << val << '\n';

            return SubTrie[nextTrie - '0'] -> SearchTrie(nextEnt, false);
        }
        else
        {

            SubTrie[nextTrie - '0'] = new Trie(nextTrie);
            return SubTrie[nextTrie - '0'] -> SearchTrie(nextEnt, true);
        }

    } 
};


int N = 0;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("5052.txt", ios_base::in);
    cin >> N;
    for (int tc = 0; tc < N; tc++)
    {
        Trie *Head = new Trie('1');

        
        int numofPhone;
        cin >> numofPhone;
        // cout << numofPhone << '\n';
        bool isNotFound = true;
        for (int ppPhone = 0; ppPhone < numofPhone; ppPhone++)
        {
            string phoneNumber;
            cin >> phoneNumber;

            // cout << phoneNumber <<  '\n' << phoneNumber.substr(1) << '\n';
            if (isNotFound && !Head -> SearchTrie(phoneNumber, true))
            {
                isNotFound = false;
                cout << "NO" << '\n';
                continue;
            }
        }
        if (isNotFound)
        {
            cout << "YES" << '\n';
        }
    }
    

    
}