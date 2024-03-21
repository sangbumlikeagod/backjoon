import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
N = int(st())

dx = [1, 1, 1]
dy = [-1, 0, 1]
table = [[0] * N for _ in range(N)]
# print(table)
count = 0
def ind(x):
    # print(*table, sep='\n')
    # print()
    if x == N:
        global count
        count += 1
        return
    for y in range(N):
        if not table[x][y]:
            table[x][y] = 1
            for_back = [(x, y)]
            for i in range(3):
                k = 1
                
                while 0 <= x + dx[i] * k < N and 0 <= y + dy[i] * k < N:
                    nx, ny = x + dx[i] * k, y + dy[i] * k
                    if not table[nx][ny]:
                        for_back.append((nx, ny))
                        table[nx][ny] = 1
                    k += 1
            ind(x + 1)
            while for_back:
                fx, fy = for_back.pop()
                table[fx][fy] = 0

ind(0)
print(count)
    
