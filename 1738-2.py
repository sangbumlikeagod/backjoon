import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
N, M = map(int,input().split())
lst = [0, 0] + [float('inf')] * (N - 1)
