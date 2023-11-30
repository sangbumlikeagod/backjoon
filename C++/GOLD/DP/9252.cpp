#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


pair<int, pair<int, int>> LCSARRAY[1001][1001];
string baseword;
string compareword;

int LCS(int indexBase, int indexCompare){
    if (indexBase < 0 | indexCompare < 0){
        return 0;
    }
    if (LCSARRAY[indexBase + 1][indexCompare + 1].first){
        return LCSARRAY[indexBase + 1][indexCompare + 1].first;
    }
    int res = 0;
    int tmp = 0;
    int k = 0;

    while (indexCompare - k >= 0){
        if (baseword[indexBase] == compareword[indexCompare - k]){
            tmp = LCS(indexBase - 1, indexCompare - k - 1) + 1;

            if (res < tmp){
                res = tmp;
                LCSARRAY[indexBase + 1][indexCompare + 1].second = make_pair(indexBase, indexCompare - k);
                
                // LCSARRAY[indexBase + 1][indexCompare + 1].second = make_pair(indexBase + 1, indexCompare - k + 1);
                
                // LCSARRAY[indexBase + 1][indexCompare + 1].second = make_pair(indexBase, indexCompare - k);

                // if (baseword[indexBase - 1] == compareword[indexCompare - k - 1]){
                //     LCSARRAY[indexBase + 1][indexCompare + 1].second = make_pair(indexBase, indexCompare - k);
                // } else {
                //     LCSARRAY[indexBase + 1][indexCompare + 1].second = LCSARRAY[indexBase][indexCompare - k].second;
                // }

            }
            break;
        }
        k++;
    }

    tmp = LCS(indexBase - 1, indexCompare);
    if (res < tmp){
        res = tmp;
        // LCSARRAY[indexBase + 1][indexCompare + 1].second = make_pair(indexBase, indexCompare + 1);
        LCSARRAY[indexBase + 1][indexCompare + 1].second = LCSARRAY[indexBase][indexCompare + 1].second;
        
        // if (baseword[indexBase - 1] == compareword[indexCompare]){
        //     LCSARRAY[indexBase + 1][indexCompare + 1].second = make_pair(indexBase, indexCompare + 1);
        // } else {
        //     LCSARRAY[indexBase + 1][indexCompare + 1].second = LCSARRAY[indexBase][indexCompare + 1].second;
        // }
    }

    LCSARRAY[indexBase + 1][indexCompare + 1].first = res;
    return LCSARRAY[indexBase + 1][indexCompare + 1].first;
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

    // for (int i = 0; i <= wordlength; i++){
    //     for (int j = 0; j <= wordlength; j++){
    //         cout << LCSARRAY[i][j].first << '(' << LCSARRAY[i][j].second.first << ' ' << LCSARRAY[i][j].second.second << ')' << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<char> stack;
    if (res){
        pair<int, int> tracking = LCSARRAY[wordlength][comparelength].second;
        while (tracking.first > 0 | tracking.second > 0){
            if (baseword[tracking.first] == compareword[tracking.second]){
            stack.push_back(baseword[tracking.first]);}
            tracking = LCSARRAY[tracking.first][tracking.second].second;
        }
        if (baseword[0] == compareword[0]){stack.push_back(baseword[0]);}
    }


    while (!stack.empty())
    {
        cout << stack[stack.size() - 1];
        stack.pop_back();
    }
    
}