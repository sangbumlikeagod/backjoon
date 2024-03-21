import sys


name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r')
sys.stdin = file
import sys
N = int(sys.stdin.readline())
import heapq
que = []
for i in range(N):
    x = int(sys.stdin.readline())
    if x:
        heapq.heappush(que, -x)
    else:
        if que:
            tp = heapq.heappop(que)
            print(-tp)
        else:
            print(0)

