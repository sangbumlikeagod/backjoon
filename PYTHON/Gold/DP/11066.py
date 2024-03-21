import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
N = int(st())
import heapq

for i in range(N):
    K = int(st())
    hq = list(map(int, st().split()))
    hq.sort(reverse= True)
    total = 0
    while len(hq) != 1:
        f = hq.pop() + hq.pop()
        hq.append(f)
        hq.sort(reverse= True)
        total += f
        print(hq, total)
    print(total)
    
    