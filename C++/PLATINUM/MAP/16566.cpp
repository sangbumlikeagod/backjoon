#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

map<int, short> Cardset; 



int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("16566.txt", ios_base::in);    
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        Cardset[n] = 1;
    }

    for (int i = 0; i < K; i++)
    {
        int k;
        cin >> k;
        int card = Cardset.upper_bound(k) -> first;
        cout << card << '\n';
        Cardset.erase(card);
    }
}