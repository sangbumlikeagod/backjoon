#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

vector<string> container(100, "");
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("9369.txt", ios_base::in);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        container.resize(100, "");
        char aToz[26];
        char aToz2[26];
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> container[i];
        }
        string hint, target;
        cin >> hint >> target;
        memset(aToz, '0', 26);

        // 언급이 안되는 애와 중복으로 되는애들은 고려를 해줘야함
        bool isNoMatch = true;
        for (int i = 0; i < N; i++)
        {
            // 같은 문자 자리에 두번이 박히는지도 알아야하고
            // 대표되는 문자가 두번 박히는지도 알아야함
            char tmp[26];
            memset(aToz, '0', 26);
            memset(tmp, '0', 26);

            // 두 서로 다른 문자가 같은 해석이 되는가에 대한 경우
            memset(aToz2, '0', 26);
            bool isNonoverlap = true;

            for (int j = 0; j < hint.length(); j++)
            {

                char a = container[i][j];
                // 3개중에 하나로 해야한다?
                // container에 저장된 각 문자들이 hint 문자로 변환됨
                if ((aToz[a - 'a'] != '0' && aToz[a - 'a'] != hint[j]) || (aToz2[hint[j] - 'a'] != '0' && aToz2[hint[j] - 'a'] != a))
                {
                    isNonoverlap = false;
                    break;
                }
                else
                {
                    aToz[a - 'a'] = hint[j];
                    aToz2[hint[j] - 'a'] = a;
                }

                if (j == hint.length() - 1)
                {
                    cout << j << '\n';
                    isNoMatch = false;
                }
            }
            if (!isNonoverlap)
            {
                continue;
            }
            break;
        }

        if (isNoMatch)
        {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        // for (int i = 0; i < 26; i++)
        // {
        //     cout << aToz[i] << ' ';
        // }
        // cout << '\n';
        string ans = "";
        for (char i : target)
        {
            if (aToz[i - 'a'] != '0')
            {
                ans += aToz[i - 'a'];
            }
            else
            {
                ans += '?';
            }
        }

        // 3항연산자로 마무리

        bool isImpossible = true;
        for (int i = 0; i < target.length(); i++)
        {
            if (ans[i] != '?')
            {
                isImpossible = false;
                break;
            }
        }
        isImpossible ? cout << "IMPOSSIBLE" : cout << ans;
        cout << '\n';
    }
}