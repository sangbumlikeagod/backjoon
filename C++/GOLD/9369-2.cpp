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

    for (int t = 0; t < tc; t++)
    {
        container.resize(100, "");
        char aToz[26];
        char aTozBottom[26];
        char temp[26];
        char tempAtozBottom[26];

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> container[i];
        }
        string hint, target;
        cin >> hint >> target;
        memset(aToz, '0', 26 * sizeof(char));
        memset(aTozBottom, '0', 26 * sizeof(char));

        bool isNoMatch = true;
        for (int i = 0; i < N; i++)
        {
            memset(temp, '0', 26 * sizeof(char));
            memset(tempAtozBottom, '0', 26 * sizeof(char));

            if (container[i].length() != hint.length())
                continue;

            for (int j = 0; j < hint.length(); j++)
            {
                char a = container[i][j];
                char b = hint[j];

                if ((temp[a - 'a'] != '0' && temp[a - 'a'] != b) || (tempAtozBottom[b - 'a'] != '0' && tempAtozBottom[b - 'a'] != a))
                {
                    break;
                }
                else
                {
                    temp[a - 'a'] = b;
                    tempAtozBottom[b - 'a'] = a;
                }

                // 밑에 매칭이 안되는게 똑같이 일어날 수 있고 새로추가된 애는 반영이 되겠지만 첫번째애는 반영이 안될것. 그것도 판단을 해줬어야함
                if (j == hint.length() - 1)
                {
                    if (isNoMatch)
                    {
                        for (int pk = 0; pk < 26; pk++)
                        {
                            aToz[pk] = temp[pk];
                            aTozBottom[pk] = tempAtozBottom[pk];
                        }
                    }
                    else
                    {
                        for (int l = 0; l < 26; l++)
                        {
                            if (aToz[l] != temp[l] || aTozBottom[aToz[l] - 'a'] != tempAtozBottom[temp[l] - 'a'])
                            {
                                char tmp1 = aToz[l];
                                char tmp2 = temp[l];
                                aToz[l] = '?';
                                aTozBottom[tmp1 - 'a'] = '?';
                                if (tmp2 != '0')
                                {
                                    aToz[tmp2 - 'a'] = '?';
                                    aTozBottom[tmp2 - 'a'] = '?';
                                }
                            }
                        }
                    }

                    // 그냥 따로하는게 낫겠다 여기선
                    // 둘다 같아야만해 아니면 전부 다 a로 해석될 수도 있고 b로도 해석될 수 있는 건데  뭐가 맞는건지 모르기 때문에
                    // 지금 상황에서 b로 해석되고 있는 놈도 ?가 돼야함 둘 다 같은 확률이기 때문에

                    isNoMatch = false;
                }
            }
        }

        string ans = "";
        for (char p : target)
        {
            if (aToz[p - 'a'] != '0')
            {
                ans += aToz[p - 'a'];
            }
            else
            {
                ans += '?';
            }
        }

        bool isImpossible = true;
        for (int q = 0; q < target.length(); q++)
        {
            if (ans[q] != '?')
            {
                isImpossible = false;
                break;
            }
        }
        isImpossible ? cout << "IMPOSSIBLE" : cout << ans;
        cout << '\n';
    }
}
