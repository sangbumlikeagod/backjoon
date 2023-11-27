import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(10000)
st = sys.stdin.readline



def calculate(num, cal_type):
    if cal_type == "D":
        return (num * 2) % 10000
    
    elif cal_type == "S":
        if not num:
            return 9999
        else: return num - 1

    elif cal_type == "L":

        st_num = '0' * (4 - len(str(num))) + str(num)
        return(int(st_num[1: 4] + st_num[0]))

    else:
        st_num = '0' * (4 - len(str(num))) + str(num)
        return(int(st_num[3] + st_num[0: 3]))

test_case = int(st())
from collections import deque

for i in range(test_case):
    dic = {}
    # print('=======================================',i)
    num, target = map(int, st().split())
    que = deque()
    que.append(('', num))
    while que:
        # print(que, dic)
        command, c_num = que.popleft()
        if c_num == target:
            print(command)
            break

        for i in ["D","S", "L",'R']:
            tmp = calculate(c_num, i)
            if tmp not in dic:
                dic[tmp] = len(command) + 1
                que.append((command + i, tmp))




    

