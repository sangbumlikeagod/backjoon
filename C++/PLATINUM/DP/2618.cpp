#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Node   
{
    int val;
    Node* before;
    Node(int val) : val(val), before(nullptr) {};
};

Node* table[1001][1001];



int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2618.txt", ios_base::in);    
    vector<pair<int, int>> stacks;
    int N;
    cin >> N;
    int W;
    cin >> W;
    
    
    int ans = 0;
    cout << (table[0][0] == nullptr) << endl;
    
    // w번 반복
    // i번 사건을 경찰차 1이 해결할 때 

}