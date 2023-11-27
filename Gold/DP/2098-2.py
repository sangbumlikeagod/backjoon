import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
sys.setrecursionlimit(10000)

N = int(sys.stdin.readline())

NbyN = [[0] * N for _ in range(N)]
for i in range(N):
    local = list(map(int, sys.stdin.readline().split()))
    for j in range(N):
        NbyN[i][j] = local[j]


import heapq


def search(num, psum, bit):
    print(num, end=' ')
    global min_val
    if bit == 2 ** N - 1 and NbyN[num][start]:
        if psum + NbyN[num][start] < min_val:
            min_val = psum + NbyN[num][start]
        return 
    if psum >= min_val:
        return
    heap = []
    
    for idx, val in enumerate(NbyN[num]):
        if val and not bit & 1 << idx:
            heapq.heappush(heap, (val, idx))
            
    while heap:
        s, nnum = heapq.heappop(heap)
        search(nnum, psum + NbyN[num][nnum] ,bit + (1 << nnum))

    return

# 이러면 결국 다봐야함 결국 다익스트라적인 요소를 가져가야함 


min_val =  2 ** 31 - 1

for start in range(N):
    search(start, 0 ,1 << start)

print(min_val)
        