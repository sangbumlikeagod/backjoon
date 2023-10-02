import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
N, M = map(int,input().split())

adj_lst = [[float('inf')] * N for _ in range(N)]

for _ in range(M):
    u, v, w = map(int, input().split())
    adj_lst[u - 1][v - 1] = - w
    
# print(*adj_lst, sep='\n')
# print()
power = [float('inf')] * N
road = [[] for _ in range(N)]
power[0] = 0
road[0] += '1'

def bella():
    for case in range(M):
        # print(power)
        lst_copy = power.copy()
        for start in range(N):
            for end in range(N):
                if adj_lst[start][end] + power[start] < power[end] and str(end + 1) not in road[start]:
                    power[end] = adj_lst[start][end] + power[start]
                    road[end] = road[start] + [str(end + 1)]
        if lst_copy == power:
            return road[N - 1]
        if case == M - 1:
            return []
    
tmp = bella()
if tmp:
    print(' '.join(tmp))
else:
    print(-1)
    
print(road)
# print(power)
# 지금보니 그냥 벨만포드의 문제는 아니었
# 벨만포드의 해석에 대한 문제였.
# 벨만포드는 도착에만 관심이있고 N - 1 번 전까지는 도착이 반드시 최선이라는 점을
# 보장하지 않는다
# 2차원 리스트에 리스트를 받고 

'''

생각보다 훨씬더 많은 고민들을 필요로한다. 가는길이 있다고 다 하면 되는게 아님 
난 지금 아예 사이클을 안가버리는 방식으로 갔음

'''