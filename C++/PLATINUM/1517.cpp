#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int inputList[500001]{0};
int sortedInputList[500001]{0};

int N;
long long ans = 0;

long long devideAndConquer(int start, int end)
{
    // cout << start << '\t' << end << '\n';
    if (end - start == 1)
    {
        return 0;
    }
    if (end - start == 2)
    {
        if (inputList[end - 1] < inputList[start])
        {
            swap(inputList[end - 1], inputList[start]);
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int ans = 0;
    int mid = (start + end) / 2;
    ans += devideAndConquer(start, mid);
    ans += devideAndConquer(mid, end);
    vector<int> left;
    vector<int> right;
    for (int leftArg = start; leftArg < mid; leftArg++)
    {
        left.push_back(inputList[leftArg]);
    }
    for (int rightArg = mid; rightArg < end; rightArg++)
    {
        right.push_back(inputList[rightArg]);
    }
    int leftMaxIndex = mid - start;
    int rightMaxIndex = end - mid;
    int leftStartIndex = 0;
    int rightStratIndex = 0;

    int maxTotalIndex = end - start;
    int totalIndex = 0;

    int byItsOwn = 0;

    while (totalIndex < maxTotalIndex)
    {
        int next = 0;
        if (leftStartIndex == leftMaxIndex)
        {
            byItsOwn += abs(rightStratIndex + leftMaxIndex - totalIndex);
            inputList[start + totalIndex] = right[rightStratIndex];
            totalIndex++;
            // cout << right[rightStratIndex] << ' ';
            rightStratIndex++;
        }
        else if (rightStratIndex == rightMaxIndex)
        {
            inputList[start + totalIndex] = left[leftStartIndex];
            byItsOwn += abs(totalIndex - leftStartIndex);
            // cout << left[leftStartIndex] << ' ';

            totalIndex++;
            leftStartIndex++;
        }
        else
        {
            if (left[leftStartIndex] <= right[rightStratIndex])
            {
                inputList[start + totalIndex] = left[leftStartIndex];

                byItsOwn += abs(totalIndex - leftStartIndex);
                // cout << left[leftStartIndex] << ' ';

                totalIndex++;
                leftStartIndex++;
            }
            else
            {
                byItsOwn += abs(rightStratIndex + leftMaxIndex - totalIndex);
                inputList[start + totalIndex] = right[rightStratIndex];
                // cout << right[rightStratIndex] << ' ';

                totalIndex++;
                rightStratIndex++;
            }
            // else
            // {
            //     if (abs(rightStratIndex + leftMaxIndex - totalIndex) < abs(leftStartIndex - totalIndex))
            //     {
            //         byItsOwn += abs(rightStratIndex + leftMaxIndex - totalIndex);
            //         inputList[start + totalIndex] = right[rightStratIndex];
            //         totalIndex++;
            //         rightStratIndex++;
            //     }
            //     else
            //     {
            //         byItsOwn += abs(totalIndex - leftStartIndex);
            //         totalIndex++;
            //         leftStartIndex++;
            //     }
            // }
        }
    }
    // cout << '\n';
    return ans + byItsOwn / 2;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("1517.txt", ios_base::in);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int inpVal;
        cin >> inpVal;
        inputList[i] = inpVal;
        sortedInputList[i] = inpVal;
    }
    cout << devideAndConquer(0, N);
}