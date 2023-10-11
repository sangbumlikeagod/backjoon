import sys


name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r')
sys.stdin = file
import sys
st = sys.stdin.readline
N = int(st())



mine_pann = []
mine_where = {}
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
for i in range(N):
    row = st()
    for j in range(len(row)):
        if row[j] == '*':
            mine_where[(i, j)] = True
    # mine_pann.append(row)
    
is_bomb = False
# print(mine_where)
for i in range(N):
    row = list(st().strip())
    for j in range(len(row)):
        if mine_where.get((i ,j), 0) and row[j] == 'x':
            is_bomb = True
            # print((i, j))
        row[j] = 0 if row[j] == 'x' else '.'
    mine_pann.append(row)
    

# print(*mine_pann, sep='\n')
for arg in mine_where:
    for i in range(8):
        nx, ny = arg[0] + dx[i], arg[1] + dy[i]
        if 0 <= nx < N and 0 <= ny < N and type(mine_pann[nx][ny]) == int:
            mine_pann[nx][ny] += 1
    if is_bomb:
        mine_pann[arg[0]][arg[1]] = '*'
    
for _ in range(N):
    print(''.join(map(str, mine_pann[_])))
        
    