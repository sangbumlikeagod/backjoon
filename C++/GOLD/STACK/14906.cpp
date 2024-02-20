#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("14906.txt", ios_base::in);
    cout << "SLURPYS OUTPUT" << '\n';
    int N;
    cin >> N;
    vector<int> stack;
    for (int i = 0; i < N; i++)
    {
        // 초기화 작업
        stack.clear();
        string s;
        cin >> s;
        bool SWITCH = true;
        if (s[0] != 'A' || s[s.length() - 1] != 'G')
        {
            cout << "NO" << '\n';
            continue;
        }
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            // cout << c << '\t';
            if (c == 'A')
            {
                if (!stack.empty() && stack[stack.size() - 1] == 2)
                {
                    SWITCH = false;
                    break;
                }
                stack.push_back(1);
            }
            else if (c == 'B')
            {
                if (stack.empty() || stack[stack.size() - 1] == 2)
                {
                    SWITCH = false;
                    break;
                }
            }
            else if (c == 'C')
            {
                if (!stack.empty())
                {
                    while (stack[stack.size() - 1] == 2)
                    {
                        stack.pop_back();
                    }
                    if (stack.empty())
                    {
                        SWITCH = false;
                        break;
                    }
                    stack.pop_back();
                }
                else
                {
                    SWITCH = false;
                    break;
                }
            }
            else if (c == 'D' || c == 'E')
            {
                stack.push_back(2);
            }
            else if (c == 'F')
            {
                if (stack.empty() || stack[stack.size() - 1] == 1)
                {
                    SWITCH = false;
                    break;
                }
            }
            else if (c == 'H')
            {
                if (i != 0 && s[i - 1] == 'A')
                {
                    stack.pop_back();
                }
                else
                {
                    SWITCH = false;
                    break;
                }
            }
            else if (c == 'G')
            {
                if (stack.empty() || stack[stack.size() - 1] == 1 || (i && s[i - 1] != 'G' && s[i - 1] != 'F'))
                {
                    SWITCH = false;
                    break;
                }
                else
                {
                    while (stack[stack.size() - 1] == 2)
                    {
                        stack.pop_back();
                    }
                }
            }
            else
            {
                SWITCH = false;
                break;
            }
        }
        if (SWITCH && stack.empty())
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
    cout << "END OF OUTPUT" << '\n';
}