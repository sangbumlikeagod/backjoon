import sys

name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r', encoding='utf-8')
sys.stdin = file


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
    
print(start)
print(total)
if not total:
    print(0)
    exit()
    
ans = -1

dic = {
    1 : 5,
    2 : 5,
    3 : 5,
    4 : 5,
    5 : 5}

table_lst = {
    1 : [(a, b) for a in range(1) for b in range(1) if a == 0 or b == 0],
    2 : [(a, b) for a in range(2) for b in range(2) if a == 1 or b == 1],
    3 : [(a, b) for a in range(3) for b in range(3) if a == 2 or b == 2],
    4 : [(a, b) for a in range(4) for b in range(4) if a == 3 or b == 3],
    5 : [(a, b) for a in range(5) for b in range(5) if a == 4 or b == 4],
    }

def dfs(cord):
    d = 1
    while d <= 5:
        for arg in table_lst[d]:
            if 
            
    return
    # 언제까지 

# for i in range(1, 6):
#     print(table_lst[i])
    