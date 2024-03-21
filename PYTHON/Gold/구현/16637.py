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

    di_stack = []
    non_digit = []
    idx = 0
    while idx < len(nex):
        # print(di_stack)
        # print(non_digit)
        if nex[idx] == '-' and (idx == 0 or not nex[idx - 1].isdigit()):
                di_stack.append(int(nex[idx: idx + 2]))
                idx += 1
        elif nex[idx].isdigit():
            di_stack.append(int(nex[idx]))
        else:
            while non_digit and dic[nex[idx]] >= dic[non_digit[-1]]:
                k = non_digit.pop()
                a, b = di_stack.pop(), di_stack.pop()
                if k == '+':
                    di_stack.append(a + b) 
                elif k == '-':
                    di_stack.append(b - a)
                elif k == '*':
                    di_stack.append(a * b)
            non_digit.append(nex[idx])
        idx += 1
            
    while non_digit:
        print(di_stack)
        print(non_digit)
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
    if nex[i] == '+' or nex[i] == '-':
        dodo.append(i)
print(dodo)

# 부분집합에서 어떤 조건 하나를 추가할 것 

dodo_clone = [0] * len(dodo)
max_val = -float('inf')
def conditional_subset(lst, idx):
    global max_val
    if idx == len(lst):
        st = nex
        for i in range(len(lst) - 1, -1 , -1):
            
            if lst[i] and st[dodo[i]] == '+':
                st = st[:dodo[i] - 1] + str(int(st[dodo[i] - 1]) + int(st[dodo[i] + 1]))      + st[dodo[i] + 2:]
            elif   lst[i] and st[dodo[i]] == '-':
                st = st[:dodo[i] - 1] + str(int(st[dodo[i] - 1]) - int(st[dodo[i] + 1]))      + st[dodo[i] + 2:]
        print(st)

        var = tupyo(st)
        print(var)
        if var > max_val:
            max_val = var
        return 
    conditional_subset(lst, idx + 1)
    if idx == 0 or abs(dodo[idx] - dodo[idx - 1]) != 2 or not lst[idx - 1]:
        lst[idx] = 1
        conditional_subset(lst, idx + 1)
        lst[idx] = 0
       
conditional_subset(dodo_clone, 0)

print(max_val)
# 후진 계산법을 활용해야하는데 ? 
# 후입가산기였나.
# 단순 부분집합문제가 아님 
# 더하기 빼기에만 해야 의미가 있긴함 