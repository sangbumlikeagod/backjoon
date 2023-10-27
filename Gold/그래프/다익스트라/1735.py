import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline


V, E = map(int, st().split())
K = int(st())

lst = [[0] * V for _ in range(V)]
for _ in range(E):
    s, e, w = map(int, st().split())
    if lst[s - 1][e - 1]:
        continue