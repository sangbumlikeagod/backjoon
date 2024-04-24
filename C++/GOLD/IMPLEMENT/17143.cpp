#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;
map<pair<int, int>, tuple<int, int, int>> sharksContainer[2];

int maxR;
int maxC;

tuple<int, int, int> move(pair<int, int> pos, int direction, int speed)
{

    if (direction == 1)
    {
        if (pos.first - speed <= 0)
        {
            speed -= pos.first - 1;
            pos.first = 1;
            direction = 2;
        }
        else
        {
            return {pos.first - speed, pos.second, direction};
        }
    }
    else if (direction == 2)
    {
        if (pos.first + speed > maxR)
        {
            speed -= maxR - pos.first;
            pos.first = maxR;
            direction = 1;
        }
        else
        {
            return {pos.first + speed, pos.second, direction};
        }
    }
    else if (direction == 3)
    {
        if (pos.second + speed > maxC)
        {
            speed -= maxC - pos.second;
            pos.second = maxC;
            direction = 4;
        }
        else
        {
            return {pos.first, pos.second + speed, direction};
        }
    }
    else
    {
        if (pos.second - speed <= 0)
        {
            speed -= pos.second - 1;
            pos.second = 1;
            direction = 3;
        }
        else
        {
            return {pos.first, pos.second - speed, direction};
        }
    }

    if (direction == 1)
    {
        if (speed / (maxR - 1) % 2)
        {
            direction = 2;
            pos.first = 1 + speed % (maxR - 1);
        }
        else
        {
            // 짝 수 일 때
            pos.first = maxR - speed % (maxR - 1);
        }
    }
    else if (direction == 2)
    {
        if (speed / (maxR - 1) % 2)
        {
            direction = 1;
            pos.first = maxR - speed % (maxR - 1);
            // pos.first = 1 + speed % (maxR - 1);
        }
        else
        {
            // 짝 수 일 때
            // pos.first = maxR - speed % (maxR - 1);
            pos.first = 1 + speed % (maxR - 1);
        }
    }
    else if (direction == 3)
    {
        if (speed / (maxC - 1) % 2)
        {
            direction = 4;
            pos.second = maxC - speed % (maxC - 1);
        }
        else
        {
            pos.second = 1 + speed % (maxC - 1);
        }
    }
    else
    {
        if (speed / (maxC - 1) % 2)
        {
            direction = 3;
            pos.second = 1 + speed % (maxC - 1);
        }
        else
        {
            pos.second = maxC - speed % (maxC - 1);
        }
    }

    return {pos.first, pos.second, direction};
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cin.tie(0);
    ifstream cin("17143.txt", ios_base::in);
    int R, C, M;
    cin >> R >> C >> M;
    maxR = R;
    maxC = C;

    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        // sharksContainerOne[{r, c}] = {s, d, z};
        sharksContainer[1][{r, c}] = {s, d, z};
    }
    int King = 0;
    for (int king = 1; king <= C; king++)
    {
        for (int depth = 1; depth <= R; depth++)
        {
            if (sharksContainer[king % 2].find({depth, king}) != sharksContainer[king % 2].end())
            {
                tuple<int, int, int> info = (sharksContainer[king % 2])[{depth, king}];
                // King += get<2>(sharksContainer[king % 2][{king, depth}]);
                cout << get<2>(info) << '\n';
                King += get<2>(info);
                sharksContainer[king % 2].erase({depth, king});
                break;
            }
        }
        // sharksContainer[(king + 1) % 2]
        for (map<pair<int, int>, tuple<int, int, int>>::iterator shark = sharksContainer[king % 2].begin(); shark != sharksContainer[king % 2].end(); shark++)
        {
            pair<int, int> pos = shark->first;
            tuple<int, int, int> info = shark->second;

            tuple<int, int, int> newPos = move(pos, get<1>(info), get<0>(info));
            // cout << get<2>(info) << " 크기의 상어 (" << get<0>(newPos) << ',' << get<1>(newPos) << " ) 로 이동 방향은" << get<2>(newPos) << '\n';
            // 새로운 자리에 추가할건데 이미 있을 경우엔 값만 바꾸도록 ,해야함
            if (sharksContainer[(king + 1) % 2].find({get<0>(newPos), get<1>(newPos)}) == sharksContainer[(king + 1) % 2].end())
            {
                sharksContainer[(king + 1) % 2][{get<0>(newPos), get<1>(newPos)}] = {get<0>(info), get<2>(newPos), get<2>(info)};
            }
            else
            {
                if (get<2>(sharksContainer[(king + 1) % 2][{get<0>(newPos), get<1>(newPos)}]) < get<2>(info))
                {
                    sharksContainer[(king + 1) % 2][{get<0>(newPos), get<1>(newPos)}] = {get<0>(info), get<2>(newPos), get<2>(info)};
                }
            }
        }

        // swap(sharksContainer[king % 2], sharksContainerTwo);
        sharksContainer[king % 2].clear();
    }

    cout << King;
}