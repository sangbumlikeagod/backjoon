import sys

sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
st = sys.stdin.readline

N = int(st())
dic = [[] for _ in range(N + 1)]

for i in range(N - 1):
    a, b = map(int, st().split())
    dic[a] += [b]
    dic[b] += [a]

dic[1] += [0]
visited = [0] * (N + 1)
visited[0] = 1
visited[1] = 1
count = 0

# print(dic)

N_2 = N - 1
def dfs(node): 
    # print(node)
    global N_2
    global count
    a = 1
    count += (N - 1) * (len(dic[node]) - 1)
    N_2 -= len(dic[node]) - 1
    a += len(dic[node]) - 1
    if N_2:
        while dic[node]:
            i = dic[node].pop()
            if not visited[i] and len(dic[i]) != 1:
                visited[node] = 1
                tmp = dfs(i)
                a += tmp - 1
                count += ((N - 1) * tmp) - (tmp * (tmp - 1)) // 2 - (N - 1)
    return a

dfs(1)
print(count)