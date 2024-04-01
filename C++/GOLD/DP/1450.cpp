#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

map<long long, int> leftThis;
map<long long, int> leftNext;
map<long long, int> rightThis;
map<long long, int> rightNext;

vector<long long> rightForindex;
vector<int> rightPrefixSum;
// vector<int> leftThis;
// vector<int> leftNext;
// vector<int> rightThis;
// vector<int> rightNext;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1450.txt", ios_base::in);
    int N, C;
    cin >> N >> C;
    // 예를들어서 upperbound로 찾아 개수 모르잖아 끝까지의
    leftThis[0] = 1;
    for (int ithNode = 0; ithNode < N / 2; ithNode++)
    {
        int inp;
        cin >> inp;
        for (map<long long, int>::iterator i = leftThis.begin(); i != leftThis.end(); i++)
        {
            leftNext[i->first + inp] += i->second;
            leftNext[i->first] += i->second;
        }
        leftThis.clear();
        swap(leftNext, leftThis);
    }
    rightThis[0] = 1;
    for (int jthNode = 0; jthNode < N - N / 2; jthNode++)
    {
        int inp;
        cin >> inp;
        for (map<long long, int>::iterator i = rightThis.begin(); i != rightThis.end(); i++)
        {
            rightNext[i->first + inp] += i->second;
            rightNext[i->first] += i->second;
        }
        rightThis.clear();
        swap(rightNext, rightThis);
    }
    // right에 대해서만 모두 인덱스 접근 할 수 있는 Vector에 추가하고 누적합 개념으로 다른애들도 추가
    int index = 0;
    for (map<long long, int>::iterator i = rightThis.begin(); i != rightThis.end(); i++)
    {
        rightForindex.push_back(i->first);
        int sumOfBeforeNode = index == 0 ? 0 : rightPrefixSum[index - 1];
        rightPrefixSum.push_back(i->second + sumOfBeforeNode);
        index++;
    }

    // cout << "일단 저장 완료" << '\n';
    int ans = 0;
    for (map<long long, int>::iterator i = leftThis.begin(); i != leftThis.end(); i++)
    {
        long long limitsForRight = C - i->first;
        // cout << "이게 상대방의 최대 " << limitsForRight << '\n';
        if (limitsForRight < 0)
            continue;

        int start = 0;
        int end = index;
        while (start < end)
        {
            int mid = (start + end) / 2;
            // cout << mid << '\n';
            //  << '\n';
            if (rightForindex[mid] <= limitsForRight)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        // cout << rightForindex[end - 1] << '\t';
        // cout << rightPrefixSum[end - 1] << '\n';
        ans += rightPrefixSum[end - 1] * i->second;
    }
    cout << ans;
}