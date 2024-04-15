#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int lineOfThings[40001] {};

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("2352.txt", ios_base::in);
    
    int N;
    cin >> N;
    int maxRight = 0;


    for (int ith = 0; ith < N; ith++)
    {
        int ip;
        cin >> ip;
        int left = 0;
        int right = maxRight;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (lineOfThings[mid] == ip)
            {
                left = mid;
                break;
            }
            else if (lineOfThings[mid] < ip)
            {
                left = mid + 1;
            } 
            else 
            {
                right = mid;
            }
        }
        lineOfThings[left] = ip;
        if (left == maxRight)
        {
            maxRight++;
        }
        
    }
    cout << maxRight;
}