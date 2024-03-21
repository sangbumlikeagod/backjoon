#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxVal = 2e9;
int commands[100001][5][5];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2342.txt", ios_base::in);
    // 25, 16, 9,

    // 처음이 00인오류를 막기위해서 1개만 미리 때오자
    for (int i = 0; i < 100001; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                commands[i][j][k] = maxVal;
            }
        }
    }

    int handleException;
    cin >> handleException;
    int index = 0;
    commands[0][0][handleException] = 2;
    commands[0][handleException][0] = 2;

    while (true)
    {
        int command;
        cin >> command;
        if (command == 0)
        {
            break;
        }
        for (int leftFoot = 0; leftFoot < 5; leftFoot++)
        {
            for (int rightFoot = 0; rightFoot < 5; rightFoot++)
            {
                if (commands[index][leftFoot][rightFoot] != maxVal)
                {
                    if (leftFoot == command || rightFoot == command)
                    {
                        commands[index + 1][leftFoot][rightFoot] = min(commands[index + 1][leftFoot][rightFoot], commands[index][leftFoot][rightFoot] + 1);
                    }
                    else
                    {
                        int transitionCostLeft;
                        if (leftFoot == 0)
                        {
                            transitionCostLeft = 2;
                        }
                        else
                        {
                            transitionCostLeft = abs(leftFoot - command) == 2 ? 4 : 3;
                        }

                        commands[index + 1][command][rightFoot] = min(commands[index + 1][command][rightFoot], commands[index][leftFoot][rightFoot] + transitionCostLeft);
                        // cout << commands[index + 1][command][rightFoot] << '\t' << commands[index][leftFoot][rightFoot] << '\t' << transitionCostLeft << '\n';
                        int transitionCosRight;
                        if (rightFoot == 0)
                        {
                            transitionCosRight = 2;
                        }
                        else
                        {
                            transitionCosRight = abs(rightFoot - command) == 2 ? 4 : 3;
                        }

                        commands[index + 1][leftFoot][command] = min(commands[index + 1][leftFoot][command], commands[index][leftFoot][rightFoot] + transitionCosRight);
                        // cout << commands[index + 1][leftFoot][command] << '\t';
                    }
                }
            }
        }

        // 새로 받는 커맨드가 예를들어서 1이다 그러면 5로나눈 나머지가 1인놈들은
        index++;
        // cout << '\n';
    }
    int ans = maxVal;

    for (int left = 0; left < 5; left++)
    {
        for (int right = 0; right < 5; right++)
        {
            ans = min(ans, commands[index][left][right]);
        }
    }
    cout << ans;
}