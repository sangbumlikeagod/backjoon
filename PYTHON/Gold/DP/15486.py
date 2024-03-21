import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
sys.setrecursionlimit(100000)
st = sys.stdin.readline
N = int(st())

maximum_table = [0] * N
somo_table = [0] * N
benefit_table = [0] * N
for _ in range(N):
    T, P = map(int, st().split())
    somo_table[_] = T
    benefit_table[_] = P
    
# print(somo_table)
# print(benefit_table)


def dp(day):
    if day >= N:
        return 0
    if maximum_table[day]:
        return maximum_table[day]
    else:
        # print(day)
        res = 0
        if somo_table[day] == 1:
            key = 1
            while day + key < N and somo_table[day + key]  == 1:
                key += 1
            res = dp(day + key) + sum(benefit_table[day : day + key])
        else: 
            if somo_table[day] + day <= N:
                res = max(dp(day + somo_table[day]) + benefit_table[day], res)
            res = max(dp(day + 1), res)
    maximum_table[day] = res
    return res   
         
print(dp(0))
# print(maximum_table)