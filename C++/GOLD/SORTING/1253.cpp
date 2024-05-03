#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

int forOverlap[2001] {0};
unordered_map<int, int> mapps;
unordered_map<int, int> OVERLAP;
vector<int> stackwithoutDouble {};


int binarySearch(int i, int j, int val)
{   
    // cout << val << '\n';
    while (i < j)
    {
    
        int mid = (i + j) / 2;
        // cout << i << ' ' << j << ' ' << mid << ' ' << val << ' ' <<  stackwithoutDouble[mid] << '\n';  
    
        if (stackwithoutDouble[mid] == val)
        {
            // cout << mid << '\n';
            return mid;
        }
        else if (stackwithoutDouble[mid] > val)
        {
            // cout << stackwithoutDouble[mid]  << '\n';
            j = mid;
            // cout << "우웩" << '\n';
        }
        else
        {
            i = mid + 1;
        }
    }
    if (stackwithoutDouble[i] == val)
    {
        return i;
    }
    return -1;

}

int check(int next, int i, int j, int target)
{
    if (next == -1)
    {
        return 0;
    }
    else if (next == i && mapps[stackwithoutDouble[i]]<= 1)
    {
        return 0;
    }
    else if (next == j && mapps[stackwithoutDouble[j]] <= 1)
    {
        return 0;
    }
    else if (i == j && i != next && mapps[stackwithoutDouble[i]] <= 1)
    {
        return 0;
    }
    else if (i == j && i == next && mapps[stackwithoutDouble[i]] <= 2)
    {
        return 0;
    }
    else
    {
        return mapps[stackwithoutDouble[target]];
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("1253.txt", ios_base::in);
    int N;
    cin >> N;
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        int in;
        cin >> in; 
        if (mapps.find(in) == mapps.end())
        {   
            stackwithoutDouble.push_back(in);
        }
        mapps[in]++;
        // cout << in << '\t' << mapps[in] << '\n';
    }
    sort(stackwithoutDouble.begin(), stackwithoutDouble.end());
    // for (int i = 0; i < stackwithoutDouble.size(); i++)
    // {
    //     cout << stackwithoutDouble[i] << '\t';
    // }
    // cout << '\n' << '\n';
    

    for (int i = 0; i < stackwithoutDouble.size(); i++)
    {
        for (int j = stackwithoutDouble.size() - 1; j >= i; j--)
        {
            // cout  << '\t' << i << '\t' << j << '\n'; 

            int next = binarySearch(0, stackwithoutDouble.size() - 1, stackwithoutDouble[j] + stackwithoutDouble[i]);
            // cout <<  next << '\t' << i << '\t' << j << '\n'; 

            int checkNum = check(next, i, j, next);

            if (checkNum && !OVERLAP[next]) 
            {
                OVERLAP[next]++;
                ans += checkNum;
            }

            next = binarySearch(0, stackwithoutDouble.size() - 1, stackwithoutDouble[j] - stackwithoutDouble[i]);
            checkNum = check(next, i, j, j);
            if (checkNum && !OVERLAP[j])
            {
                OVERLAP[j]++;
                // cout << '\t' << stackwithoutDouble[i] << ' ' << stackwithoutDouble[next] << ' ' << stackwithoutDouble[j] << '\n';
                ans += checkNum;
            }

            next = binarySearch(0, stackwithoutDouble.size() - 1, stackwithoutDouble[i] - stackwithoutDouble[j]);
            checkNum = check(next, i, j, i);
            if (checkNum && !OVERLAP[i])
            {
                OVERLAP[i]++;
                // cout << "\t\t" << stackwithoutDouble[j] << ' ' << stackwithoutDouble[next] << ' ' << stackwithoutDouble[i] << '\n';

                ans += checkNum;
            }
            
        }
    }

    cout << ans << '\n';
    
}