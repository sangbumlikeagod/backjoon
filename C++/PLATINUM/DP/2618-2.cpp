#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Node   
{
    int val;
    int cops;
    Node* before;
    Node(int val) : val(val), cops(0), before(nullptr) {};
};
const int MAXVAL = 10000000;
Node* table[1001][1001];

pair<int, int> trail[1001] = {};
int trail2[1001] = {};

 
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2618.txt", ios_base::in);    
    int N;
    cin >> N;
    int W;
    cin >> W;
    
    

    
    // w번 반복
    // i번 사건을 경찰차 1이 해결할 때 
    Node* ans = new Node(MAXVAL); 
    table[0][0] = new Node(0);
    for (int i = 1; i <= W; i++)
    {
        cout << i << '\n';
        // i 번째 일
        int a, b;
        cin >> a >> b;
        // 두번째 일을 해야한다? 0, 1 1, 0 이 나서야지
        if (i == 1) {
            
        }
        for (int j = 0; j < i - 1; j++)
        {
            
        }
        
    }
    
    }