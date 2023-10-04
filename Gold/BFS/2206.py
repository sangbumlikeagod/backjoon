import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
N, M = map(int, st().split())

kwang = []
for i in range(N):
    kwang.append(list(st().strip()))
    
# print(kwang)
visited = [[-1] * M for _ in range(N)]
visited[0][0] = 1
from collections import deque

que = deque()
que.append(((0, 0), 1, 1))

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

while que:
    # print(que)
    (x, y), left_power, stage = que.popleft()
    if x == N  - 1 and y == M - 1:
        print(stage)
        break
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < N and 0 <= ny < M and visited[nx][ny] < left_power:
            if kwang[nx][ny] == '1':
                if not left_power:
                    continue
                else:
                    visited[nx][ny] = left_power
                    que.append(((nx, ny), 0, stage + 1))
            else:
                visited[nx][ny] = left_power
                que.append(((nx, ny), left_power, stage + 1))
else:
    print(-1)

