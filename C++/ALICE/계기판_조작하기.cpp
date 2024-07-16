#include <iostream>

using namespace std;

int check(int value)
{
    int array[10] = {0};
    int answer = 0;
    int digit = 1;
    while (digit <= value)
    {
        array[(value % (digit * 10)) / digit]++;
        digit *= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        if (array[i])
        {
            answer++;
        }
    }
    return answer;
}

int main()
{
    int N, K;
    cin >> N >> K;
    if (K == 8)
    {
        cout << "10234567";
        return 0;
    }
    else if (K == 9)
    {
        cout << "102345678";
        return 0;
    }
    else if (K == 10)
    {
        cout << "1023456789";
        return 0;
    }
    N++;
    while (true)
    {
        if (check(N) == K)
        {
            cout << N;
            return 0;
        }
        else
        {
            N++;
        }
    }
}
