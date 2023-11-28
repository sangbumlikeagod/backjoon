#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


int LCSARRAY[1001][1001];
string baseword;
string compareword;

int LCS(int indexBase, int indexCompare){
    if (indexBase < 0 | indexCompare < 0){
        return 0;
    }
    if (LCSARRAY[indexBase + 1][indexCompare + 1]){
        return LCSARRAY[indexBase + 1][indexCompare + 1];
    }
    int res = 0;
    int tmp = 0;


    if (baseword[indexBase] == compareword[indexCompare])
    {
        tmp = LCS(indexBase - 1, indexCompare - 1); 
        tmp += 1;
        if (res < tmp){
        res = tmp;
        }
    } 
    else 
    {
    if (indexBase){
        tmp = LCS(indexBase - 1, indexCompare); 
        if (res < tmp){
            res = tmp;
        }}

        if (indexCompare){
        tmp = LCS(indexBase, indexCompare - 1); 

        if (res < tmp){
            res = tmp;
        }}
    }

    LCSARRAY[indexBase + 1][indexCompare + 1] = res;
    return LCSARRAY[indexBase + 1][indexCompare + 1];
}

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
    int res = LCS(wordlength - 1, comparelength - 1);
    cout << res << '\n';

    for (int i = 0; i <= wordlength; i++){
        for (int j = 0; j <= comparelength; j++){
            cout << LCSARRAY[i][j] << '(' << LCSARRAY[i][j] << ' ' << LCSARRAY[i][j] << ')' << ' ';
        }
        cout << '\n';
    }

    
}