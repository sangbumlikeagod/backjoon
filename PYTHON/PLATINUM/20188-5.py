import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
st = sys.stdin.readline
sys.setrecursionlimit(400000)
N = int(st())
dic = {}
for i in range(N - 1):
    a, b = map(int, st().split())
    dic[a] = dic.get(a, []) + [b]
    dic[b] = dic.get(b, []) + [a]




visited = [0] * (N + 1)
count = 0
def dfs(node, layer): 
    global count
    # print(node, layer, valueofbro, numofbro)
    visited[node] = 1

    # print(f'{node} \t {base_value + base_brother_num} 를 더함')

    a = 0


    count += (dic[node] - 1)
    for i in dic[node]:
        if not visited[i]:
            if len(dic[i]) == 1: 
                count += (N - 1)
                a += 1
            else:
                tmp = dfs(i, layer + 1)
                a += tmp
                count += ((N - 1) * tmp) - (tmp * (tmp - 1)) // 2
    
    return a

dfs(1, 1)
print(count)
