import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(100000)

A, P = map(int, sys.stdin.readline().split())

#A의 각자리 숫자들을 P제곱 하는 기능 구현
def func(A, P):
    retu_rn = 0
    while A >= 1:
        retu_rn += (A % 10) ** P
        A //= 10
    return retu_rn


        
# print(func(57, 2)) 
stack = [A]
dic = {A : True}

while dic.get(stack[-1], False): # 바로 요 놈이 반복되지 않을 때까지
    maybe_over = func(stack[-1], P)
    if maybe_over in dic:
        break
    stack.append(maybe_over)
    dic[maybe_over] = True
    # print(stack)
    
while stack[-1] != maybe_over:
    stack.pop()
# print(stack)
print(len(stack) - 1)
    