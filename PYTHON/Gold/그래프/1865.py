import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

testcase = int(st())
def bf():
    # print(node)
    for i in range(N):
        is_change = False
        for start in range(N):
            for end in range(N):
                if node[start] + adj_lst[start][end] < node[end]:
                    node[end] = node[start] + adj_lst[start][end]
                    is_change = True
                    if not visited[end]:
                        visited[end] = 1
        if not is_change:
            return True
        if i == N - 1:
            return False

for i in range(testcase):
    N, M, W = map(int, st().split())
    visited = [0] * N
    adj_lst = [[float('inf')] * N for _ in range(N)]
    for i in range(M):
        S, E, T = map(int, st().split())
        adj_lst[S - 1][E - 1] = min(adj_lst[S - 1][E - 1], T)
        adj_lst[E - 1][S - 1] = min(adj_lst[S - 1][E - 1], T)
    
    for i in range(W):
        S, E, T = map(int, st().split())
        adj_lst[S - 1][E - 1] = min(adj_lst[S - 1][E - 1], -T)

    for nd in range(N):
        if not visited[nd]:
            node = [float('inf')] * N
            node[nd] = 0
            visited[nd] = 1
            if not bf():
                print('YES')
                break
    else:
        print('NO')
