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

            
# print(lst)

dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]


# 어딘가에서부터 백트래킹 할건데 
maxx = 0
def find_mind(cord, mine):
    # print(cord)
    # print(*lst, sep ='\n')

    
    for row in range(cord[0], N - 1):
        if row == 1 or row == N - 2:
            for col in range(1, N - 1):

                if (row == cord[0] and col <= cord[1]) or lst[row][col] != "#":
                    continue
                is_okay = True
                # print(row, col)
                for num in range(8):
                    nx, ny = row + dx[num], col + dy[num]
                    if lst[nx][ny] != '#':
                        if not lst[nx][ny]:
                            is_okay = False 
                            break

                        if (row == 1 and num == 0) or (row == N - 2 and num == 5):
                            if lst[nx][ny] > 1:
                                is_okay = False
                                break

                if is_okay:
                    for num in range(8):
                        nx, ny = row + dx[num], col + dy[num]
                        if lst[nx][ny] != '#':
                            lst[nx][ny] -= 1 
                    find_mind((row, col), mine + 1)
                    for num in range(8):
                        nx, ny = row + dx[num], col + dy[num]
                        if lst[nx][ny] != '#':
                            lst[nx][ny] += 1 
                    find_mind((row, col), mine)
                    return
        else:
            for col in (1, N - 2):
                if (row == cord[0] and col <= cord[1]) or lst[row][col] != "#":
                    continue
                is_okay = True
                for num in range(8):
                    nx, ny = row + dx[num], col + dy[num]
                    if lst[nx][ny] != '#':
                        if not int(lst[nx][ny]):
                            is_okay = False 
                            break
                        if (col == 1 and num == 0) or (col == N - 2 and num == 2):
                            if int(lst[nx][ny]) > 1:
                                is_okay = False
                                break

                if is_okay:
                    for num in range(8):
                        nx, ny = row + dx[num], col + dy[num]
                        if lst[nx][ny] != '#':
                            lst[nx][ny] -= 1 
                    find_mind((row, col), mine + 1)
                    for num in range(8):
                        nx, ny = row + dx[num], col + dy[num]
                        if lst[nx][ny] != '#':
                            lst[nx][ny] += 1
                    find_mind((row, col), mine)
                    return

    global maxx
    maxx = max(maxx, mine)

find_mind((1, 0), 0)
print(maxx + (N - 4) ** 2) 