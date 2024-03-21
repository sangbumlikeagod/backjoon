import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')


st = sys.stdin.readline
import sys
sys.setrecursionlimit(10000)
'''
0부터 시작해서 L에 따라서 시작의 부분집합이 커지는데 
2 ** L 칸 단위로 움직이면서 

다음칸으로 간다를 해석할 수 있으면 
델타도 해야한다.

'''

N, Q = map(int, input().split())


lst = [list(map(int, input().split())) for _ in range( 2 ** N )]
# print(lst)
# i번째 행 j번째 칸이 이 n - i 번째 열 j번째 칸이 되면된다. n * n 행렬에서 ?
# 2, 2  [3 - 2] 2
L = list(map(int, input().split()))

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]


def magic(num):
    # 인덱스상 칸
    lg = 2 ** (N - num)
    kan = 2 ** num

    
    for i in range(lg):
        for j in range(lg):
            bx = kan * i
            by = kan * j
            tmp = [[-1] * kan for _ in range(kan)]
            for k in range(kan):
                for p in range(kan):
                    # 간단하게 0번째 행이 n - 1번째 열로 바뀌는거야 
                    tmp[p][kan - 1 - k] =lst[bx + k][by + p]
            for k in range(kan):
                for p in range(kan):
                    lst[bx + k][by + p] = tmp[k][p]
    gone = []
    for k in range(2 ** N):
        for p in range(2 ** N):
            if lst[k][p]:
                ct = 0
                for w in range(4):
                    nx, ny = k + dx[w], p + dy[w]
                    if 0 <= nx < 2 ** N and 0 <= ny < 2 ** N and lst[nx][ny]:
                        ct += 1
                if ct < 3:
                    gone.append((k, p))

    for arg in gone:
        if lst[arg[0]][arg[1]]:
            lst[arg[0]][arg[1]] -= 1

 
                
for _ in L:
    magic(_)
    # print(_)
    # print(*lst, sep= '\n')
    # print()

total = 0
maxx = 0
for row in lst:
    for col in row:
        if col > maxx:
            break
    break
    # 움직이는 애들의 칸

# i 번째 열을 n - i 번째 행으로 바꿔주기만 하면됨.

visited = [ [0] * 2 ** N for _ in range( 2 ** N ) ]
# print(visited)
total = 0
def dfs(x, y):
    global total
    ct = 1

    total += lst[x][y]
    for w in range(4):
        nx, ny = x + dx[w], y + dy[w]
        if 0 <= nx < 2 ** N and 0 <= ny < 2 ** N and lst[nx][ny] and not visited[nx][ny]:
            visited[nx][ny] = 1
            ct += dfs(nx, ny)
    return ct

maxx = 0
for row in range(2 ** N):
    for col in range(2 ** N):
        if not visited[row][col] and lst[row][col]:
            visited[row][col] = 1
            maxx =max(dfs(row, col), maxx)
            
print(total)
print(maxx)
            


            


# 총 몇개니 ? 
# L이 1일때는 
