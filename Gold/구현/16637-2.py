import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')


N = int(input())
nex = input()


dic = {
    '+' : 1,
    '-' : 1,
    '*' : 1,
    '/' : 1,
    '(' : 3,
    ')' : 3
    }
dic_inside = {
    '+' : 1,
    '-' : 1,
    '*' : 1,
    '/' : 1,
    '(' : 0,
    ')' : 3
    }


def tupyo(nex):

    di_stack = []
    non_digit = []
    for i in nex:
        # print(di_stack)
        if i.isdigit():
            di_stack.append(int(i))
        elif i == ')':
            while non_digit[-1] != '(':
                di_stack.append(non_digit.pop())
            non_digit.pop()
        else:
            while non_digit and dic_inside[non_digit[-1]] >= dic[i]:
                di_stack.append(non_digit.pop())
            non_digit.append(i)
    while non_digit:
        di_stack.append(non_digit.pop())
    
    # print(di_stack)
    calcul = []
    for i in range(len(di_stack)):
        if di_stack[i] not in dic:
            calcul.append(di_stack[i])
        else:
            a, b = calcul.pop(), calcul.pop()
            if di_stack[i] == '+':
                calcul.append(b + a)
            elif di_stack[i] == '-':
                calcul.append(b - a)
            else:
                calcul.append(b * a)
            
    return calcul[0]
            
    # print(calcul[0])
max_val = -float('inf')
    
def make_paren(st, idx):
    global max_val
    p1 = idx
    while p1 < len(st):
        p2 = p1 + 2
        if p2 < len(st):
            make_paren(st[:p1] + '(' + st[p1:p2 + 1] + ')' + st[p2 + 1:], p2 + 4)
            

        p1 += 2
    # print(st)
    a = tupyo(st)
    # print(a)
    if a > max_val:
        max_val = a
# print(tupyo(nex))
make_paren(nex, 0)
print(max_val)