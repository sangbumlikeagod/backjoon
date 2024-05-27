#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("2877.txt", ios_base::in);
    
    int N;
    int numDigit = 2;
    int digit = 1;

    cin >> N;
    N--;
    while (numDigit <= N)
    {
        N -= numDigit;
        numDigit *= 2;
        digit++;
    }
    // 최대 digit을 찾았음 
    // cout << N;
    numDigit /= 2;
    while (numDigit)
    {
        if (numDigit & N)
        {
            cout << '7';
        }
        else
        {
            cout << '4';
        }
        numDigit /= 2;
    }
    

}