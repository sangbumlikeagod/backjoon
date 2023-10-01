import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
N, M = map(int,input().split())

adj_lst = [[0] * N for _ in range(N)]

for _ in range(M):
    u, v, w = map(int, input().split())
    adj_lst[u - 1][v - 1] = w
    
print(adj_lst)