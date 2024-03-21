import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
st = sys.stdin.readline
K = int(st())

H, W = map(int, st().split())

road = [list(map(int, st().split())) for _ in range(W)]
#print(*road, sep='\n')
from collections import deque

que = deque()
que.append((0, 0, 0, K))


    

visited = [[0] * H for _ in range(W)]
visited[0][0] = 0


# 상하좌우 뒤 말 움직임 시계방향
dx = [-1, 1, 0, 0, -2, -1, 1, 2, 2, 1, -1, -2]
dy = [0, 0, -1, 1, 1, 2, 2, 1, -1, -2, -2, -1]

dx2 = [0, 0, 1, -1]
dy2 = [1, -1, 0, 0]

while que:
    cordx, cordy, count, remain = que.popleft()
    print('=============================')
    print(cordx, cordy, count, que)
    print(*visited , sep = '\n')
    print('=============================')
    if cordx == W - 1 and cordy == H - 1:
        print(count)
        break

    for i in range(len(dx)):
        if 0 <= cordx + dx[i] < W and 0 <= cordy + dy[i] < H\
            and visited[cordx + dx[i]][cordy + dy[i]] < visited[cordx][cordy] + 1\
            and not road[cordx + dx[i]][cordy + dy[i]]:
            # count 기반으로 하자고 
            # que.append((cordx + dx[i], cordy + dy[i], count + 1, remain))
            
            if abs(dx[i]) + abs(dy[i]) == 1:
                visited[cordx + dx[i]][cordy + dy[i]] = visited[cordx][cordy] + 1
                que.append((cordx + dx[i], cordy + dy[i], count + 1, remain))
            elif remain > 0:
                visited[cordx + dx[i]][cordy + dy[i]] = visited[cordx][cordy] + 1
                que.append((cordx + dx[i], cordy + dy[i], count + 1, remain - 1))
            
    # break
    # elif remain:
    #     for i in range(len(dx)):
    #         if 0 <= cordx + dx[i] < W and 0 <= cordy + dy[i] < H\
    #             and not visited2[cordx + dx[i]][cordy + dy[i]]\
    #             and possible(cordx, cordy, dx[i], dy[i]): 
    #             visited[cordx + dx[i]][cordy + dy[i]] = 1  
    #             if abs(dx[i]) + abs(dy[i]) == 1:
    #                 visited2[cordx + dx[i]][cordy + dy[i]] = 1
    #                 que.append((cordx + dx[i], cordy + dy[i], count + 1, remain))
    #             else:
    #                 visited2[cordx + dx[i]][cordy + dy[i]] = 1               
    #                 que.append((cordx + dx[i], cordy + dy[i], count + 1, remain - 1))
        

    # # 한마디로 문제를 정의한다면 
    # else:
    #     for i in range(len(dx2)):
    #         if 0 <= cordx + dx2[i] < W and 0 <= cordy + dy2[i] < H\
    #             and not visited[cordx + dx2[i]][cordy + dy2[i]]\
    #             and possible(cordx, cordy, dx2[i], dy2[i]):
    #             visited[cordx + dx2[i]][cordy + dy2[i]] = 1
    #             que.append((cordx + dx2[i], cordy + dy2[i], count + 1, remain))
    # print(que)
                
    #print(que)
    #print(cordx, cordy, count, remain)
else:
    print(-1)