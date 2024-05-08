#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Trie
{
public:

    int num;
    char val;
    Trie* next[26];

    Trie(char val) : val(val), num(0) {
        for (int idx = 0; idx < 26; idx++)
        {
            next[idx] = nullptr;
        }
    }; 
    void addWord(string word)
    {
        // cout << word << " 의 위치를 확인 " << '\n';
        if (word.empty() == false)
        {
            int nextidx = word[0] - 'a';
            if (next[nextidx] == nullptr)
            {
                next[nextidx] = new Trie(word[0]);
            }
            next[nextidx]->addWord(word.substr(1));
        }
        num++;
    }
    void deleteWord(string word)
    {   
        
        if (word.empty() == false)
        {
            int nextidx = word[0] - 'a';
            next[nextidx]->deleteWord(word.substr(1));
            if (next[nextidx]->empty())
            {
                // cout << "지워줄 수 있는지 확인 \t\t" << word << '\n';
                delete next[nextidx];
                next[nextidx] = nullptr;
            }
        }
        num--;
    }
    Trie* fillUpTable(char c, int index, vector<int> &table)
    {   
        // cout << "fullUpTable " << c << '\n';
        if (c == '#')
        {
            table[index] = num;
            // cout << "끝에 다다랐다는 의미 \n";
            return nullptr;
        }
        if (index != -1)
        {
            // cout << num << "    여 위치까지 오는지 확인 " << num << '\t' << index << '\n'; 
            table[index] = num;
            // cout << "인덱스 문제인지 확인" << index << '\n';
        }
        if (next[c - 'a'] != nullptr)
        {
            // cout << "nullptr이 아니었는지 확인 " << '\n';

            return next[c - 'a'];
        }
        else
        {
            // cout << "단어가 없다는의미" << '\n';
            return nullptr;
        }
    

    }

    bool empty()
    {
        return num == 0;
    }

};


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("27652.txt", ios_base::in);
    
    int C;
    cin >> C;
    Trie* headA = new Trie('&');
    Trie* headB = new Trie('&');    

    for (int i = 0; i < C; i++)
    {
        string s;
        cin >> s;
       

        if (s == "add")
        {
            char whichOne;
            cin >> whichOne;
            if (whichOne == 'A')
            {
                string word;
                cin >> word;
                headA->addWord(word);
            } 
            else 
            {
                string word;
                cin >> word;
                reverse(word.begin(), word.end());
                headB->addWord(word);
            }
        }
        else if (s == "delete")
        {
            char whichOne;
            cin >> whichOne;
            string word;
            cin >> word;
            // cout << whichOne << ' ' << word << '\n';
            
            if (whichOne == 'A')
            {   
                headA->deleteWord(word);
            }
            else 
            {
                reverse(word.begin(), word.end());
                headB->deleteWord(word);
            }
        }
        else
        {
            string word;
            cin >> word;
            int wordLength = word.length();
            if (wordLength == 1)
            {
                cout << 0 << '\n';
                continue;
            } 
            vector<int> vectorA (wordLength, 0);
            vector<int> vectorB (wordLength, 0);
            Trie* fillA = headA;
            Trie* fillB = headB;
            for (int j = -1; j < wordLength; j++)
            {
                // cout << "인덱스 순환 " << j << '\n';
                char ca = j != wordLength - 1 ? word[j + 1] : '#';
                char cb = j != wordLength - 1 ? word[wordLength - j - 2] : '#';
                cout << '\n' << "ca와 cb  " << ca  << ' ' << cb << '\n';
                // cout << cb - 'a';
                
                if (fillA != nullptr) 
                {
                    Trie* newA = fillA->fillUpTable(ca, j, vectorA);
                    fillA = newA;
                    // if (fillA)
                    // {
                    //     cout << fillA->val << '\n';
                    // }
                    // cout << "리턴이 문제가 아니라는 의미" << '\n';
                }
                if (fillB != nullptr)
                {
                    // cout << "리턴이 문제가 아니라는 의미 \n";
                    Trie* newB = fillB->fillUpTable(cb, j, vectorB);
                    fillB = newB;
                    // if (fillB == nullptr)
                    // {
                    //     cout << "여기서 끊겼다는 의미" << '\n';
                    // }
                    // else 
                    // {
                    //     cout << "B의 유효성을 확인 " << fillB->val << '\n';
                    // }
                }
            }
            // for (int a: vectorA)
            // {
            //     cout << a << '\t';
            // }
            // cout << '\n';

            // for (int b: vectorB)
            // {
            //     cout << b << '\t';
            // }
            // cout << '\n';
            int ans = 0;
            for (int j = 0; j < word.length() - 1; j++)
            {
                ans += vectorA[j] * vectorB[word.length() - j - 2];
            }
            cout << ans << '\n';
        }
    }
}
