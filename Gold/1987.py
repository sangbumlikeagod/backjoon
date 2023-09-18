import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(10000)
st = sys.stdin.readline
M, N = map(int, st().split())
road = [st() for i in range(M)]
visited = {}
visited[road[0][0]] = True

def dfs(node):
    lst = []
    for i in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
        if 0 <= node[0] + i[0] < M and 0 <= node[1] + i[1] < N and\
            road[node[0] + i[0]][node[1] + i[1]] not in visited:
            visited[road[node[0] + i[0]][node[1] + i[1]]] = True

            lst.append(dfs((node[0] + i[0] , node[1] + i[1])) + 1)
            visited.pop(road[node[0] + i[0]][node[1] + i[1]])
    # print(node, lst)
    return max(lst) if lst else 1

print(dfs((0, 0)))
        

