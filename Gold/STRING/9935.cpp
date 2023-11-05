#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

string s1;
string s2;

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("9935.txt", ios_base::in);    
    cin >> s1 >> s2;
    // cout << s1.length() << '\n' << s2.length();
    int levelS1, levelS2;
    levelS1 = s1.length();
    levelS2 = s2.length();
    if (levelS1 < levelS2){
        cout << s1;
    } else {

        vector<int> arrS2(levelS2, 0);
        arrS2[0] = -1;
        int j = 0;
        for (int i = 1; i < levelS2 ; i++ ){

                //  얼마나 같아야하는지를 주기적으로 확인시켜줄 놈
                while (s2[j] != s2[i] && j > 0){
                    
                }

            }
        

        for (int k: arrS2){
            // 여기서 틀렸을때 막 뒤로 가지 말고 몇칸 덜가 봐 라는걸 알려주는 알고리즘 이기 때문에 앞에 k개는 같아 라고 하는것과 같고 k개만큼 덜가겠지 원래 0번이 와야하는데 틀렸으니까 0번이 여기서 부터봐 -> 틀렸는데 겹치는 부분이 있으니까 k번부터 여기서 봐 
            // 
            cout << k << ' ';
        }




    }
    


}