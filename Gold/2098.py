import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

# 완전 똑같은데 시간의 문제
# 대칭적이지 않은데 비트 마스킹 가능 ?  12 -x-> 3 이라고 해서 마스킹 할 수는 없음
N = int(sys.stdin.readline())

NbyN = [[0] * N for _ in range(N)]
for i in range(N):
    local = list(map(int, sys.stdin.readline().split()))
    for j in range(N):
        NbyN[i][j] = local[j]

# 다익스트라로 갈수있는곳과 비트넣어
import heapq

hip = []

for i in range(N):
    heapq.heappush(hip, (0, i, 1 << i, i))
# print(hip)

min_value = 2 ** 31 - 1
origin = 2


for num in range(N):
    hip = [(0, num, 1 << num)]
    while hip:
        psum, next, beat = heapq.heappop(hip)
        # print(next, psum, beat)
        if beat == 2 ** N - 1 and NbyN[next][num]:
            # heapq.heappush(hip, (psum +  NbyN[next][origin], origin, beat + (1 << origin), origin))
            if min_value > psum + NbyN[next][num]:
                min_value = psum + NbyN[next][num]
                break
                
        # elif 2 ** (N + 1)  - 1> beat > 2 ** N - 1:
        #     min_value = psum
        #     break
        for i in range(N):
            if NbyN[next][i] and not beat & 1 << i:
                heapq.heappush(hip, (psum +  NbyN[next][i], i, beat + (1 << i)))
                

print(min_value)