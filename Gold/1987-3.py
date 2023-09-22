import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')

st = sys.stdin.readline
M, N = map(int, st().split())
road = [st() for i in range(M)]
visited = {}
visited[road[0][0]] = True
ans = 0
def dfs(nodex, nodey, count):
    global ans
    ans = max(ans, count)
    for i in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
        if 0 <= nodex + i[0] < M and 0 <= nodey + i[1] < N and\
            road[nodex + i[0]][nodey + i[1]] not in visited:
            visited[road[nodex + i[0]][nodey + i[1]]] = True

            dfs(nodex + i[0] , nodey + i[1], count + 1)
            visited.pop(road[nodex + i[0]][nodey + i[1]])
    # print(node, lst)
dfs(0, 0, 1)
print(ans)