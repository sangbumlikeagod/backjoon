import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
N, M = map(int, input().split())

dic = {}
for i in range(M):
    s, t = map(int, input().split())
    dic[s] = dic.get(s, set()) | {t}
    dic[t] = dic.get(t, set()) | {s}

minn = (0, 10000000)
from collections import deque
heq = deque()
for i in range(1, N + 1):
    visited = [0] * (N + 1)
    heq.append((i, 0))
    lct = 0
    visited[i] = 1
    while heq:
        next, val = heq.popleft()
        lct += val
        for j in dic[next]:
            if not visited[j]:
                visited[j] = 1
                heq.append((j, val + 1))

    if lct < minn[1]:
        minn = (i, lct)
print(minn[0])
