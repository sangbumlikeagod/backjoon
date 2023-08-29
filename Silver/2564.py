# 반시계일 경우 자기의 왼쪽 모스트에 있는 애의 거리만큼을 뺄 수 있고 
# 반대편이 아닐 경우엔 그 방향으로 가는게 반드시 최소이며 자기 쪽에 있을때도 그냥 둘의 차의
# 절대값을 구해주면 된다
# 반대편에 있을 때만 좀 남다른데

import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

N, M = map(int,input().split())

'''
    1
3       4
    2
'''
ans = 0
new_di = {1 : 1,
           2 : 3,
           3 : 2,
           4 : 4}
tc = int(input()) 

gage = []
for t in range(tc):
    gage.append(list(map(int,input().split())))
# print(gage)

dongkun_di, dongkun_dis = map(int, input().split())

for i in gage:
    # print(ans)
    if abs(new_di[i[0]] % 4 - new_di[dongkun_di] % 4) == 0:
        ans += abs(i[1] - dongkun_dis)
    elif abs(new_di[i[0]] % 4 - new_di[dongkun_di] % 4) == 1:
        
        if new_di[i[0]] == 1:
            if new_di[dongkun_di] == 4:
                ans += dongkun_dis + N - i[1]
            elif new_di[dongkun_di] == 2:
                ans += i[1] + dongkun_dis
        elif new_di[i[0]] == 2:
            if new_di[dongkun_di] == 1:
                ans += dongkun_dis + i[1]
            else:
                ans += dongkun_dis + M - i[1]
        elif new_di[i[0]] == 3:
            if new_di[dongkun_di] == 2:
                ans += M - dongkun_dis + i[1]
            else:
                ans += M - dongkun_dis + N - i[1]
        else:
            if new_di[dongkun_di] == 3:
                ans += N - dongkun_dis + M - i[1]
            else:
                ans += i[1] + N - dongkun_di
    else:
        if new_di[dongkun_di] % 2:
            ans += M + min( dongkun_dis + i[1] , N - dongkun_dis  + N - i[1] )
            # print(M, dongkun_dis, i[1])
        else:
            ans += N + min (dongkun_dis + i[1] , M - dongkun_dis  + M - i[1] )
        
print(ans)