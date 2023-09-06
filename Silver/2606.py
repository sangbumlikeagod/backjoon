import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(10000)
st = sys.stdin.readline
C = int(st())
N = int(st())

dic = {}
for i in range(N):
    a, b = map(int, st().split())
    dic[a] = dic.get(a, []) + [b]
    dic[b] = dic.get(b, []) + [a]
    


visited = [0] * (C + 1)
def dfs(num):
    visited[num] = 1
    # print(visited)
    if num not in dic:
        return 1
    val = 0
    
    for i in dic[num]:
        if not visited[i]:
            val += dfs(i)
            
    return val + 1
print(dfs(1) - 1)
    