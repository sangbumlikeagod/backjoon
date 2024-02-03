#include <iostream>
#include <fstream>
#include <cstring>
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
        char aTozBottom[26];
        char aToz2[26];
        char tmp[26];

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> container[i];
        }
        string hint, target;
        cin >> hint >> target;
        memset(aToz, '0', 26);
        memset(aTozBottom, '0', 26);

        // 위쪽 변환문과 아래쪽 변환문을 둘다 고려해서 해줘야함
        // 언급이 안되는 애와 중복으로 되는애들은 고려를 해줘야함
        bool isNoMatch = true;
        for (int i = 0; i < N; i++)
        {
            // 같은 문자 자리에 두번이 박히는지도 알아야하고
            // 대표되는 문자가 두번 박히는지도 알아야함

            memset(tmp, '0', 26);
            memset(aToz2, '0', 26);

            // 두 서로 다른 문자가 같은 해석이 되는가에 대한 경우
            bool isNonoverlap = true;
            if (container[i].length() != hint.length())
                continue;

            for (int j = 0; j < hint.length(); j++)
            {

                char a = container[i][j];
                char b = hint[j];
                // 3개중에 하나로 해야한다?
                // container에 저장된 각 문자들이 hint 문자로 변환됨
                // 비어있지않고 그 값이 지금 저장하려는 값도 아닐때
                if ((tmp[a - 'a'] != '0' && tmp[a - 'a'] != b) || (aToz2[b - 'a'] != '0' && aToz2[b - 'a'] != a))
                {
                    isNonoverlap = false;
                    break;
                }
                else
                {
                    tmp[a - 'a'] = b;
                    aToz2[b - 'a'] = a;
                }

                // 여기까지 왔다면 2개 이상의 암호문자가 한 대상으로 바뀌거나 한 문자가 두개 이상의 문자로 해석되는 경우는 모두 피했음
                if (j == hint.length() - 1)
                {

                    // for (int k = 0; k < hint.length(); k++)
                    // {
                    //     /* 이제부터 암호문의 문자들이 어떤 문자로 저장될지만 판단 */
                    //     char a = container[i][k];
                    //     // 이미 저장된적이 있다면 해야하는 행동과 아닐경우의 행동이 다름
                    //     // 아니지 두개 이상일 경우에는 둘이 동시가 아닐 경우엔 전부 쳐내야하고 한개일 경우에는 한개만 하면 됨
                    //     // 그러면 일단 한개일때는 전부 해놓자? 그리고 두개 이상인게 nomatch로 확인됐을 떄는 아닌애 까지 싹다 바꾸기
                    //     if (isNoMatch)
                    //     {
                    //         aToz[a - 'a'] =
                    //     }
                    // }

                    for (int i = 0; i < 26; i++)
                    {

                        if (aToz[i] == '0')
                        {
                            // 아직 안됐으면
                            if (isNoMatch)
                            {
                                aToz[i] = tmp[i];
                            }
                            else
                            {
                                // 이미 한번 다녀갔는데 0이다 ? 뒤에 애들이 있던 말던 여기는 이제 해석 불가임
                                aToz[i] = '?';
                            }
                        }
                        else if (aToz[i] != tmp[i])
                        {
                            aToz[i] = '?';
                        }

                        // 해석된 문자들이 어떤 암호문자를 대표하고 있는지 확인하는 일
                        // if (aTozBottom[i] == '0' || aTozBottom[i] == aToz2[i])
                        // {
                        //     aTozBottom[i] = aToz2[i];
                        // }
                        // else
                        // {
                        //     aTozBottom[i] = '?';
                        // }
                    }
                    isNoMatch = false;
                }
            }
            if (!isNonoverlap)
            {
                continue;
            }
        }

        if (isNoMatch)
        {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }

        string ans = "";
        for (char i : target)
        {
            // if (aToz[i - 'a'] != '0' && aTozBottom[aToz[i - 'a'] - 'a'] != '?')
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