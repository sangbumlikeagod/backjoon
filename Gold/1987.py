import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(10000)
st = sys.stdin.readline
M, N = map(int, st().split())
road = [list(st())[ : -1] for i in range(M)]
visited = [[set()] * N for i in range(M)]
visited[0][0] = set(road[0][0])

def dfs(node):
    lst = []
    # print('\n', node)
    # print()
    # print(*visited, sep='\n')
    for i in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
        if 0 <= node[0] + i[0] < M and 0 <= node[1] + i[1] < N and\
            road[node[0] + i[0]][node[1] + i[1]] not in  visited[node[0]][node[1]] and\
            (visited[node[0] + i[0]][node[1] + i[1]] & visited[node[0]][node[1]] != visited[node[0] + i[0]][node[1] + i[1]] or not visited[node[0] + i[0]][node[1] + i[1]] ) :
            visited[node[0] + i[0]][node[1] + i[1]] = visited[node[0]][node[1]] | set(road[node[0] + i[0]][node[1] + i[1]])
            if len(visited[node[0] + i[0]][node[1] + i[1]]) == 26:
                return 26
            tmp = dfs((node[0] + i[0] , node[1] + i[1]))
            if tmp == 26:
                return 26
            else:
                lst.append(tmp)
    # print(node, lst)
    # print(lst, node ) if lst else print(len(visited[node[0]][node[1]]), node)
    return max(lst) if lst else len(visited[node[0]][node[1]])
# print(road, visited)
print(dfs((0, 0)))