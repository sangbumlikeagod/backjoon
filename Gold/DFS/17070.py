import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')



import sys
st = sys.stdin.readline
N = int(st())

lst = []
for i in range(N):
    lst.append(list(map(int, input().split())))

dic = {
    0 : [(0, 1), (1, 1)],
    1 : [(1, 0), (1, 1)],
    2 : [(1, 0), (1, 1), (0, 1)]
}
visited = [[[-1] * N for _ in range(N)] for _ in range(3)]
# print(*visited , sep='\n')

ans = 0

def search(x, y, state):

    global ans
    if x == N - 1 and y == N - 1:
        global ans
        ans += 1
        return 1
    local = 0
    for delta in dic[state]:
        # print(delta)
        if delta[0]:
            if delta[1]:
                nx, ny = x + 1, y + 1
                new_state = 2
                if 0 <= nx < N and 0 <= ny < N:
                    if visited[new_state][nx][ny] != -1:
                        local += visited[new_state][nx][ny]
                        continue
                    if lst[x + 1][y] + lst[x][y + 1] + lst[nx][ny]:
                        continue
                else: continue
            else:
                nx, ny = x + 1, y
                new_state = 1
                if 0 <= nx < N and 0 <= ny < N:
                    if visited[new_state][nx][ny] != -1:
                        local += visited[new_state][nx][ny]
                        continue
                    if lst[nx][ny]:
                        continue
                else: continue
        else:
            nx, ny = x, y + 1
            new_state = 0
            if 0 <= nx < N and 0 <= ny < N:
                if visited[new_state][nx][ny] != -1:
                    local += visited[new_state][nx][ny]
                    continue
                if lst[nx][ny]:
                    continue
            else: continue
        local += search(nx, ny, new_state)
    visited[state][x][y] = local
    return local
        

        
search(0, 1, 0)
print(visited[0][0][1])

# for i in visited:
#     print( *i, sep='\n')
#     print()