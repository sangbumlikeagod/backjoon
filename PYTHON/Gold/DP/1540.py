import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

N, M = map(int, st().split())

lst = [list(map(int, st().split())) for _ in range(N)]

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
dic = {}

def dp(cord):
    if cord in dic:
        return dic[cord]
    if cord == (N - 1, M - 1):
        return 1
    res = 0
    val = lst[cord[0]][cord[1]]
    for _ in range(4):
        nx, ny = cord[0] + dx[_], cord[1] + dy[_]
        if 0 <= nx < N and 0 <= ny < M and lst[nx][ny] < val:
            res += dp((nx, ny))
    dic[cord] = res
    return res

print(dp((0, 0)))