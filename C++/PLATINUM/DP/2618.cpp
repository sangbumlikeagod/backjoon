#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Node   
{
    int val;
    int cops;
    Node* before;
    Node(int val) : val(val), cops(0), before(nullptr) {};
};
const int MAXVAL = 10000000;
Node* table[1001][1001];

pair<int, int> trail[1001] = {};
int trail2[1001] = {};


int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2618.txt", ios_base::in);    
    int N;
    cin >> N;
    int W;
    cin >> W;
    
    

    
    // w번 반복
    // i번 사건을 경찰차 1이 해결할 때 
    Node* ans = new Node(MAXVAL); 
    table[0][0] = new Node(0);
    for (int i = 1; i <= W; i++)
    {

        int a, b;
        cin >> a >> b;

        if (i == 1)
        {
            int ifCapOne = abs(a - 1) + abs(b - 1);
            int ifCapTwo = abs(N - a) + abs(N - b);
            table[1][0] = new Node(ifCapOne);
            table[1][0]->cops = 1;
            table[0][1] = new Node(ifCapTwo);
            table[0][1]->cops = 2;
        }
        
        for (int j = 0; j < i - 1; j++)
        {   
            int ifCapOne;
            int ifCapTwo;
            if (i - 1 == 0){
                ifCapOne = abs(a - 1) + abs(b - 1);
            } 
            else {
                ifCapOne = abs(a - trail[ i - 1 ].first) + abs(b - trail[i - 1].second); 
            }
            if (!j) 
            {
                ifCapTwo = abs(N - a) + abs(N - b);
            } 
            else 
            {
                ifCapTwo = abs(trail[j].first - a) + abs(trail[j].second - b);
            }
            // cout << "-----" << i  << j  << table[i - 1][j]->val << '\n';    

            if (table[i][j] == nullptr) {table[i][j] = new Node(MAXVAL);}
            if (table[i][j]->val > ifCapOne + (table[i - 1][j]->val)) {
                table[i][j]->val = ifCapOne + (table[i - 1][j]->val);
                table[i][j]->cops = 1;
                table[i][j]->before = table[i - 1][j];
                if (i == W){
                    if ( table[i][j]->val < ans->val ){
                        ans = table[i][j];
                    }
                }
            }

            if (table[i - 1][i] == nullptr) {table[i - 1][i] = new Node(MAXVAL);}
            if (table[i - 1][i]->val > ifCapTwo + (table[i - 1][j]->val)){
                table[i - 1][i]->val = ifCapTwo + (table[i - 1][j]->val);
                table[i - 1][i]->cops = 2;
                table[i - 1][i]->before = table[i - 1][j];
                if (i == W){
                    if ( table[i - 1][i]->val < ans->val ){
                        ans = table[i - 1][i];
                    }
                }
            }

            // cout << "-----" << '\n';    
            
        }
        for (int j = 0; j < i - 1; j++)
        {
            int ifCapOne;
            int ifCapTwo;
            if (j == 0){
                ifCapOne = abs(a - 1) + abs(b - 1);
            } else {
                ifCapOne = abs(trail[j].first - a) + abs(trail[j].second - b);
            }
            if (i - 1 == 0) {
                ifCapTwo = abs(N - a) + abs(N - b);
            } else {
                ifCapTwo = abs(trail[i - 1].first - a) + abs(trail[i - 1].second - b);
            }


            if (table[i][i - 1] == nullptr) table[i][i - 1] = new Node(MAXVAL);
            if (table[i][i - 1]->val > ifCapOne + (table[j][i - 1]->val)) {
                table[i][i - 1]->val = ifCapOne + (table[j][i - 1]->val);
                table[i][i - 1]->cops = 1;
                table[i][i - 1]->before = table[j][i - 1];
                if (i == W){

                    if ( table[i][i - 1]->val < ans->val ){
                        ans = table[i][i - 1];
                    }
                }
            }

            if (table[j][i] == nullptr) table[j][i] = new Node(MAXVAL);
            if (table[j][i]->val > ifCapTwo + (table[j][i - 1]->val)){
                table[j][i]->val = ifCapTwo + (table[j][i - 1]->val);
                table[j][i]->cops = 2;
                table[j][i]->before = table[j][i - 1];
                if (i == W){
                    if ( table[j][i]->val < ans->val ){
                        ans = table[j][i];
                    }
                }
            }

            
        }
        
        trail[i] = make_pair(a, b);
    }

    cout << ans -> val << '\n'; 
    // cout << ans->before->val;
    // ans = ans->before;

    // cout << ans->val;
    // ans = ans->before;

    // cout << ans->val;
    
    trail2[W] = ans->cops;
    for (int w = W - 1; w > 0; w--)
    {
        ans = ans->before;
        trail2[w] = ans->cops;
    }
    for (int w = 1; w <= W; w++)
    {
        cout << trail2[w] << '\n';
    }
    
    
}