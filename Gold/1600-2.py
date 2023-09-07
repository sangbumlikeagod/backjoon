import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')

K = int(sys.stdin.readline())

H, W = map(int, sys.stdin.readline().split())
road = [list(sys.stdin.readline().split()) for _ in range(W)]
#print(*road, sep='\n')
from collections import deque

que = deque()
que.append((0, 0, 0))
    
visited = [[-1] * H for _ in range(W)]
visited[0][0] = K

# 상하좌우 뒤 말 움직임 시계방향
# dx_for_horse = [-2, -1, 1, 2, 2, 1, -1, -2]
# dy_for_horse = [1, 2, 2, 1, -1, -2, -2, -1]
# dx_for_monkey = [1, -1, 0, 0]
# dy_for_monkey = [0, 0, 1, -1]
d_for_monkey = [[1, 0], [-1, 0], [0, 1], [0, -1]]
dy_for_horse = [[-2, 1], [-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1]]

while que:
    cordx, cordy, count = que.popleft()
    # print('=============================')
    # print(cordx, cordy, count, que)
    # print(*visited , sep = '\n')
    # print('=============================')
    
    if cordx == W - 1 and cordy == H - 1:
        print(count)
        break
    if visited[cordx][cordy]:
        for i in dy_for_horse:
            if not(0 <= cordx + i[0] < W and 0 <= cordy +i[1] < H) \
                or road[cordx + i[0]][cordy +i[1]] == '1':
                    continue
            if visited[cordx + i[0]][cordy +i[1]] < visited[cordx][cordy]:
                visited[cordx + i[0]][cordy +i[1]] = visited[cordx][cordy] - 1
                que.append((cordx + i[0], cordy +i[1], count + 1))

    for i in d_for_monkey:
        if not(0 <= cordx + i[0] < W and 0 <= cordy +i[1] < H) or\
            road[cordx + i[0]][cordy +i[1]] == '1': 
                continue
            
            # que.append((cordx + i[0], cordy +i[1], count + 1, remain))
        if visited[cordx + i[0]][cordy +i[1]] < visited[cordx][cordy]:
            visited[cordx + i[0]][cordy +i[1]] = visited[cordx][cordy]
            que.append((cordx + i[0], cordy +i[1], count + 1))

# 칸을 3개로 줄일 수 있음
# 그런데 remain빼기 가능하지 않을까?

else:
    print(-1)