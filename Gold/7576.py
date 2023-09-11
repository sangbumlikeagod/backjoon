import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

M, N = map(int, sys.stdin.readline().split())
count = M * N
from collections import deque

lst = []
que = deque()
for i in range(N):
    tmp = list(map(int, sys.stdin.readline().split()))
    for j in range(len(tmp)):
        if tmp[j] == 1:
            count -= 1
            que.append((i, j, 0))
        elif tmp[j] == -1:
            count -= 1
    lst += [tmp]


ct = 0
        
while que and count > 0:
    nextx, nexty, ct = que.popleft()
    
    for i in [[-1, 0], [1, 0], [0, 1], [0, -1]]:
        
        if 0 <= nextx + i[0] < N and 0 <= nexty + i[1] < M and\
                lst[nextx + i[0]][nexty + i[1]] == 0:
            count -= 1
            lst[nextx + i[0]][nexty + i[1]] = 1
            que.append((nextx + i[0], nexty + i[1], ct + 1))
if count:
    print(-1)
elif que:
    while que:
        nextx, nexty, ct = que.popleft()
    print(ct)
            
    
    
