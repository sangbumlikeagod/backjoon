import sys
name = __file__.split('\\')[-1][:-5]
file = open(f'{name}.txt', 'r', encoding='utf-8')
sys.stdin = file
import sys
from copy import deepcopy

table = []
total = 0
start = None
for i in range(10):
    tmp = list(map(int, input().split()))
    for j in range(10):
        if tmp[j]:
            if not start:
                start = (i, j)
            total += 1
    table.append(tmp)

# print(total)
if not total:
    print(0)
    exit()
    
# ans = -1

dic = {
    1 : 5,
    2 : 5,
    3 : 5,
    4 : 5,
    5 : 5}

# table_lst = {
#     1 : [(a, b) for a in range(1) for b in range(1) if a == 0 or b == 0],
#     2 : [(a, b) for a in range(2) for b in range(2) if a == 1 or b == 1],
#     3 : [(a, b) for a in range(3) for b in range(3) if a == 2 or b == 2],
#     4 : [(a, b) for a in range(4) for b in range(4) if a == 3 or b == 3],
#     5 : [(a, b) for a in range(5) for b in range(5) if a == 4 or b == 4],
#     }
table_lst = {
    1 : [(0, 0)],
    2 : [(0, 1), (1, 0), (1, 1)],
    3 : [(0, 2), (1, 2), (2, 0), (2, 1), (2, 2)],
    4 : [(0, 3), (1, 3), (2, 3), (3, 0), (3, 1), (3, 2), (3, 3)],
    5 : [(0, 4), (1, 4), (2, 4), (3, 4), (4, 0), (4, 1), (4, 2), (4, 3), (4, 4)],
    }

minn = 25
visitied = [[0] * 10 for _ in range(10)]
def dfs(cord, visitied):
    global minn
    d = 1
    flag = True
    tmp = 0
    for i in dic:
        tmp += dic[i]
    if 25 - tmp >= minn:
        return
    while d <= 5 and flag:
        for arg in table_lst[d]:
            nx = cord[0] + arg[0]
            ny = cord[1] + arg[1]
            if not (0 <= nx < 10 and 0 <= ny < 10 and table[nx][ny] and not visitied[nx][ny]):
                flag = False
                break
        if not flag:
            break
        for arg in table_lst[d]:
            nx = cord[0] + arg[0]
            ny = cord[1] + arg[1]
            visitied[nx][ny] = 1
        d += 1
    d -= 1
    while d:
        ne_visited = deepcopy(visitied)
        
        s_flag = True
        if dic[d]:
            for i in range(10):
                for j in range(10):
                    if table[i][j] and not ne_visited[i][j]:
                        dic[d] -= 1
                        dfs((i, j), ne_visited)
                        dic[d] += 1
                        s_flag = False
                        break  
                if not s_flag:
                    break
            else:
                tmp = 0
                for i in dic:
                    tmp += dic[i]
                tmp -= 1
                minn = min(minn, 25 - tmp)  
        for arg in table_lst[d]:
            nx = cord[0] + arg[0]
            ny = cord[1] + arg[1]
            visitied[nx][ny] = 0
        d -= 1     
    return

dfs(start, visitied)
if minn == 25:
    print(-1)
else:
    print(minn)


'''

정답 코드

'''

from copy import deepcopy

table = []
total = 0
start = None
for i in range(10):
    tmp = list(map(int, input().split()))
    for j in range(10):
        if tmp[j]:
            if not start:
                start = (i, j)
            total += 1
    table.append(tmp)

if not total:
    print(0)
    exit()
    
# ans = -1

dic = {
    1 : 5,
    2 : 5,
    3 : 5,
    4 : 5,
    5 : 5}

# table_lst = {
#     1 : [(a, b) for a in range(1) for b in range(1) if a == 0 or b == 0],
#     2 : [(a, b) for a in range(2) for b in range(2) if a == 1 or b == 1],
#     3 : [(a, b) for a in range(3) for b in range(3) if a == 2 or b == 2],
#     4 : [(a, b) for a in range(4) for b in range(4) if a == 3 or b == 3],
#     5 : [(a, b) for a in range(5) for b in range(5) if a == 4 or b == 4],
#     }
table_lst = {
    1 : [(0, 0)],
    2 : [(0, 1), (1, 0), (1, 1)],
    3 : [(0, 2), (1, 2), (2, 0), (2, 1), (2, 2)],
    4 : [(0, 3), (1, 3), (2, 3), (3, 0), (3, 1), (3, 2), (3, 3)],
    5 : [(0, 4), (1, 4), (2, 4), (3, 4), (4, 0), (4, 1), (4, 2), (4, 3), (4, 4)],
    }

minn = 25
def dfs(cord):
    global minn
    d = 1
    flag = True
    tmp = 0
    for i in dic:
        tmp += dic[i]
    if 25 - tmp >= minn:
        return
    while d <= 5 and flag:
        for arg in table_lst[d]:
            nx = cord[0] + arg[0]
            ny = cord[1] + arg[1]
            if not (0 <= nx < 10 and 0 <= ny < 10 and table[nx][ny]):
                flag = False
                break
        if not flag:
            break
        for arg in table_lst[d]:
            nx = cord[0] + arg[0]
            ny = cord[1] + arg[1]
            table[nx][ny] = 0
        d += 1
    d -= 1
    while d:
        s_flag = True
        if dic[d]:
            for i in range(10):
                for j in range(10):
                    if table[i][j]:
                        dic[d] -= 1
                        dfs((i, j))
                        dic[d] += 1
                        s_flag = False
                        break  
                if not s_flag:
                    break
            else:
                tmp = 0
                for i in dic:
                    tmp += dic[i]
                tmp -= 1
                minn = min(minn, 25 - tmp)  
        for arg in table_lst[d]:
            nx = cord[0] + arg[0]
            ny = cord[1] + arg[1]
            table[nx][ny] = 1
        d -= 1     
    return

dfs(start)
if minn == 25:
    print(-1)
else:
    print(minn)