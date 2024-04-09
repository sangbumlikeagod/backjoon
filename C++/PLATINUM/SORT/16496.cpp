#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node
{
    string val;
    bool operator<(Node& b) const {
        // 자리수가 다른 상태에서 
        string v2 = val;
        string v3 = b.val;
        int index1 = 0;
        int index2 = 0;
        int l1 = v2.length();
        int l2 = v3.length();
        int chance = max(l1, l2);
        if (v2 != v3 )
        {
            while (v2[index1] == v3[index2] && chance)
            {
                index1 = (index1 + 1) % l1;
                index2 = (index2 + 1) % l2;
                chance--;
            }
        }

        return v2[index1] > v3[index2];
    }
    Node(string s) : val(s) {};
};


vector<Node> numbersS;
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("16496.txt", ios_base::in);
    int s;
    cin >> s;
    // int a = s[0] - '0';
    for (int num = 0; num < s; num++)
    {
        string inp;
        cin >> inp;
        numbersS.push_back(Node(inp));
    }

    // cout << "sort 전까지 입력"<< '\n';
    sort(numbersS.begin(), numbersS.end());
    if (numbersS[0].val == "0")
    {
        cout << "0";
    }
    else 
    {
        for (int num = 0; num < s; num++)
        {
            cout << numbersS[num].val;
        }
    }
}