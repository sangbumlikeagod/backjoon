import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(10000)

V, E  = map(int, input().split())

visited = [0] * (V + 1)
dic = {}
for i in range(E):
    a, b = map(int,input().split())
    dic[a] = dic.get(a, []) + [b]
    dic[b] = dic.get(b, []) + [a]
    
# print(dic)
    

def bfs(que, ind):
    if ind > len(que) - 1:
        return
    next = que[ind]
    if next in dic:
        for i in dic[next]:
            if not visited[i]:
                visited[i] = 1
                que.append(i)
    return bfs(que, ind + 1)
      
return_value = 0  
for i in range(1, V + 1):
    if not visited[i]:
        visited[i] = 1
        bfs([i], 0)
        return_value += 1
    
    print(visited)
print(return_value)