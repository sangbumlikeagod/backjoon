import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
N = int(st())
grid = [list(st().strip()) for _ in range(N)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

handicap = {'R' : 1,
            'G' : 1,
            'B' : 2}

normal = {'R': 1,
          'B': 2,
          'G': 3}
# print(grid)
def search(eye):
    region = 0
    if eye == handicap:
        is_handicap = 1
    else:
        is_handicap = 0
    for row in range(N):
        for col in range(N):
            if not visited[row][col]:
                # print(row, col)
                visited[row][col] = 1
                dfs((row, col), grid[row][col], is_handicap)
                region += 1
                # print(*visited)
    return region
       
def dfs(cord, base, is_handicap):
    # print(cord, base)
    for i in range(4):
        nx, ny = cord[0] + dx[i], cord[1] + dy[i]
        if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
            if is_handicap:
                if handicap[grid[nx][ny]] == handicap[base]:
                    visited[nx][ny] = 1
                    dfs((nx, ny), base, is_handicap)
            else:
                if normal[grid[nx][ny]] == normal[base]:
                    visited[nx][ny] = 1
                    dfs((nx, ny), base, is_handicap)

visited = [[0] * N for _ in range(N)]
a = search(normal)
visited = [[0] * N for _ in range(N)]
b = search(handicap)
print(a, b)


