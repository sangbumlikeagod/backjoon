#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;



unordered_map<int, string> nameMapping;
unordered_map<string, int> mapping;
vector<int> scaleOfFile(501, 0);
vector<string> childFile[501];

bool comp(string s1, string s2){
	//string 사전 역순 
    int idx = 0;
    while (idx != s1.length() && idx != s2.length())
    {
        if (s1[idx] != s2[idx])
        {
            return s1[idx] < s2[idx];
        }
        idx++;
    }
    return s1.length() < s2.length();
}


void dfs(int numOfBlank, string s)
{
    for (int i = 0; i < numOfBlank; i++)
    {
        cout << ' ';
    }
    cout << s << '\n';
    
    for (string cS : childFile[mapping[s]])
    {
        dfs(numOfBlank + 1, cS);
    }
} 

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("7432.txt", ios_base::in);
    
    int n;
    cin >> n;
    int idxWord = 0;

    for (int i = 0; i < n; i++)
    {  
        string s = ""; 
        cin >> s;
        vector<string> pop;
        pop.clear();
        string p = "";
        for (int idx = 0; idx < s.length(); idx++)
        {
            if (s[idx] == '\\')
            {
                
                pop.push_back(p);
                if (mapping.find(p) == mapping.end())
                {
                    // cout << p << ' ' << idxWord << '\n';
                    nameMapping[idxWord] = p;
                    mapping[p] = idxWord++;
                }
                p = "";
            }
            else
            {
                p += s[idx];
            }
        }
        // cout << p << '\n';
        
        if (mapping.find(p) == mapping.end())
        {
            // cout << p << ' ' << idxWord << '\n';
            nameMapping[idxWord] = p;
            mapping[p] = idxWord++;
        }
        pop.push_back(p);

        

        for (int j = 0; j < pop.size(); j++)
        {
            if (j != pop.size() - 1)
            {
                bool isOVerlap = false;
                for (int k = 0; k < childFile[mapping[pop[j]]].size(); k++)
                {
                    if (childFile[mapping[pop[j]]][k] == pop[j + 1])
                    {
                        isOVerlap = true;
                        break;;
                    }
                }
                if (!isOVerlap)
                {
                    childFile[mapping[pop[j]]].push_back(pop[j + 1]);
                    scaleOfFile[mapping[pop[j + 1]]]++; 
                }   
            }
        }

    }
    
    
    for (int i = 0; i < n; i++)
    {
        sort(childFile[i].begin(), childFile[i].end(), comp); 
    }
    vector<string> start;
    for (int j = 0; j < n; j++)
    {
        if (scaleOfFile[j] == 0)
        {
            // dfs(0, nameMapping[j]);
            start.push_back(nameMapping[j]);
        }
    }
    sort(start.begin(), start.end(), comp);
    for (string last: start)
    {
        dfs(0, last);

    }
    
    

    // for (unordered_map<int, string>::iterator instance = nameMapping.begin(); instance != nameMapping.end(); instance++)
    // {
    //     cout << instance -> first << '\t' << instance -> second << '\n';
    // }
    // for (unordered_map<string, int>::iterator instance = mapping.begin(); instance != mapping.end(); instance++)
    // {
    //     cout << instance -> first << '\t' << instance -> second << '\n';
    // }

}