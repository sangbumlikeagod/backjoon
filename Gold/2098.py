import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(10000)

# 완전 똑같은데 시간의 문제
# 대칭적이지 않은데 비트 마스킹 가능 ?  12 -x-> 3 이라고 해서 마스킹 할 수는 없음
N = int(sys.stdin.readline())

NbyN = [[0] * N for _ in range(N)]
for i in range(N):
    local = list(map(int, sys.stdin.readline().split()))
    for j in range(N):
        NbyN[i][j] = local[j]

# 
import heapq

hip = []

for i in range(N):
    heapq.heappush(hip, (0, i, 1 << i, i))

min_value = 2 ** 31 - 1
# 동적 프로그래밍이라 

hip = [0, 1, 1]
for num in range(N):
    for vil in [j for j in range(N) if NbyN[j][num]]:
        hip = [(0, num, (1 << num) + (1 << vil))]
        max_len = 0
        while hip:
            if len(hip) > max_len:
                max_len = len(hip) 
            psum, next, beat = heapq.heappop(hip)
            if beat == 2 ** N - 1 and NbyN[next][vil]:
                if min_value > psum + NbyN[next][vil] + NbyN[vil][num]:
                    min_value = psum + NbyN[next][vil] +  NbyN[vil][num]
                    break
            for i in range(N):
                if NbyN[next][i] and not beat & 1 << i and psum +  NbyN[next][i] < min_value:
                    heapq.heappush(hip, (psum +  NbyN[next][i], i, beat + (1 << i)))
        print(max_len)
print(min_value)

