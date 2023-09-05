
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(100000)


N = int(input())
lst = [input() for _ in range(N)]
# print(lst)
visited = [[0] * N for _ in range(N)]
def bfs(que, que_idx):
    # print(que)
    if que_idx > len(que) - 1:
        return 0
    
    idx = que[que_idx]
    for i in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
        if 0 <= idx[0] + i[0] < N and \
            0 <= idx[1] + i[1] < N and\
            not visited[idx[0] + i[0]][idx[1] + i[1]] and\
            lst[idx[0] + i[0]][idx[1] + i[1]] == '1':
            visited[idx[0] + i[0]][idx[1] + i[1]] = 1
            que.append([idx[0] + i[0], idx[1] + i[1]])
    return bfs(que, que_idx + 1) + 1

retu = 0
ans_lst = []
for i in range(N):
    for j in range(N):
        if lst[i][j] == '1' and not visited[i][j]:
            visited[i][j] = 1
            ans_lst.append(bfs([[i, j]], 0))
            retu += 1
# print(*visited, sep=' \n')
ans_lst.sort()
print(retu)
print(*ans_lst, sep = '\n')

