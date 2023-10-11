import sys
sys.stdin = open('2140.txt','r')
import sys
sys.setrecursionlimit(200000)
st = sys.stdin.readline

N = int(st())


lst = [list(st().strip()) for _ in range(N)]
for row in range(N):
    for column in range(N):
        if lst[row][column] != '#':
            lst[row][column] = int(lst[row][column])
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]


change = True
ans = 0
while change:
    change = False
    # print(ans)
    # print(*lst, sep='\n')
    for row in range(N):
        for column in range(N):
            if row == 0 or row == N - 1 or column == 0 or column == N - 1:
                ct = 0
                st = []
                for num in range(8):
                    nx, ny = row + dx[num], column + dy[num]
                    if 0 <= nx < N and 0 <= ny < N and lst[nx][ny] == '#':
                        ct += 1
                        st.append((nx, ny))
                if not lst[row][column]:
                    for arg in st:
                        lst[arg[0]][arg[1]] = 'x'
                elif ct == lst[row][column]:
                    change = True
                    for arg in st:
                        for num in range(8):
                            nx, ny = arg[0] + dx[num], arg[1] + dy[num]
                            if 0 <= nx < N and 0 <= ny < N and type(lst[nx][ny]) == int:
                                lst[nx][ny] -= 1
                        lst[arg[0]][arg[1]] = '*'
                        ans += 1
                
if N >= 5:
    ans += (N - 4) ** 2
print(ans)
# print(*lst, sep='\n')
