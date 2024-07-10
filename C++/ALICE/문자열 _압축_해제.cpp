#include <iostream>
#include <string>

using namespace std;
string s;
int sSize;

int unzip(int &index)
{
    int res = 0;
    while (index < sSize)
    {
        if (s[index] == '(')
        {
            res--;
            index++;
            res += (s[index - 2] - '0') * unzip(index);
        }
        else if (s[index] == ')')
        {
            index++;
            return res;
        }
        else
        {
            index++;
            res++;
        }
    }
    return res;
}

int main()
{
    cin >> s;
    sSize = s.length();
    int arg = 0;
    cout << unzip(arg);
}
