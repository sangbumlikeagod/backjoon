import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
import sys
st = sys.stdin.readline

N = int(st())
aquarium = []
for i in range(N):
    tmp = list(map(int,st().split()))
    for j in range(N):
        if tmp[j] == 9:
            start = (i, j)
    aquarium += [tmp]

# print(aquarium, start)

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

from collections import deque



def bfs(cord):
    limit = N ** 2
    minn = (N, N)
    while que:
        # print(que)
        (x, y), dis = que.popleft()
        if dis > limit:
            return (minn, limit)
        if aquarium[x][y] and aquarium[x][y] < size_shark:
            if minn[0] > x:
                minn = (x, y)
            elif minn[0] == x and minn[1] > y:
                minn = (x, y)
            limit = dis
            continue
            # return ((x, y), dis)
        for _ in range(4):
            nx, ny = x + dx[_], y + dy[_]
            if 0 <= nx < N and 0 <= ny < N \
                and not visited[nx][ny] \
                and aquarium[nx][ny] <= size_shark:
                visited[nx][ny] = 1
                que.append(((nx, ny), dis + 1))
                
    if minn[0] < N:
        return (minn, limit)
    return (0, 0)

call_mom = True
ans = 0

size_shark = 2
ct = 2
# print(*aquarium, sep='\n')
# print(ans, size_shark)

while call_mom:
    que = deque()
    que.append((start, 0))
    visited = [[0] * N for _ in range(N)]
    visited[start[0]][start[1]] = 1
    tmp, dis = bfs(start)
    # print(tmp)
    if tmp:
        aquarium[start[0]][start[1]], aquarium[tmp[0]][tmp[1]] = 0, aquarium[start[0]][start[1]]
        start = tmp
        ans += dis
        ct -= 1
        if not ct:
            size_shark += 1
            ct = size_shark
    else:
        call_mom = False
    # print(*aquarium, sep='\n')
    # print(ans, size_shark)
print(ans)

