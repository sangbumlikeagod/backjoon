import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
N = int(st())
current = int(st(), 2)
target = int(st(), 2)
# print(current, target)

from collections import deque
que = deque()
que.append((current, 0))
visited = {}
visited[current] = 1
while que:
    # print(que)
    state, round = que.popleft()
    if state == target:
        print(round)
        break
    for i in range(N):
        # if target & (1 << i) != state & (1 << i):
        stage = state
        if stage & 1 << i:
            stage -= 1 << i
        else:
            stage += 1 << i
        if i != 0:
            if stage & 1 << (i - 1):
                stage -= 1 << (i - 1)
            else:
                stage += 1 << (i - 1)
        if i != N - 1:
            if stage & 1 << (i + 1):
                stage -= 1 << (i + 1)
            else:
                stage += 1 << (i + 1)
        if stage not in visited:
            visited[stage] = 1
            que.append((stage, round + 1))
        
