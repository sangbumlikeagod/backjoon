from itertools import permutations, product
from collections import deque
from copy import deepcopy
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
input = sys.stdin.readline

matrix = [[[0] * 5 for _ in range(5)] for _ in range(5)]
dx = [0, 0, 0, 0, 1, -1]
dy = [0, 0, 1, -1, 0, 0]
dz = [1, -1, 0, 0, 0, 0]
new_matrix =  [[[0] * 5 for _ in range(5)] for _ in range(5)]

for i in range(5):
    for j in range(5):
            matrix[i][j] = list(map(int, input().split())) 




# def bfs(x, y):
def bfs():
    visited =  [[[0] * 5 for _ in range(5)] for _ in range(5)]
    que = deque()
    que.append((0, 0, 0, 0))
    visited[0][0][0] = 1

    while que:
        iz, ix, iy, count = que.popleft()

        if iz == 4 and ix == 4 and iy == 4:
            return count
        
        for i in range(6):
            nz = iz + dz[i]
            ny = iy + dy[i]
            nx = ix + dx[i]
            if (0 <= nx < 5 and 0 <= ny < 5 and 0 <= nz < 5 and new_tmp_matrix[nz][nx][ny] == 1 and visited[nz][nx][ny] == 0):
                visited[nz][nx][ny] = 1
                que.append((nz, nx, ny, count + 1))
                
    return 1000000

maxVal = 1000000

# 몇번째 바꿀건지, 몇번 회전할건지
def rotation(idx, left):
    if (not left): return
    tmp = []
    for t in zip(*new_tmp_matrix[idx]):
        tmp.append(list(reversed(t)))
    new_tmp_matrix[idx] = tmp
    rotation(idx, left - 1)



for i in permutations(range(5)):
    for _ in range(5):
        new_matrix[_] = deepcopy(matrix[i[_]])
    # 새로운 매트릭스 형성
    # 매트릭스 돌리기 
    
    for j in product(range(4), range(4), range(4), range(4), range(4)):
        new_tmp_matrix = deepcopy(new_matrix)
         # 여기서부터 rotation과 시작 
        for idx in range(5):
            rotation(idx, j[idx])
        if new_tmp_matrix[0][0][0] == new_tmp_matrix[4][4][4] == 1:
            val = bfs()
            if val == 12:
                print(12)
                sys.exit()
            maxVal = min(maxVal, val)
if maxVal == 1000000:
    print(-1)
else:
    print(maxVal)
