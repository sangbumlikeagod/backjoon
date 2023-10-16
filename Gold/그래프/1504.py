import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
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
    visited = [0] * N
    que = []
    heapq.heappush(que, (0, start))
    visited[start] = 1
    while que:
        val, this = heapq.heappop(que)
        # print(val)
        if this == end and v1 in visited and v2 in visited:
            print(val)
            return val
        for i in range(N):
            if lst[this][i] and not visited[i]:
                visited[i] = 1
                heapq.heappush(que, (val + lst[this][i], i))
    return float('inf')

a = find_way(0, v1)
b = find_way(0, v2)
c = find_way(v1, v2)
d = find_way(v1, N - 1)
e = find_way(v2, N - 1)
f = find_way(0, N - 1)
# print(a, b, c, d, e, f)
ans = min([a + c + d, b + c + e, 2 * a + b + e, 2 * b + a + d + 2 * a + 2 * b + f])
print(-1) if ans == float('inf') else print(ans)
    
# 1 v1 v2 N 

    