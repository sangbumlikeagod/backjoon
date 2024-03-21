import sys
sys.stdin = open(__file__.split('''\\''')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

N, M = map(int, st().split())
pann = [list(map(int, st().split())) for _ in range(N)]
large_num = max(map(max, pann))

dx = [0, 1, -1, 0]
dy = [1, 0, 0, -1]
maxx = 0

import itertools
def tetromino(cord):
    origin = cord

    def move(cord, left, val):
        global maxx
        if left == 0:
            maxx = max(val, maxx)
            return
        if maxx >= val + large_num * ( left ):
            return
        possible = []
        for i in range(4):
            nx, ny = cord[0] + dx[i], cord[1] + dy[i]
            if 0 <= nx < N and 0 <= ny < M and not visited[nx][ny]:
                visited[nx][ny] = 1
                move((nx, ny), left - 1, val + pann[nx][ny])
                possible.append((nx, ny))
        for arg in possible:
            visited[arg[0]][arg[1]] = 0
            
        if 2 <= len(possible):
            ct = 2
            while ct <= left:
                for arg in itertools.combinations(possible, ct):
                    tmp = val
                    for sub in arg:
                        tmp += pann[sub[0]][sub[1]]
                        visited[sub[0]][sub[1]] = 1
                    for sub in arg:
                        move(sub, left - ct, tmp)
                        visited[sub[0]][sub[1]] = 0
                ct += 1

    move(cord, 3, pann[cord[0]][cord[1]]) 

visited = [[0] * M for _ in range(N)]  
for row in range(N):
    for column in range(M):
        visited[row][column] = 2
        tetromino((row, column))
print(maxx)
# print(*total_visited, sep='\n')
'''
상하좌우 제약없이 움직일 수 있어야함 좌우로 분기가 나뉘는 경우를 생각해줘야함 

4 3 
1 2 
와
4 1
3 2
를 막아줄 방법

또한 

ㅗ 형태를 해줄방법, dfs로도 안되고 bfs로도 그냥은 구현이 안된다.
문제는 좌우 또는 상하 등등을 전부 추가하는 방법. 
갈 수 있는 애들의 조합으로 문제를 풀어야 할 수도 있다.
비트마스킹으로 가능해 

같은경로를 삭제하는 법을 몰라

방향성에 문제가 있다는 거에요시발 

다시 dfs로 바꿀까?

이미 한번 간대는 가지마라고하면 괜찮아지지 않을까
모든조합을 보지는 않고 갈 수 있는 곳이 더 많을때 
'''