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
road = [0 for _ in range(N + 1)]
power[0] = 0
# print(porow)
cycle = {} 
def bella():
    for case in range(N):
        is_change = False
        for start in range(N):
            for end in range(N):
                if adj_lst[start][end] + power[start] < power[end]:
                    power[end] = adj_lst[start][end] + power[start]
                    road[end + 1] = start + 1
                    is_change = True
                    if case == N - 1:
                        power[end] = -float('inf')
        if not is_change:
            return True

    
alert = []
bella()
# print(power)
# print(road)
if power[N - 1] != -float('inf'):
    tmp = []
    start = N
    while start != 0:
        tmp.append(start)
        start = road[start]
        # print(start)
    print(' '.join(map(str, tmp[::-1])))
else:
    print(-1)

    
# print(power)
# 지금보니 그냥 벨만포드의 문제는 아니었
# 벨만포드의 해석에 대한 문제였.
# 벨만포드는 도착에만 관심이있고 N - 1 번 전까지는 도착이 반드시 최선이라는 점을
# 보장하지 않는다
# 2차원 리스트에 리스트를 받고 

'''

생각보다 훨씬더 많은 고민들을 필요로한다. 가는길이 있다고 다 하면 되는게 아님 
난 지금 아예 사이클을 안가버리는 방식으로 갔음
근데 이 문제는 4와 관련 있는 애가 싸이클일 때는 그게 있다고는 알려줘야함 사이클이 있으면 
사이클의 존재는 4와 관련이 있을때만 상관이 있음 n과 관련이 없는 사이클이면 상관이 없다는 것
벨만포드는 n번의 행위동안 정확히 k번의 길을 갔을때 일어나는 상황을 묘사한다
즉 사이클이 돌기전에 먼저 도착해버릴 우려가 있다는 것.

그러면 n - 1번까지의 사이클들은 전부 받아들이지 않고 정확하게 사이클이 없는 애들은 받아들이면서
사이클이 있다면 

사이클이 발견되면 저장해 두었다가 다시는 사이클이 있는 쪽으로 가지 않는다. 


마지막에
사이클이 있는 정점들을 전부 pop한다
남는애가 있다면 리턴하고 없다면 pop한다.

-발견한다?
최저 경로를 의미하는 애한테 자기가 있다면으로 처리 가능


가지않는다 == 가지 못하게한다.
어떻게 ? 
인접리스트에서 가고 오는 k행, k열을 모두 inf처리해버린다면 가능 다시는 거기론 가지 않을거야
다만 그게다야 
전부다 무한대 처리해버리면.

k가 루프인것으로 밝혀지기 전에 담겼던 경로들은 무사하지 못한다
전부 없었던 걸로 처리하면 되지 않냐? 그러면 M - 1번만 하는 벨만포드의 특성상 처음부터 다시 적용되는게 안어울릴 수 있음

그래서 일단 다시 못가게 처리를 해놓고 
이후에 =
리스트 출력을 지금방식으로 할라면 어느정도 이전 정보들을 저장을 해놔야겠는데.
인과관계를 가진 튜플로?

이만 됐다 이제 어떻게 하는질 봐보자
얘한테 갈 수 있는 모든 애들을 제거해야하는거 아니냐 
'''