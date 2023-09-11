import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')


# 총 개수를 세기

M, N = map(int, input().split())
mass = M * N
from collections import deque
que = deque()
lst = []
for i in range(M):
    lst = list(map(int, input().split()))
    for j in lst:
        if j:
            mass -= 1
            que.append((i, j))

print(que)

one_dung = True

while one_dung:
    for _ in range(len(que)):
        i, j = que.popleft()
        tmp = []
        for nwes in ((1, 0), (0, 1), (-1, 0), (0, -1)):
            if i + nwes[0]
