import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline


def dp(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1
    elif a > 20 or b > 20 or c > 20:
        return dp(20, 20, 20)
    else:
        if visited[a][b][c] is not None:
            return visited[a][b][c]
        res = 0
        if a < b < c:
            res += dp(a, b, c- 1) + dp(a, b - 1, c- 1) - dp(a, b - 1, c)
        else:
            res += dp(a - 1, b, c) + dp(a - 1, b - 1, c) + dp(a - 1, b, c - 1) - dp(a - 1, b - 1, c - 1)
        visited[a][b][c] = res
        return res


visited = [[[None] * 51 for _ in range(51)] for _ in range(51)]
while True:
    a, b, c = map(int, st().split())
    if a == -1 and b == -1 and c == -1:
        break
    else:
        print(f'w({a}, {b}, {c}) = {dp(a, b, c)}')