#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("11.txt", ios_base::in);
    int a = 5;
    int b = a;
    cout << b << endl; 
    
    int *ptr_b;
    ptr_b = &a;
    a += 3;
    cout << b << endl;

    cout << *ptr_b;

    int arr[30];
    int max_num;
    cin >> max_num;

    for (int i = 0; i < max_num; i++){
        cin >> arr[i]; 
    }
    for (int & x:arr ){
        cout << x;
    }
}