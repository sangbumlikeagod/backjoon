#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
map<int, int> arrayD;
vector<int> vc;

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < pow(2, N); i++)
    {
        int ac;
        cin >> ac;
        if (ac)
            arrayD[ac]++;
    }
    map<int, int>::iterator arg = arrayD.begin();
    while (arg != arrayD.end())
    {
        for (int j = 0; j < pow(2, vc.size()); j++)
        {
            int val = arg->first;
            int pointer = 1;
            for (int k = 0; k < vc.size(); k++)
            {
                if (j & pointer)
                {
                    val += vc[k];
                }
                pointer <<= 1;
            }
            if (val != arg->first && arrayD.find(val) != arrayD.end())
            {
                arrayD[val]--;
                if (arrayD[val] == 0)
                {
                    arrayD.erase(val);
                }
            }
        }
        vc.push_back(arg->first);
        if (arg->second == 1)
        {
            arg++;
        }
        else
        {
            arg->second--;
        }
    }

    for (int v : vc)
    {
        cout << v << ' ';
    }
}
