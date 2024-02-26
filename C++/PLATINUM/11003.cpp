#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;



struct P {
    int idx;
    int val;
    P(int idx, int val) : idx(idx), val(val){};
};
deque<P> deq;


int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("11003.txt", ios_base::in);
    int N, L;
    cin >> N >> L;
    
    for (int i = 0; i < N; i++)
    {
        int v;
        cin >> v;

        if (i >= L && deq.front().idx == i - L)
        {
            deq.pop_front();
        }

        while (deq.empty() == false && deq.back().val > v)
        {
            deq.pop_back();
        }
        deq.push_back(P(i, v));
        cout << deq.front().val << ' ';
        
    }
    
}