#include <iostream>
#include <stdio.h>
using namespace std;


int main(){

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