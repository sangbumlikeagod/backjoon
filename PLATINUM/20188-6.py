import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
import sys
st = sys.stdin.readline
sys.setrecursionlimit(400000)
N = int(st())
dic = [[] for _ in range(N + 1)]

for i in range(N - 1):
    a, b = map(int, st().split())
    dic[a] += [b]
    dic[b] += [a]
    # print(dic)
visited = [0] * (N + 1)
visited[1] = 1
count = 0
def dfs(node): 
    global count
    a = 1
    while dic[node]:
        i = dic[node].pop()
        if not visited[i]:
            visited[i] = 1
            tmp = dfs(i)
            a += tmp 
            count += ((N - 1) * tmp) - (tmp * (tmp - 1)) // 2
    return a
dfs(1)
print(count)