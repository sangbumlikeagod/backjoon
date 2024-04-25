#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

// Trie는 다른 Trie를 잇는다.
// 트라이의 메소드로 하는것과 그냥 함수로 하는것 두가지 방법이 있다. 일단 난 그냥 함수의 메소드로 하는 방식으로함
// 그러다보니 어떤 트라이를 만들면 제대로 적용이 안된다. 101 이라고 할때 101그자체를 트라이 함수에 넣고 시작하면 어디서부터 시작되어야 하는걸까
// 항상 이렇게 우선 순위문제, 논리 문제가 있다. 그럴때는 항상 더미를 만들어서 해결하는 습관을 기르자

// 트라이의 밑으로 내려가는 방법은 한가지
struct Trie
{
    char val;
    Trie *SubTrie[10] = {
        nullptr,
    };
    Trie(char val) : val(val)
    {
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

            return SubTrie[nextTrie - '0']->SearchTrie(nextEnt, false);
        }
        else
        {

            SubTrie[nextTrie - '0'] = new Trie(nextTrie);
            return SubTrie[nextTrie - '0']->SearchTrie(nextEnt, true);
        }
    }
};

int N = 0;

int main()
{
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
            if (isNotFound && !Head->SearchTrie(phoneNumber, true))
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