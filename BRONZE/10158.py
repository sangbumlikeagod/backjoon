# 가로 한칸 세로 한칸 이동하는데 생각해보면 무조건 절대값으로 이동하는데
# 둘의 최소공배수 만큼 시간이 시간이 지나면 올거같은데 
# 시간이 ㅈㄴ 큰거 보니 
# 근데 왜 최소공배수가 아니냐 
# + a  - a + a  - a 를 반복할거고 
# + b - b + b - b를 반복할거다 
# 최소공배수로 안되는게 부호가 반대일 수 있음 
# 최소 공배수의 의는 무조건 둘다 짝수 배수일 때 가능하다는 것
# c (짝수 ) * b = k (짝수) * a 를 가능하게 해줘야함
# 둘이 곱해주고 최대공약수로 나누면 되나 


# 최대 공약수 구하기 

import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')



M, N = map(int, input().split())

# n, m = N, M
# biggest_ronaldo = 0
# if n > m: n, m = n ,m
# while m % n:
#     m, n = n, m % n
    
# biggest_ronaldo = n
# smallest_bally = M * N // biggest_ronaldo
# if smallest_bally // M or smallest_bally // N:
#     smallest_bally *= 2
    
    
where = list(map(int, input().split()))
distance = int(input()) 

dx = distance % (2 * M)
dy = distance % (2 * N)

# print(dx, dy)
# where[0] = where[0] + M - dx if dx > M else where[0] + dx
# where[1] = where[1] + N - dy if dy > N else where[1] + dy

where[0] = (where[0] + dx) % M if not ((where[0] + dx) // M) % 2 else M - (where[0] + dx) % M
where[1] = (where[1] + dy) % N if not ((where[1] + dy) // N) % 2 else N - (where[1] + dy) % N

# direction = [1, 1]
# while distance:
#     # print(where, direction) 
#     if 0 < where[0] < M and 0 < where[1] < N:
#         where[0] += direction[0]
#         where[1] += direction[1]
#     elif  not 0 < where[0] < M and 0 < where[1] < N:
#         direction[0] *= -1
#         where[0] += direction[0]
#         where[1] += direction[1]
#     elif 0 < where[0] < M and not 0 < where[1] < N:
#         direction[1] *= -1
#         where[1] += direction[1]
#         where[0] += direction[0]
#     else:
#         direction[0] *= -1
#         direction[1] *= -1
#         where[1] += direction[1]
#         where[0] += direction[0]
#     distance -= 1

print( *where, sep=' ')