#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;


long long countTotal1(long long inp){

    long long forLeft = 0;
    long long forRight = inp;
    long long ans = 0;
    int GreatIndex = 0;
    while (inp >= (1 << GreatIndex))
    {
        GreatIndex++;
    }
    // cout << GreatIndex << '\n'; 
    GreatIndex--;
    while (GreatIndex >= 0)
    {
        ans += (forLeft / 2);


        if (inp & (1 << GreatIndex))
        {
            forRight -= (1 << GreatIndex);
            ans += forRight + 1;
            forLeft |= (1 << GreatIndex);
        }
        GreatIndex--;
        // cout << ans << '\t' << forLeft << '\n';
    }
    
    
    return ans;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("9527.txt", ios_base::in);
    
    long long A, B;
    cin >> A >> B;   
    
    int C = 0;
    int index = 0;
    

    cout << countTotal1(B) - countTotal1(A - 1) << '\n';
    // while (B)
    // {
    //     cout << B << '\t';
    //     // B = (B >> 1);
    //     cout << C << '\t';

    //     cout << (B & 1) << '\t';
    //     if (B & 1 == 1)
    //     {
    //         C |= (1 << index);
    //     }
        
    //     B >>= 1;
    //     index++;
    //     cout << C << '\n';
    // }
    
}