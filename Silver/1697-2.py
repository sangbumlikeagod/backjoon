import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
sys.setrecursionlimit(100000)



N, K = map(int, sys.stdin.readline().split())
# print(N, K)


if K <= N:
    print(N - K)
else:
    # 17 16 8 4 5
    # 
    from collections import deque
    que = deque()
    que.append((N, 0))
    visited = [0] * (K + 1)
    
    value = 10000000000
    while que:
        next, count = que.popleft()
        if next == K:
            if value >  
        for i in [next * 2, next + 1, next - 1]:
            if N <= i <= K and not visited[i]:
                visited[i] = 1
                que.append((i, count + 1))


# 언제 멈춰 