#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("5525.txt", ios_base::in);

    deque<int> q;
    int N, M;
    cin >> N >> M;

    int answer = 0;
    string s;
    cin >> s;
    // 10101 1이 나오면 앞에애들 다 버려야함 절대 안만들어지니까
    for (int index = 0; index < M; index++)
    {
        if (s[index] == 'I')
        {
            if (!q.empty() && q.back() != index - 2)
            {
                q.clear();
            }
            else
            {
                while (!q.empty() && q.front() < index - 2 * N)
                {
                    q.pop_front();
                }
                if (!q.empty() && q.front() == index - 2 * N)
                {
                    answer++;
                }
            }
            q.push_back(index);
        }
    }

    cout << answer;
}