import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
sys.setrecursionlimit(100000)
testcase = int(st())

def search(node):
    # print(node)
    if node in dic:
        return dic[node]
    
    maxable_root = None 
    maxx = 0
    if adj_lst[node]:
        for i in adj_lst[node]:
            # print(i)
            cave, value = i[0], i[1]
            tmp = search(cave) + value
            if tmp > maxx:
                maxx = tmp
                maxable_root = cave
    
    dic[node] = maxx
    gogo[node] = maxable_root
    return maxx
    
            


# 여기 가서 받을 수 있는 최대의 값을 Dp로 설정해 놓는거지


for _ in range(testcase):
    N, E = map(int, st().split())
    adj_lst = [[] for _ in range(N)] 
    Vn = list(map(int, st().split()))
    dic = {}

    for i in range(E):
        a, b, c = map(int, st().split())
        adj_lst[a - 1].append((b - 1, Vn[b - 1] - c))
    # print(adj_lst)
    gogo = [''] * (N + 1)
    # print(*adj_lst, sep='\n') 
    # print()
    search(0)
    # print(dic)
    # print(gogo)
    start = 0
    lst = []
    ct = 1
    while gogo[start]:
        lst.append(start + 1)
        ct += 1
        start = gogo[start]
    lst.append(start + 1)
    print(dic[0] + Vn[0], ct)
    print(' '.join(map(str, lst)))


