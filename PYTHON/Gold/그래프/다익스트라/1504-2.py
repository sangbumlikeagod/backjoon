import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
import sys
import heapq
st = sys.stdin.readline


N, E = map(int, st().split())
lst = [[0] * N for _ in range(N)]

for _ in range(E):
    a, b, c = map(int, st().split())
    lst[a - 1][b - 1] = c
    lst[b - 1][a - 1] = c


# 반드시 들러야한다. 
# 1개면 갔다가 가면 되는데 2개니까 방향이 여러개임 
# v1 -> v2 -> N 일 수도 있고 
# 한번 이동했던 정점에 
# 갔다 왔던 경로를 전부 저장해둔다면 괜찮은 애들이 나올 때 까지 반복하면 되겠지만 문제는 메모리

'''

갈 수 없는 경우가 없다니까

'''
v1 , v2 = map(int, st().split())
v1 -= 1
v2 -= 1


def find_way(start, end):
    visited = [[float('inf')] * N for _ in range(4)] 
    que = []
    heapq.heappush(que, (0, start, 0))
    visited[start][0] = 0
    while que:
        # print(que)
        # print(visited)
        val, this, state = heapq.heappop(que)
        if this == v1 and state != 3:
            if state == 2:
                state = 3
            else:
                state = 1
        elif this == v2 and state != 3:
            if state == 1:
                state = 3
            else:
                state = 2
        if this == end and state == 3:
            return val
        for i in range(N):
            if lst[this][i] and val + lst[this][i] < visited[state][i]:
                visited[state][i] = val + lst[this][i]
                heapq.heappush(que, (val + lst[this][i], i, state))

    return float('inf')
ans = find_way(0, N - 1)

print(-1) if ans == float('inf') else print(ans)
