#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;


int LCSARRAY[1001][1001];
string baseword;
string compareword;



int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("9252.txt", ios_base::in);    

    cin >> baseword >> compareword;

    if (baseword.length() < compareword.length()){
        string tmp = baseword;
        baseword = compareword;
        compareword = tmp;
    }

    int wordlength = baseword.length();
    int comparelength = compareword.length();

    for (int i = 0; i < wordlength; i++)
    {
        for (int j = 0; j < comparelength; j++)
        {
            if (baseword[i] == compareword[j]) 
            {
                if (i > 0 & j > 0)
                {
                    LCSARRAY[i][j] = LCSARRAY[i - 1][j - 1] + 1;
                }
                else
                {
                    LCSARRAY[i][j] = 1;
                }
            }
            else
            {
                int tmp = 0;
                if ( j > 0 & tmp < LCSARRAY[i][j - 1]) {tmp = LCSARRAY[i][j - 1];}
                if ( i > 0 & tmp < LCSARRAY[i - 1][j]) {tmp = LCSARRAY[i - 1][j];}
                LCSARRAY[i][j] = tmp;
            } 
        }
    }
    cout << LCSARRAY[wordlength - 1][comparelength - 1] << '\n';

    for (int i = 0; i < wordlength; i++){
        for (int j = 0; j < comparelength; j++){
            cout << LCSARRAY[i][j] << ' ';
        }
        cout << '\n';
    }

    vector<char> stack;
    if (LCSARRAY[wordlength - 1][comparelength - 1]){
        pair<int, int> tracking = make_pair(wordlength - 1 ,comparelength - 1);
        while (tracking.first >= 0 & tracking.second >= 0){
            // cout << tracking.first << ' ' << tracking.second << '\n';
            if (baseword[tracking.first] == compareword[tracking.second])
            {
                stack.push_back(baseword[tracking.first]);
                tracking = make_pair(tracking.first - 1 ,tracking.second - 1);
            }
            else
            {
                if (LCSARRAY[tracking.first - 1][tracking.second - 1] == LCSARRAY[tracking.first][tracking.second]) {tracking = make_pair(tracking.first - 1 ,tracking.second - 1);}
                else if (LCSARRAY[tracking.first][tracking.second - 1] == LCSARRAY[tracking.first][tracking.second]) {tracking = make_pair(tracking.first ,tracking.second - 1);}
                else if (LCSARRAY[tracking.first - 1][tracking.second] == LCSARRAY[tracking.first][tracking.second]) {tracking = make_pair(tracking.first - 1 ,tracking.second);}
            }
    }
    }

    while (!stack.empty())
    {
        cout << stack[stack.size() - 1];
        stack.pop_back();
    }
    }