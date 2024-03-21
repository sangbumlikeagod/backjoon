import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
N = int(sys.stdin.readline())
data = [list(map(int, sys.stdin.readline().split())) for i in range(N)]

# 전부다 리스트에 박고 거리를 구하라하면 무조건 틀리겠지 델타가 있으면 상관이 없는데
# 