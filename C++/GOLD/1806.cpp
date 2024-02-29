#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

int MAXVAL = 1e5 + 1;
int history[100001] = {0};
int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("1806.txt", ios_base::in);
    
    int left = 0;
    int sum = 0;
    int N, M;
    cin >> N >> M;


    for (int i = 0; i < N; i++)
    {
        cin >> history[i];
        sum += history[i];
        while (sum >= M)
        {
            MAXVAL = min( MAXVAL, i - left + 1);
            sum -= history[left++];
        }
    }
    MAXVAL != 1e5 + 1 ? cout << MAXVAL : cout << 0;
}