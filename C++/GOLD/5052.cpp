#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

struct Trie
{
    int val;
    Trie* SubTrie[10];
    Trie(int val) : val(val) {};
    bool SearchTrie(Trie* node, bool isSame)
    {   
        cout << node -> val << '\t' << isSame << '\n';
        if (!isSame)
        {
            int isThereOthers = 0;
            for (int i = 0; i < 10; i++)
            {
                if (SubTrie[i])
                {
                    isThereOthers++;
                }
            }
            if (!isThereOthers)
            {
                return false;
            }
        }
        int degree = 1;
        while (node -> val / degree)
        {
            degree *= 10;
        }
        degree /= 10;
        
        int wherePut = node -> val / degree;
        int nextVal = node -> val % degree;

        if (nextVal == 0)
        {
            for (int i = 0; i < 10; i++)
            {
                if (SubTrie[i])
                {
                    return false;
                }
            }
            return true;
        }

        Trie* nextTrie = new Trie(nextVal);

        if (SubTrie[wherePut])
        {
            return SubTrie[wherePut] ->SearchTrie(nextTrie, false);
        }
        else
        {
            SubTrie[wherePut] = nextTrie;
            return SubTrie[wherePut] ->SearchTrie(nextTrie, true);
        }
    } 
};


Trie *Head = new Trie(-1);
int N;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("5052.txt", ios_base::in);
    cin >> N;
    for (int tc = 0; tc < N; tc++)
    {
        int numofPhone;
        cin >> numofPhone;
        for (int ppPhone = 0; ppPhone < numofPhone; ppPhone++)
        {
            int phoneNumber;
            cin >> phoneNumber;
            if (!Head -> SearchTrie(new Trie(phoneNumber), true))
            {
                cout << "FALSE" << '\n';
                continue;
            }
        }
        cout << "TRUE" << '\n';
    }
    

    
}