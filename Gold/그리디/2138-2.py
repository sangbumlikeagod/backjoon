import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
import sys
st = sys.stdin.readline
N = int(st())
# current = int(st(), 2)
# target = int(st(), 2)

current = list(st())
target = list(st())
from collections import deque
que = deque()
que.append((current, 0))
visited = {}
visited[current] = 1

def change(integer, i):
    # print(integer, i)
    target[i] = 1 - target[i]
    if i != 0:
        if integer & 1 << (i - 1):
            integer -= 1 << (i - 1)
        else:
            integer += 1 << (i - 1)
    if i != N - 1:
        if integer & 1 << (i + 1):
            integer -= 1 << (i + 1)
        else:
            integer += 1 << (i + 1)
    # print(integer)
    return integer if integer not in visited else False

while que:
    state, round = que.popleft()
    if state == target:
        print(round)
        break
    max_a, max_b = 1, 0
    max_i = [[] for _ in range(4)]

    for i in range(N):
        a, b = 0, 0
        stage = state
        a += 1
        if (stage & 1 << i) != (target & 1 << i):
            b += 1
        if i != 0:
            a += 1
            if (stage & 1 << (i - 1)) != (target & 1 << (i - 1)):
                b += 1

        if i != N - 1:
            a += 1
            if (stage & 1 << (i + 1)) != (target & 1 << (i + 1)):
                b += 1
        if max_b / max_a <= b / a:
            max_a, max_b = a, b
            max_i[max_b].append(i)

    for i in max_i[max_b]:
        tmp = change(state, i)
        if tmp:
            visited[tmp] = 1
            que.append((tmp, round + 1))
else:
    print(-1)
