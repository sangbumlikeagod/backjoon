#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

long long ptsum(long long s, long long e, long long** arr){
    if (e == s){
        return arr[s][s];
    }
    // if (e - s == 1){
    //     return arr[s][s] + arr[e][e];}
         else {
    if (arr[s][e]){
        return arr[e][s];
    } else {

        long long minn = 10000 * 501 * 250;
        long long min_advo = 0;
        for (long long m = s; m < e; m++){
            long long advo = 0;
            long long tmp = ptsum(s, m, arr) + ptsum(m + 1, e, arr);
            if (s != m){
                advo += arr[s][m];
            }
            if (m + 1 != e){
                advo += arr[m + 1][e];
            }
            if (tmp + advo < minn + min_advo) {
                minn = tmp;
                min_advo = advo;
                }
        }
        // 만드는데 드는 비용들을 조사 
        // 만드는데 드는 총 비용은 하위 애들이 만드는데 드는 비용의 합`
        arr[s][e] = minn + min_advo;
        arr[e][s] = minn;
        // cout << s << ' ' << e << ' ' << arr[s][e] << ' ' <<  minn <<'\n';

        // total += minn;
        return minn;
    }
    }

}


int main(){
    ifstream cin("11066.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    long long T;
    cin >> T;
    // cout << T;
    for (long long test = 0; test < T; test++){
        long long** arr = new long long*[501];
        for (long long i = 0; i < 501 ; i++){
            arr[i] = new long long[501] {0, };  
        }
        long long K;
        cin >> K;

        for (long long i = 1; i < K + 1; i++){
            cin >> arr[i][i];
        }

        // cout << arr[1][1] << '\n';
        ptsum(1, K, arr);
        cout << arr[1][K] << '\n';


        for (long long i = 0; i < 501; i++){
            delete arr[i];
        }
        delete arr;
    }


}   