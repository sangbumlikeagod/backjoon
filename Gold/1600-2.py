import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
K = int(input())

H, W = map(int, input().split())
road = [input().split() for _ in range(W)]
#print(*road, sep='\n')
from collections import deque
que = deque([(0, 0, 0, K)])
    
visited = [[-1 for _ in range(H)] for _ in range(W)]
monkey = [[1, 0], [-1, 0], [0, 1], [0, -1]]
horse = [[-2, 1], [-1, 2], [1, 2], [2, 1], [2, -1], [1, -2], [-1, -2], [-2, -1]]

W, H = W-1, H-1
answer = -1

def why_not_working(next_x, next_y):
    if 0 <= next_x <= W and 0 <= next_y <= H:
        return False
    return True 
    
    
while que:
    cordx, cordy, count, remain = que.popleft()
    
    if cordx == W and cordy == H:
        answer = count
        break
    if remain >= 1:
        for i in horse:
            next_x, next_y = cordx + i[0], cordy +i[1]
            if why_not_working(next_x, next_y) \
                or road[next_x][next_y] == '1':
                    continue
            if visited[next_x][next_y] < remain:
                visited[next_x][next_y] = remain - 1
                que.append((next_x, next_y, count + 1, remain - 1))

    for i in monkey:
        next_x, next_y = cordx + i[0], cordy +i[1]
        if why_not_working(next_x, next_y) or\
            road[next_x][next_y] == '1': 
                continue
            
        if visited[next_x][next_y] < remain:
            visited[next_x][next_y] = remain
            que.append((next_x, next_y, count + 1 , remain))

# 칸을 3개로 줄일 수 있음
# 그런데 remain빼기 가능하지 않을까?

print(answer)