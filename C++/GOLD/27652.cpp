#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <unordered_map>
using namespace std;


unordered_map<string, int> A[1001];
unordered_map<string, int> B[1001];


class Trie
{
    int num;
    char val;
    Trie* next[26];

    Trie(char val) : val(val) {}; 
    void addWord(string word)
    {
        if (word.empty() == false)
        {
            int nextidx = word[0] - 'a';
            if (next[nextidx] == nullptr)
            {
                next[nextidx] = new Trie(word[0]);
            }
            num++;
        }
    }
    void deleteWord(string word)
    {   
        if (word.empty() == false)
        {
            int nextidx = word[0] - 'a';
            next[word[0] - 'a']->deleteWord(word.substr(1));
            if (next[nextidx]->empty())
            {
                delete next[nextidx];
            }
            num--;
        }
    }
    Trie* fillUpTable()
    {
        
    }
    bool empty()
    {
        return num == 0;
    }
};

int countWord(string word)
{
    int length = word.length();
    int ans = 0;

    for (int i = 1; i < length; i++)
    {
        if (A[i].empty() || B[length - i].empty())
        {
            continue;
        }
        if (A[i].find(word.substr(0, i)) != A[i].end() && B[length - i].find(word.substr(i, length - i)) != B[length - i].end())
        {
            ans++;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("27652.txt", ios_base::in);
    
    int C = 0;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            char whichOne;
            cin >> whichOne;
            string word;
            cin >> word;
            if (whichOne == 'A')
            {   
                A[word.length()][word]++;
            }
            else 
            {
                B[word.length()][word]++;
            }
        }
        else if (s == "delete")
        {
            char whichOne;
            cin >> whichOne;
            string word;
            cin >> word;
            if (whichOne == 'A')
            {   
                A[word.length()].erase(word);
            }
            else 
            {
                B[word.length()].erase(word);
            }
        }
        else
        {
            string word;
            cin >> word;
            cout << countWord(word) << '\n';
        }
        
    }
    

}