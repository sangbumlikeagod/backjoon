import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

N = int(sys.stdin.readline())

NbyN = [[0] * N for _ in range(N)]
for i in range(N):
    local = list(map(int, sys.stdin.readline().split()))
    for j in range(N):
        NbyN[i][j] = local[j]

#print(NbyN)

# 4개를 dfs로 탐색할 수 있다, 힙을 다용한 다익스사라도
# 사용 가능할 것처럼 보이는데 
# 

def dfs(vil, num, visited, origin):
    local = []
    if num == N:
        return NbyN[vil][origin] if NbyN[vil][origin] else 2 ** 31 - 1
    for i in range(N):
        if NbyN[vil][i] and visited[i] == 0:
            visited[i] = 1
            local.append(dfs(i, num + 1, visited, origin) + NbyN[vil][i])
            visited[i] = 0
    if not local:
        return 2 ** 31 - 1
    return min(local)

min_value = 2 ** 31 - 1
for i in range(N):
    visited = [0] * N
    visited[i] = 1
    local = dfs(i, 1, visited, i)
    if local < min_value:
        min_value = local

print(min_value)