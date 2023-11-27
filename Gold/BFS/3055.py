
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

# 이름이 나오는지 확인
from collections import deque


R, C = map(int, input().split())

# print(R, C)

dochi_que = deque()
water_set = set()

maps = []
for row in range(R):
    col = list(input())
    for column in range(len(col)):
        if col[column] == "S":
            start = (row, column)
        elif col[column] == "*":
            water_set.add((row, column))
    maps.append(col)

# print(maps, start, water_set)
# 
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def water_flow(level):
    prev_level = map_table.get(level - 1, set())
    pprev = map_table.get(level - 2, set())
    new_set = set()
    for i in prev_level:
        for j in range(4):
            nx = i[0] + dx[j]
            ny = i[1] + dy[j]
            if 0 <= nx < R and 0 <= ny < C and (nx, ny) not in pprev and maps[nx][ny] != 'X' and  maps[nx][ny] != 'D':
                new_set.add((nx, ny))
    return new_set

map_table = {0 : water_set} 

# BFS의 특성상 하나를 줄여버릴 수는 있음

dochi_que.append((start, 0))
while dochi_que:
    new, stage = dochi_que.popleft()
    if stage + 1 not in map_table:
        map_table[stage + 1] = water_flow(stage + 1)
        map_table.pop(stage)
    block = map_table[stage + 1]
    # print(block)
    for j in range(4):
        nx = new[0] + dx[j]
        ny = new[1] + dy[j]
        if 0 <= nx < R and 0 <= ny < C and (nx, ny) not in block:
            if maps[nx][ny] == '.':
                maps[nx][ny] = 'S'
                dochi_que.append(((nx, ny), stage + 1))
            elif maps[nx][ny] == 'D':
                print(stage + 1)
                exit()
else:
    print('KAKTUS')













    
