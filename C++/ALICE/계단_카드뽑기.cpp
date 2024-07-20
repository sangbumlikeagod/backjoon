#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

multiset<int> container = {};
int cardArray[50001] = {0};

int findSmallorEqual(int num)
{
    auto it = container.upper_bound(num);
    return distance(it, container.end()) + container.count(num);
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cardArray[i];
    }
    int answer = 0;
    int left = 0;
    int right = 0;
    while (right < N)
    {
        int next = right - left + 1;
        int nextInput = cardArray[right];
        if (nextInput < next)
        {
            int smallOrEqualInput = next - 1 - findSmallorEqual(nextInput);
            // cout << nextInput << '\t' << next << '\t' << smallOrEqualInput << '\n';
            bool haveToDelete = smallOrEqualInput >= nextInput;
            if (haveToDelete)
            {
                while (cardArray[left] > nextInput)
                {
                    container.erase(cardArray[left]);
                    left++;
                }
                container.erase(cardArray[left]);
                left++;
            }
        }
        right++;
        container.insert(nextInput);
        answer = max(answer, right - left);
        // cout << right << ' ' << left << '\n';
    }

    cout << answer;
}
