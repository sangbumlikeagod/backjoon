#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;


unordered_set<int> ismalfunction;

bool ispossible(int val){
    bool ispossible = true;
    if (val == 100) break;

    while (val){
    if (ismalfunction.count(val % 10)) {
        ispossible = false;
        return true;
    }
    }
    if (ispossible) {
        return true;
    }
    else false;
    
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1107.txt", ios_base::in);    
    int start;
    cin >> start;
    int malfunction;
    cin >> malfunction;
    
    for (int i = 0; i < malfunction; i++)
    {
        int j;
        cin >> j;
        ismalfunction.insert(j);
    }
    int ans = 0;
    int startleft = start, startright = start;
    while (true){
        int startCopy = start;
        bool ispossible = true;
        while (startCopy){

        }
        


    }
    



}