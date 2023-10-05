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
        heapq.heappush(que, (abs(x), x > 0))
    else:
        if que:
            tp, ab = heapq.heappop(que)
            if ab:
                print(tp)
            else:
                print(-tp)
        else:
            print(0)
