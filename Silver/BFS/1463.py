import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
from collections import deque
st = sys.stdin.readline

N = int(st())


visited = {}

que = deque()

que.append((N, 0))

while que:
    n, stage = que.popleft()
    if n == 1:
        print(stage)
        break
    if not n % 3:
        que.append((n // 3, stage + 1))
    if not n % 2:
        que.append((n // 2, stage + 1 ))
    que.append((n - 1, stage + 1))

