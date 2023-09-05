x, y, d1, d2 = 2, 4, 2, 2

import sys
# sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(100000)

N = 6

lst = [[0] * N for _ in range(N)]

# 1번 구역 설정 

for i in range(x + d1 - 1):
    for j in range( y ):
        lst[i][j] = 1
        
print(*lst, sep= '\n') 
print()
# 2번 구역 설정

for i in range(x + d2):
    for j in range( y, N ):
        lst[i][j] = 2
print(*lst, sep= '\n')  
print()


#3번 구역 설정

for i in range(x + d1 - 1, N):
    for j in range( y - d1 + d2 - 1):
        lst[i][j] = 3
print(*lst, sep= '\n')
print() 

for i in range(x + d2, N):
    for j in range(y - d1 + d2 - 1, N):
        lst[i][j] = 4
print(*lst, sep= '\n')  
