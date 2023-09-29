import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

# 궁수가 3명이라는게 좀 빡침 어디다 둬야할지는 끝까지 가봐야 아는거라서 
# 심지어 거리가 겹칠 수도 있어 
# 칸을 구현하지 말고 역으로 적의 모든 위치에 대해서 맨 밑에줄 간의 거리를 구해야한다 

N, M, D = map(int, input().split())

'''

M개의 열중에서 3개를 고른다.


'''

origin = []
for i in range(N):
    origin.append(list(map(int, input().split())))
    

ans = 0 
def shot(archer):
    local = 0
    turn = N - 1
    # print('=======================',archer,'==========================')
    while turn >= 0:
        drop = set()
        for arch in archer:
            d = 0
            start = (turn, arch)
            flag = True
            while d < D and flag:
                candidate = [(i, j) for j in range(-d, d + 1)  for i in range(-d, d + 1) if abs(i) + abs(j) == d if i <= 0]
                # print(candidate)
                
                for kann in candidate:
                    nx = start[0] + kann[0]
                    ny = start[1] + kann[1]
                    if 0 <= nx < N and 0 <= ny < M and lst[nx][ny]:
                        # print(arch, nx, ny)
                        drop.add((nx, ny))
                        flag = False
                        break
                d += 1
        # print(drop)
        for died in drop:
            local += 1
            lst[died[0]][died[1]] = 0
        turn -= 1
        # print(*lst, sep = '\n')
    return local
    

maxx = 0
for a in range(M - 2):
    for b in range(a + 1, M - 1):
        for c in range(b + 1, M):
            lst = [a[:] for a in origin]
            # print(lst)
            tmp = shot([a, b, c])
            maxx = max(tmp, maxx)
            # print([a, b, c])

print(maxx)
# 총 M C 3 의 가지수 안에서 하나씩 
