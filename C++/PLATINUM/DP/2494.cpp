#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int dp[10001][21] = {0};
pair<int, int> parentTrait[10001][21];
int main()
{

    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("2494.txt", ios_base::in);
    int N;
    cin >> N;
    string sTarget;
    string sCurrent;
    cin >> sCurrent >> sTarget;

    for (int index = 0; index <= N; index++)
    {
        for (int leftIndex = 0; leftIndex < 21; leftIndex++)
        {
            dp[index][leftIndex] = 100000;
        }
    }

    // int target = sTarget[0] - '0';
    // int current = sCurrent[0] - '0';
    // int leftMove = target - current >= 0 ? target - current : target - current + 10;
    // int rightMove = current - target >= 0 ? current - target : current - target + 10;

    // cout << leftMove << '\t' << rightMove << '\n';
    // dp[1][0] = current - target >= 0 ? current - target : current - target + 10;
    // dp[1][leftMove] = leftMove;

    dp[0][0] = 0;
    for (int index = 0; index < N; index++)
    {
        int target = sTarget[index] - '0';
        for (int leftIndex = 0; leftIndex < 10; leftIndex++)
        {
            if (dp[index][leftIndex] == 100000)
            {
                continue;
            }

            // leftIndex 가 11부터 20까지로 됐으니

            int current = ((sCurrent[index] - '0') + leftIndex) % 10;
            // 현재 내 위치

            // 현재 내위치에서 오른쪽으로 이동해야하는 거리 9가 1칸이어야한다.
            int args = (current - target >= 0 ? current - target : current - target + 10);
            // dp[index + 1][leftIndex] = min(dp[index][leftIndex] + args, dp[index + 1][leftIndex]);
            if (dp[index][leftIndex] + args < dp[index + 1][leftIndex])
            {
                dp[index + 1][leftIndex] = dp[index][leftIndex] + args;
                // 현재 내 인덱스에서 오른쪽으로 이만큼 이동했다인데 -를 붙이자
                parentTrait[index + 1][leftIndex] = {leftIndex, args * -1};
            }
            // 아니 생각해보니 다시 주어담는건 dp값이 왼쪽으로 몇번 이동했냐는 거잖아
            // 다음 dp 값에 영향을 주려했는데 정작 자기가 몇번 왼쪽으로 갔는지는 자기가 알아야함.
            // 0인덱스에서 min에 영향을 주었다면 오른쪽으로 이동했을 경우 같은 장소에 영향을 줬을 것이고 왼쪽으로 이동했을 경우 그만큼 왼쪽으로 이동해서 줬을 것이다. 목표지점까지의 이동만 더했을 뿐이다
            // 그니까 현재 내 장소에서난 왼쪽 또는 오른쪽으로 움직일건데 그건 지금 내칸에는 반영되어있지 않고 따라서 시작위치가 어디였고 왼쪽또는 오른쪽으로 몇칸 움직였는지를 저장해두어야함
            int leftMove = target - current >= 0 ? target - current : target - current + 10;
            if (dp[index][leftIndex] + leftMove < dp[index + 1][(leftIndex + leftMove) % 10])
            {
                dp[index + 1][(leftIndex + leftMove) % 10] = dp[index][leftIndex] + leftMove;
                parentTrait[index + 1][(leftIndex + leftMove) % 10] = {leftIndex, leftMove};
            }
            // dp[index + 1][(leftIndex + leftMove) % 10] = min(dp[index][leftIndex] + leftMove, dp[index + 1][(leftIndex + leftMove) % 10]);
        }
    }
    int ans = 100000;
    pair<int, int> lastTrait;

    for (int leftIndex = 0; leftIndex < 10; leftIndex++)
    {
        // cout << dp[N][leftIndex] << '\t';
        if (dp[N][leftIndex] < ans)
        {
            ans = dp[N][leftIndex];
            lastTrait = parentTrait[N][leftIndex];
        }
        // ans = min(ans, dp[N][leftIndex]);
    }

    vector<int> stack{};
    cout << ans << '\n';
    for (int index = 1; index <= N; index++)
    {
        stack.push_back(lastTrait.second);
        lastTrait = parentTrait[N - index][lastTrait.first];
    }

    for (int index = 1; index <= N; index++)
    {
        cout << index << ' ' << stack[stack.size() - 1] << '\n';
        stack.pop_back();
    }
}