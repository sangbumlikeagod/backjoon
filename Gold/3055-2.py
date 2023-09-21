
import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')

import sys
# 이름이 나오는지 확인
from collections import deque


R, C = map(int, input().split())

dochi_que = deque()
water = []
maps = []
for row in range(R):
    col = list(input())
    for column in range(len(col)):
        if col[column] == "S":
            start = (row, column)
        elif col[column] == "*":
            water.append((row, column))
    maps.append(col)


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
state = 0


dochi_que.append((start, 0))
while dochi_que:
    print(dochi_que)
    new, stage = dochi_que.popleft()
    if stage >= state:
        lst = []
        for wa in water:
            for j in range(4):
                nx = wa[0] + dx[j]
                ny = wa[1] + dy[j]
                if 0 <= nx < R and 0 <= ny < C and maps[nx][ny] != 'X' and  maps[nx][ny] != 'D':
                    maps[nx][ny] = '*'
                    lst.append((nx, ny))
        water = lst
        state += 1
    print(*maps, sep='\n')
    print()
    for j in range(4):
        nx = new[0] + dx[j]
        ny = new[1] + dy[j]
        if 0 <= nx < R and 0 <= ny < C and maps[nx][ny] != '*' and maps[nx][ny] != 'X'  and maps[nx][ny] != 'S':
            if maps[nx][ny] == '.':
                maps[nx][ny] = 'S'
                dochi_que.append(((nx, ny), stage + 1))

            elif maps[nx][ny] == 'D':
                print(stage + 1)
                exit()
else:
    print('KAKTUS')













    
