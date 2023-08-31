import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

M, N = map(int,input().split())

lst = [list(input()) for _ in range(N)]
visited = [[0] * M for _ in range(N)]
print(lst)
print(visited)
W_power = 0
B_power = 0



def search(id):
    # print(queue, id)
    if id >= len(queue):
        return 0
    idx = queue[id]
    print(idx)
    visited[idx[0]][idx[1]] = 1

    for i in [[idx[0] + i[0], idx[1] + i[1]] for i in [[-1, 0], [1, 0], [0, 1], [0, -1]] 
    if 0 <= idx[0] + i[0] < N
    if 0 <= idx[1] + i[1] < M
    if lst[idx[0]  + i[0]][idx[1] + i[1]] == lst[idx[0]][idx[1]]
    if not visited[idx[0]  + i[0]][idx[1] + i[1]]]:
        visited[i[0]][i[1]] = 1
        queue.append(i)


    return search(id + 1) + 1

    
for i in range(N):
    for j in range(M):
        if not visited[i][j]:
            visited[i][j] = 1
            queue = [[i, j]]
            local = search(0)
            if lst[i][j] == 'W':
                W_power += local ** 2
            else:
                B_power += local ** 2
                
print(W_power, B_power)