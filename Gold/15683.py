import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(100000)
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

N, M = map(int, input().split())
mamamax = N * M
camera = []
room = []
for i in range(N):
    local = list(map(int, input().split()))
    for j in range(M):
        if local[j]:
            if local[j] != 6:
                camera.append((i, j))
            else: mamamax -= 1
    room += [local]
print(room, camera)
# 크기와 

        


            
