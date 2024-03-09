#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


int A[1000001] = {0};
// int AParents[1000000] = {0};

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("12015.txt", ios_base::in);
    int N;
    cin >> N;

    int x = 0;
    for (int i = 0; i < N; i++)
    {
        /* code */
        int s;
        cin >> s;

        int start = 0;
        int end = x;
        while (start < end)
        {
            int m = (start + end) / 2;
            if (A[m] < s)
            {
                start = m + 1;
            } 
            else if (A[m] > s)
            {
                end = m;
            }
            else {break;}
        }
        if (end == x)
        {
            A[x++] = s; 
        }
        else 
        {
            A[end] = s;
        }
    }
    cout << x;
    
    
}