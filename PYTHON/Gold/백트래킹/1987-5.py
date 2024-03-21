import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
sys.setrecursionlimit(10000)
st = sys.stdin.readline
M, N = map(int, st().split())
road = [list(st().strip()) for i in range(M)]
new_road = [ road[i][:] for i in range(M)]
count = 0
lst = [[0, 1], [1, 0], [0, -1], [-1, 0]]
def dfs(x, y):
    global count
    count = max(count , len(new_road[x][y]))
    if count == 26:
        return 
    for i in range(4):

        nx, ny = x + lst[i][0], y + lst[i][1]
        if 0 <= nx < M and 0 <= ny < N and road[nx][ny] not in new_road[x][y]:
            new_road[nx][ny] = new_road[x][y] + road[nx][ny]
            dfs(nx, ny)
dfs(0, 0)
print(count)
        

