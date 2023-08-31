import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

N, M = map(int, input().split())
maze = [list(map(int, list(input()))) for _ in range(N) ]
visited = [[0] * M for _ in range(N)]
# print(maze)

# import heapq

# heap = []
# idx = [0, 0]

# for i in [[0 + i[0], 0 + i[1]] for i in [[1, 0], [0, 1]] \
#     if maze[0 + i[0]][0 + i[1]]]:
#     heapq.heappush(heap, (2, i))

# print(heap)
# while  idx != [N - 1, M -1]:
#     ssum, idx = heapq.heappop(heap)
#     visited[idx[0]][idx[1]] = 1
#     # print(ssum, idx)
#     for k in [[idx[0] + i[0], idx[1] + i[1]] for i in [[-1, 0], [1, 0], [0, 1], [0, -1]] \
#     if 0 <= idx[0] + i[0] < N
#     if 0 <= idx[1] + i[1] < M
#     if not visited[idx[0]  + i[0]][idx[1] + i[1]]
#         if maze[idx[0]  + i[0]][idx[1] + i[1]]]:
#             heapq.heappush(heap, (ssum + 1, k))
    
# print(ssum)

queue = [(1, (0, 0))]

def  bfs(id):
    
    summ, idx = queue[id]
    # print(idx)

    if idx == [N - 1, M - 1]:
        return summ

    for i in [[idx[0] + i[0], idx[1] + i[1]] for i in [[-1, 0], [1, 0], [0, 1], [0, -1]] 
         if 0 <= idx[0] + i[0] < N
    if 0 <= idx[1] + i[1] < M
    if maze[idx[0]  + i[0]][idx[1] + i[1]]
    if not visited[idx[0]  + i[0]][idx[1] + i[1]]]:
        visited[i[0]][i[1]] = 1
        queue.append((summ+1 ,i))

    return bfs(id + 1)



print(bfs(0))
        
    