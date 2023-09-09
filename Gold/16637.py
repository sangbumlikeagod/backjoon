# 입력값을 보면 모두 1자리 숫자들이고 
# 최대 2 ** 9 개의 불과한 연산이기 떄문에 일단 전부 조지자
# 

import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

N = int(input())
nex = input()


dic = {
    '+' : 2,
    '-' : 2,
    '*' : 1,
    '/' : 1
    }


def tupyo(nex):
    for i in nex:

        di_stack = []
        non_digit = []
        # print(di_stack)
        # print(non_digit)
        if i.isdigit():
            di_stack.append(int(i))
        else:
            while non_digit and dic[i] > dic[non_digit[-1]]:
                k = non_digit.pop()
                a, b = di_stack.pop(), di_stack.pop()
                if k == '+':
                    di_stack.append(a + b)
                elif k == '-':
                    di_stack.append(b - a)
                elif k == '*':
                    di_stack.append(a * b)
            non_digit.append(i)
            
    while non_digit:
        k = non_digit.pop()
        a, b = di_stack.pop(), di_stack.pop()
        if k == '+':
            di_stack.append(a + b)
        elif k == '-':
            di_stack.append(b - a)
        elif k == '*':
            di_stack.append(a * b)
    return di_stack[0]
            
        
# 가산기 만들었는데 이제 남은 한 기능 + 와 -에 대해서 나눠야함

dodo = []
for i in range(len(nex)):
    print(nex[i])
    if nex[i] == '+' or nex[i] == '-':
        dodo.append(i)
print(dodo)
            
            
        
    

# 후진 계산법을 활용해야하는데 ? 
# 후입가산기였나.
# 단순 부분집합문제가 아님 
# 더하기 빼기에만 해야 의미가 있긴함 