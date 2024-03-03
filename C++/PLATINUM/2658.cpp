#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;


int serializer[100001];
int idxes[1000001];
int parents[1000001];
vector<pair<int, int>> inputs {};

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("2658.txt", ios_base::in);
    
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        inputs.push_back(make_pair(a, b));
    }
    sort(inputs.begin(), inputs.end());

    int serializerS = 0;
    int serializerE = 0;

    for (int i = 0; i < N; i++)
    {
        int inp = inputs[i].second;
        int S = serializerS;
        int E = serializerE;
        while (S < E)
        {
            int M = (S + E) / 2;
            if (serializer[M] == inp)
            {
                E = M;
                break;
            }
            else if (serializer[M] < inp)
            {
                S = M + 1;
            }
            else if (serializer[M] > inp)
            {
                E = M;
            }
        }
        // upperbound 찾아냄

        // 그중에서 end일경우만 추가하며 
        // 나머지는 값이 무엇인지 변경해주고 자기의 인덱스가 어딘지 변경해준다.
        // 
        if (E == serializerE)
        {
            serializer[serializerE++] = inp;
            parents[i] = i == 0? -1 : idxes[E - 1];
        }
        else
        {
            serializer[E] = inp;
            parents[i] = idxes[E - 1];
        }
        idxes[E] = i;
    }
    
    int Last = N - 1;
    int lastSelected = idxes[serializerE - 1];


    vector<int> stack {};
    // for (int j = 0; j < serializerE; j++)
    // {
    //     cout << serializer[j] << ' ';
    // }
    // cout << '\n';
    // for (int j = 0; j < serializerE; j++)
    // {
    //     cout << idxes[j] << ' ';
    // }
    // cout << '\n';
    // for (int j = 0; j < 8; j++)
    // {
    //     cout << parents[j] << ' ';
    // }
    // cout << '\n';

    for (int k = 0; k < serializerE; k++)
    {
        /* code */
        // cout << Last << ' ' << lastSelected << '\n';
        while (Last > lastSelected)
        {
            stack.push_back(inputs[Last--].first);
        }
        Last--;
        lastSelected = parents[lastSelected];
    }
    while (Last >= 0)
    {
        stack.push_back(inputs[Last--].first);
    }
    cout << stack.size() << '\n';
    for (int ans = stack.size() - 1; ans >= 0; ans--)
    {
        cout << stack[ans] << '\n';
    }    
}