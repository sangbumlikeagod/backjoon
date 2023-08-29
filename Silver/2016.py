import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

N, M = map(int,input().split())

# 맨 부터 흰 파 빨

ans = 0 

# 아래 줄 부터 ㄱ ㄱ 
# 정확히 다돌면서 
# 제약이 전혀 없이 아무렇게나 만들수 있는 것처럼 보이는데 중간 어떤 줄을 파란색으로 바꾸면 

lst = [list(input()) for i in range(N)]
ans +=  M - lst[0].count('W')
# print(ans)

min_val = 2500


for i in range(1, N - 1):
    # i는 어찌됐든 흰색이 있을 줄 
    upper_min = 2500
    for j in range(1, i + 1):
        local_up = 0
        for k in range(1, j):
            local_up += M - lst[k].count('W')
        for blu in range(j, i ):
            local_up += M - lst[blu].count('B')
        if upper_min > local_up:
            upper_min = local_up
    down_min = 2500
    
    for b2 in range(i + 1, N - 1):
        local_down = 0
        for bl in range(i + 1, b2):
            local_down += M - lst[bl].count('B')
        for re in range(b2 , N - 1):
            local_down += M - lst[re].count('R')
        if local_down < down_min:
            down_min = local_down
    print(upper_min % 2500, down_min % 2500, i)
    if upper_min % 2500 + down_min % 2500 + M - lst[i].count('B')< min_val:
        min_val = upper_min % 2500 + down_min % 2500 + M - lst[i].count('B')

ans += min_val
ans +=  M - lst[N - 1].count('R')

print(ans)
