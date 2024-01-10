#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

double buildings[50];
const int MINVAL = -1000000000;
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1027.txt", ios_base::in);    

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> buildings[i];
    }
    int ans = 0;
    
    
    for (int building = 0; building < N; building++)
    {
        int tmp = 0;
        int left = building - 1;
        int right = building + 1;
        double maxLeft = MINVAL;
        double maxRight = MINVAL;
        while (left >= 0 || right < N){
            if (left >= 0){    
                if ((buildings[left] - buildings[building]) / (building - left) > maxLeft)
                {
                    maxLeft = (buildings[left] - buildings[building]) / (building - left);
                    // cout << maxLeft << '\t';
                    tmp++;
                }
                left--;
            }
            if (right < N){
                if ((buildings[right] - buildings[building]) / (right - building) > maxRight){
                    maxRight = (buildings[right] - buildings[building]) / (right - building);
                    // cout << maxRight << '\t';

                    tmp++;
                }
                right++;
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans;

}