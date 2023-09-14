import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
st = sys.stdin.readline

N = int(st())
dic = {}
for i in range(N - 1):
    a, b = map(int, st().split())
    dic[a] = dic.get(a, []) + [b]
    dic[b] = dic.get(b, []) + [a]
print(dic)

visited = [0] * (N + 1)
def dfs(node, layer, forbrother): 
    visited[node] = 1
    print(node, layer, forbrother)
    brother = 0
    for_return = 0
    for_this_brother = 0
    for i in dic[node]:
        if not visited[i]:
            forparent, forb = dfs(i, layer + 1, forbrother + for_this_brother)
            for_this_brother += forb
            for_return += forparent + layer + 1
            brother += 1
    return (for_return, brother)

print(dfs(1, 0, 0))

