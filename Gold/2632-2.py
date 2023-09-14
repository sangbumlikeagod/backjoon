
import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
st = sys.stdin.readline
C = int(st())
A, B = map(int, st().split())
from itertools import accumulate

dic = {}
pizza_A = []
pizza_B = []

count = 0
for _ in range(A):
    tmp = int(st())
    if tmp == C:
        count += 1
    else:
        dic[tmp] = dic.get(tmp, 0) + 1
    pizza_A += [tmp]
    
for _ in range(B):
    tmp = int(st())
    pizza_B += [tmp]

ac_pizza_A = list(accumulate(pizza_A))
# print(ac_pizza_A)
if ac_pizza_A[-1] == C:
    count += 1
else:
    dic[ac_pizza_A[-1]] = dic.get(ac_pizza_A[-1], 0) + 1
# 어느애들을 어디에 넣어야하나  
    
for i in range(0, A):
    for j in range(2, A):
        if i + j < A:
            tmp = ac_pizza_A[i + j] - ac_pizza_A[i]
            if tmp == C:
                count += 1
            dic[tmp] = dic.get(tmp, 0) + 1
        else:
            tmp = ac_pizza_A[-1] - ac_pizza_A[i] + ac_pizza_A[i + j - A]
            if tmp == C:
                count += 1
            dic[tmp] = dic.get(tmp, 0) + 1

# print('\t',count)


ac_pizza_B = list(accumulate(pizza_B))        
# print(ac_pizza_B)
if ac_pizza_B[-1] == C:
    count += 1
elif C - ac_pizza_B[-1] in dic:
    count += dic[C - ac_pizza_B[-1]]
    
    
for i in range(0, B):
    for j in range(1, B):
        if i + j < B:
            tmp = ac_pizza_B[i + j] - ac_pizza_B[i]
            # print(tmp)
            if tmp == C:
                count += 1
            elif C - tmp in dic:
                # print('\t',tmp)
                count += dic[C - tmp]
                
            
        else:
            tmp = ac_pizza_B[-1] - ac_pizza_B[i] + ac_pizza_B[i + j - B]
            # print(tmp)
            if tmp == C:
                count += 1
            elif C - tmp in dic:
                # print('\t',tmp)
                count += dic[C - tmp]
                
            
print(count)
            

        