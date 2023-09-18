import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
N = int(sys.stdin.readline())

data = [list(map(int, sys.stdin.readline().split())) for i in range(N)]

now = sys.stdin.readline()
desire = int(sys.stdin.readline())
overlap = [0] * (2 ** N)
# print(overlap)

startlst = []
startline = 0
for i in range(N):
    if now[i] == 'Y':
        startlst.append(i)
        startline += 1 << i


# print(startline, startlst) 
if not startlst:
    print(-1)
    exit()

from heapq import heappush, heappop
minimi = float('inf')

def search(now):
    if overlap[now]:
        return overlap[now]
    ct = 0
    now_l = []
    to_go = []
    for i in range(N):
        if (1 << i) & now:
            ct += 1
            now_l.append(i)
        else:
            to_go.append(i)
    if ct >= desire:
        return 0
    lst = []
    for i in now_l:
        for j in to_go:
            heappush(lst, search(now + (1 << j)) + data[i][j])
    overlap[now] = heappop(lst)            
    return overlap[now]

print(search(startline))
# print(*overlap, sep="\n")
# print()
print(overlap)




'''
2 ** i
에서 시작을해 
+ 가 아닌애에 대해서만 
시작점을 

'''
# 종료조건은 N ** desire 이랑 N ** desire - 1 사이에 들어갈 