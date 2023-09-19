import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')

st = sys.stdin.readline
M, N = map(int, st().split())
road = [list(st())[ : -1] for i in range(M)]
visited = [[''] * N for i in range(M)]
visited[0][0] = road[0][0]
from heapq import heappush, heappop



def dfs(node):
    lst = []
    # print('\n', node)
    # print(*visited, sep='\n')
    for i in [[-1, 0], [1, 0], [0, -1], [0, 1]]:
        if 0 <= node[0] + i[0] < M and 0 <= node[1] + i[1] < N and\
            road[node[0] + i[0]][node[1] + i[1]] not in  visited[node[0]][node[1]] and\
            (visited[node[0] + i[0]][node[1] + i[1]] not in visited[node[0]][node[1]] or not visited[node[0] + i[0]][node[1] + i[1]] ) :
            visited[node[0] + i[0]][node[1] + i[1]] = visited[node[0]][node[1]] + road[node[0] + i[0]][node[1] + i[1]]
            if len(visited[node[0] + i[0]][node[1] + i[1]]) == 26:
                return 26
            tmp = dfs((node[0] + i[0] , node[1] + i[1]))
            if tmp == 26:
                return 26
            else:
                heappush(lst, -tmp)
    # print(node, lst)
    # print(lst, node ) if lst else print(len(visited[node[0]][node[1]]), node)
    return heappop(lst) * -1 if lst else len(visited[node[0]][node[1]])
# print(road, visited)
print(dfs((0, 0)))