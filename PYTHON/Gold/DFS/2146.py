import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

import sys
sys.setrecursionlimit(100000)
from collections import deque
N = int(input())

#서로 다른땅을 구별하는데 까지 구현

land = [list(map(int, input().split())) for _ in range(N)]
# print(land)

# 시작지점을 발견하면 dfs를 하고 외곽선을 발견해
land_num = 1

que = deque()
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
def dfs(cord):
    is_appended = False
    for delta in range(4):
        nx, ny = cord[0] + dx[delta], cord[1] + dy[delta]
        if 0 <= nx < N and 0 <= ny < N:
            if land[nx][ny] and not visited[nx][ny]:
                visited[nx][ny] = land_num
                dfs((nx, ny))
            elif not land[nx][ny] and not is_appended:
                is_appended = True
                que.append((cord, land_num, 0))
            

visited = [[0] * N for _ in range(N)]
for row in range(N):
    for col in range(N):
        if land[row][col] and not visited[row][col]:
            visited[row][col] = land_num
            dfs((row, col))
            land_num += 1


# print(*visited, sep='\n')
# print(que)

def bfs():
    while que:
        (n_x, n_y), land_num, state = que.popleft()
        for delta in range(4):
            nx, ny = n_x + dx[delta], n_y + dy[delta]
            if 0 <= nx < N and 0 <= ny < N:
                if not visited[nx][ny]:
                    visited[nx][ny] = (land_num, state + 1)
                    que.append(((nx, ny), land_num, state + 1))
                elif type(visited[nx][ny]) != int and  visited[nx][ny][0] != land_num:
                    # if visited[nx][ny][0] != land_num:
                    return state + visited[nx][ny][1]

print(bfs())
