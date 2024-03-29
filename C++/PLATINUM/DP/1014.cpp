#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ifstream cin("1014.txt", ios_base::in);

    int tc;
    cin >> tc;

    for (int testcase = 0; testcase < tc; testcase++)
    {
        int x, y;
        cin >> x >> y;

        int shouldNot[10][10] = {0};
        int Dp[11][1024] = {0};

        for (int xV = x - 1; xV >= 0; xV--)
        {
            string s;
            cin >> s;
            // 거꾸로 저장함
            for (int yV = 0; yV < y; yV++)
            {
                shouldNot[xV][yV] = 0;
                if (s[yV] == 'x')
                {
                    shouldNot[xV][yV] = 1;
                }
            }
        }

        // cout << "저장 완료" << '\n';

        for (int xV = 0; xV < x; xV++)
        {
            for (int chance = 0; chance < (1 << y); chance++)
            {
                int yPointer = 0;
                int yPointerOndigit = 1;
                bool isProper = true;
                int totalSeat = 0;
                int nextLineShouldNotSeatHere = 0;
                // cout << '\n' << '\n' << "***********************************" << '\n' << chance  << '\n';

                while (yPointer < y)
                {

                    // int rightNow = 1 << yPointer;
                    // cout << yPointer <<  yPointerOndigit << '\t' << (chance & yPointerOndigit) << '\n';

                    if ((chance & yPointerOndigit) == yPointerOndigit)
                    {
                        if (shouldNot[xV][yPointer])
                        {
                            // cout << "걸린다" << '\n';
                            isProper = false;
                            break;
                        }
                        totalSeat++;
                        if (yPointer != 0)
                        {
                            int rightBefore = yPointerOndigit >> 1;
                            // cout << nextLineShouldNotSeatHere << '\t'  << rightBefore  << '\t' << chance << '\n';
                            nextLineShouldNotSeatHere |= rightBefore;
                            // cout << '\t' << nextLineShouldNotSeatHere << '\t'  << rightBefore << '\n';
                            if (chance & rightBefore)
                            {
                                // cout << "안됨" << '\n';
                                isProper = false;
                                break;
                            }
                        }
                        if (yPointer != y - 1)
                        {
                            nextLineShouldNotSeatHere |= yPointerOndigit << 1;
                        }
                    }
                    yPointer++;
                    yPointerOndigit = yPointerOndigit << 1;
                }
                if (isProper == false)
                {
                    continue;
                }
                // cout << xV << '\t' << yPointer << '\t' << totalSeat << '\t' << chance << '\n';
                // cout << nextLineShouldNotSeatHere << '\n';
                for (int caseForNext = 0; caseForNext < 1024; caseForNext++)
                {
                    if ((caseForNext & nextLineShouldNotSeatHere) == 0)
                    {
                        Dp[xV + 1][caseForNext] = max(Dp[xV + 1][caseForNext], Dp[xV][chance] + totalSeat);
                    }
                }
            }
        }

        int maxVal = 0;
        for (int totalNthCase = 0; totalNthCase < 1024; totalNthCase++)
        {
            maxVal = max(Dp[x][totalNthCase], maxVal);
        }
        cout << maxVal << '\n';
        // break;
    }
}