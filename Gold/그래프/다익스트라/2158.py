import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
# N = int(st())

import heapq

'''

위치와 

'''

mountain = []


V, R, C = map(int, st().split())

for i in range(R):
    tmp = list(map(int, st().split()))
    mountain.append(tmp)
    

'''

이미 간곳은 안가야한다는거 알지? 속도가 더 빠를 때만? 


'''

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

que = []
heapq.heappush(que, (0, 0, 0, V))
visited = [[float('inf')] * C for _ in range(R)]
visited[0][0] =  V
while que:
    # print(que)
    t, x, y, v = heapq.heappop(que)
    if x == R - 1 and y == C - 1:
        print(t)
        break
    for i in range(4):
        nx, ny = dx[i] + x, dy[i] + y
        # 도착했을 떄의 속도가 더 높다면 가볼만해
        if 0 <= nx < R and 0 <= ny < C and visited[nx][ny] > t + 1/v:
            visited[nx][ny] =  t + 1/v
            heapq.heappush(que, (t + 1 / v, nx, ny, v * 2 ** (mountain[x][y] - mountain[nx][ny])))  
            
# print(visited)
            
        



    
