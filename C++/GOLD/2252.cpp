#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

int studentLine[32001] = {0};
int studentPositionInLine[32001] = {0};
int MaxStudent;


int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("2252.txt", ios_base::in);
    
    
    int command;
    cin >> MaxStudent >> command;

    for (int i = 0; i < MaxStudent; i++)
    {
        studentLine[i] = i + 1;
        studentPositionInLine[i] = i;
    }
    for (int m = 0; m < command; m++)
    {
        int small, big;
        cin >> small >> big;
        // x번 학생이 어디있는가 ? 
        int smallIndex = studentPositionInLine[small - 1]; 
        int bigIndex = studentPositionInLine[big - 1];
        if (smallIndex > bigIndex)
        {
            cout << smallIndex << bigIndex << '\n';
            swap(studentLine[bigIndex], studentLine[smallIndex]);
            swap(studentPositionInLine[big - 1], studentPositionInLine[small - 1]);
        } 
    }
    
    for (int i = 0; i < MaxStudent; i++)
    {
        cout << studentLine[i] << ' ';
    }
    
}