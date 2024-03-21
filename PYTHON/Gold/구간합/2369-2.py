import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
import sys
st = sys.stdin.readline

from itertools import accumulate
N, M, K  = map(int, st().split())


lst = []
ct = 0
for i in range(N):
    tmp = list(accumulate(list(map(int, st().split()))))
    for k in range(M):
        if lst:
            tmp[k] = (tmp[k] + lst[-1][k]) % K
            # if not tmp[k]:
            #     ct += 1
        else:
            tmp[k] %= K
            # if not tmp[k]:
            #     ct += 1
    lst += [tmp]

# print(*lst, e)
# print(*lst, sep='\n')
# 가로에 있다면 
# 크기 1짜리 크기 2짜리, 3짜리  N짜리 이렇게 있어야한다 
# 마찬가지로 위에서부터 N개 
'''
1칸짜리는 N개 있어야하며 0부터 시작한다 
2칸짜리는 N - 1개 있어야한다
N칸짜리는 N - (N - 1)개 있어야 한다 N - 1부터 시작한다.
'''

for td in range(1, N + 1):
    down = td - 1
    top = down - td
    while down < N:
        local = 0
        for kann in range(1, M + 1):
            right = kann - 1
            left = right - kann
            while right < M:
                if top == -1:
                    if left == -1:
                        if not lst[down][right] % K:
                            ct += 1
                    else:
                        if not (lst[down][right] - lst[down][left]) % K: 
                            ct += 1
                else:
                    if left == -1:
                        if not (lst[down][right] - lst[top][right]) % K:
                            ct += 1
                    else:
                        if not ((lst[down][right] - lst[down][left]) - (lst[top][right] - lst[top][left])) % K: 
                            ct += 1
                right += 1
                left += 1
        top += 1
        down += 1
print(ct)
    

