#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
using namespace std;

vector<char> vec(1000000, ' ');
string s1;
string s2;
pair<int, int> *null_pair = new pair<int, int>(-1, -1);

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("9935.txt", ios_base::in);
    cin >> s1 >> s2;
    // cout << s1.length() << '\n' << s2.length();
    int levelS1, levelS2;
    levelS1 = s1.length();
    levelS2 = s2.length() - 1;
    int idx = 0;
    int idxW1 = 0;
    int idxW2;

    while (idx < levelS1)
    {

        vec[idx++] = s1[idxW1++];
        idxW2 = levelS2;
        while (idxW2 >= 0 && idx - 1 >= idxW2 && vec[idx - 1] == s2[idxW2])
        {
            idx--;
            idxW2--;
        }

        if (idxW2 != -1)
        {
            idx += levelS2 - idxW2;
        }
        else
        {
            levelS1 -= (levelS2 + 1);
        }
    }

    if (levelS1 == 0)
    {
        cout << "FRULA";
    }
    else
    {
        for (int i = 0; i < levelS1; i++)
        {
            cout << vec[i];
        }
    }
}
