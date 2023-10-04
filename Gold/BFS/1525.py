import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

puzzle = []
for _ in range(3):
    puzzle += st().split()

puzzle = ''.join(puzzle)
dic = {
    puzzle : True
    }
 
'''
0의 위치를 알려주는 거랑 
'''
for i in range(9):
    if puzzle[i] == '0':
        start = i
        break
from collections import deque
que = deque()
que.append((puzzle, start, 0))
delta = [1, -1, 3, -3]
while que:
    Puzz, zero_position, stage = que.popleft()
    if Puzz == '123456780':
        print(stage)
        break
    for i in range(4):
        new_zero = zero_position + delta[i]
        if i == 0 or i == 1:
            if new_zero // 3 != zero_position // 3:
                continue

        if 0 <= new_zero < 9:
            if new_zero > zero_position:
                new_puzzle = Puzz[:zero_position] + Puzz[new_zero] + Puzz[zero_position + 1: new_zero] + Puzz[zero_position] + Puzz[new_zero + 1:]
            else:
                new_puzzle = Puzz[:new_zero] + Puzz[zero_position] + Puzz[new_zero + 1: zero_position] + Puzz[new_zero] + Puzz[zero_position + 1:]
            # print(
            #     f'stage : {stage}\n'
            #     f'delta : {delta[i]}\n'
            #     f'Puzz : {Puzz}\n'
            #     f'new_puzzle : {new_puzzle}\n'
            #     )
            if new_puzzle not in dic:
                print(
                    f'stage : {stage}\n'
                    f'delta : {delta[i]}\n'
                    f'Puzz : {Puzz}\n'
                    f'new_puzzle : {new_puzzle}\n'
                    )
                dic[new_puzzle] = True
                que.append((new_puzzle, new_zero, stage + 1))
else:
    print(-1)
# print(dic)
    
    
    