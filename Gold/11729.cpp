#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
int arr[1048575 * 2] = {0, };
int ptr = 0;
vector<int> vec;
int recur(int num, int from, int to){
    if (num == 1){
        // cout << ptr << "번째에" << from << "을 넣을거야" << '\n';
        arr[ptr] = from;
        ptr++;
        vec.push_back(from);
        // cout << ptr << "번째에" << to << "을 넣을거야" << '\n'; 
        arr[ptr] = to;
        ptr++;
        vec.push_back(to);

        return 1;
    } else {
    int total = 0;
    arr[1] = 1;
    total += recur(num - 1, from, 6 - from - to);
    // cout << ptr << "번째에" << from << "을 넣을거야" << '\n';
    arr[ptr] = from;
    ptr++;
    vec.push_back(from);

    // cout << ptr << "번째에" << to << "을 넣을거야" << '\n';
    arr[ptr] = to;
    ptr++;
    vec.push_back(to);

    total += recur (num - 1, 6 - from - to , to);
    return total + 1;
    }
}


int main(){
    ifstream cin("11729.txt", ios_base::in);
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    // 재귀를 생각하는법 : 중간을 생각해라
    // n - 1 개를 2번으로 옮기고 n을 3번으로 옮긴뒤 n - 1을 3번으로 옮긴다
    int n;
    cin >> n;
    int final = recur(n, 1 ,3);
    // cout << "=====" << vec[1] << "=========";
    cout << final << '\n';
    // for (int a = 0; a < final * 2; a += 2){
    //     cout << a << "번째는" << arr[a] << ' ' << a + 1 << "번째는" << arr[a + 1] << '\n';
    // }
    for (int a=0; a < final * 2; ){
        cout << vec[a++] << ' ' << vec[a++] << '\n';
    }
}