import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')


# 총 개수를 세기

M, N = map(int, input().split())
mass = M * N
from collections import deque
que = deque()
sea = []
for i in range(M):
    lst = list(map(int, input().split()))
    for j in range(len(lst)):
        if lst[j]:
            mass -= 1
            que.append((i, j))
    sea += [lst]
# print(*sea, sep = '\n', end='\n')
# print()
# print(que)

one_dung = True
scount = 0
while one_dung:
    change = []
    for _ in range(len(que)):
        i, j = que.popleft()
        
        tmp = []
        ttmp = sea[i][j] 
        for nwes in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            if 0 <= i + nwes[0] < M and 0 <= j + nwes[1] < N:
                if sea[i + nwes[0]][j + nwes[1]] == 0 and ttmp:
                    ttmp -= 1
                else:
                    tmp.append((i + nwes[0], j + nwes[1]))
        # 흐음 어딨냐 
        
        if ttmp:
            que.append((i, j))
        change.append((i, j, ttmp))
        
    for arg in change:
        x, y, val = arg
        sea[x][y] = val
    
    
    # print(que)
    scount  += 1
    if que:
        new_queue = deque()
        new_queue.append(tuple(que[0]))
        tmp_count = 0
        visited = [[0] * N for _ in range(M)]
        # print(new_queue[0])
        visited[new_queue[0][0]][new_queue[0][1]] = 1
        while new_queue:
  
            tmp_count += 1
            x, y = new_queue.popleft()
            for nwes in ((1, 0), (0, 1), (-1, 0), (0, -1)):
                if 0 <= x + nwes[0] < M and 0 <= y + nwes[1] < N\
                    and not visited[x + nwes[0]][y + nwes[1]]\
                    and sea[x + nwes[0]][y + nwes[1]]:
                    visited[x + nwes[0]][y + nwes[1]] = 1
                    new_queue.append(( x + nwes[0] , y + nwes[1] ))    
        
    else:
        # print(count)
        one_dung = False
        
    if tmp_count < len(que):
        # print(count)
        one_dung = False

        
for i in range(M):
    if sea[i].count(0) != N:
        print(scount)
        break
else:
    print(0)
    
    
    # print(*sea, sep = '\n', end='\n')
    # print()
                
