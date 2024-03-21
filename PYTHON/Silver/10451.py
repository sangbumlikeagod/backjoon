
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(10000)

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

testcase = int(sys.stdin.readline())
for i in range(testcase):
    V = int(sys.stdin.readline())
    lst = list(map(int, sys.stdin.readline().split()))
    
    visited = [0] * (V + 1)
    dic = {}
    for a, b in enumerate(lst):
        dic[a + 1] = dic.get(a + 1, []) + [b]
    # print(dic)
    return_value = 0
    for i in range(1, V + 1):
        if not visited[i]:
            visited[i] = 1
            bfs([i], 0)
            return_value += 1
        # print(visited)

    print(return_value)
    
    
