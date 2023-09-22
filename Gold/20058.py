import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
st = sys.stdin.readline

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
    # print(lg, kan)
    if lg == 1:
        pass
    
    for i in range(lg):
        for j in range(lg):
            bx = kan * i
            by = kan * j
            for k in range(kan):
                for p in range(kan - k):
                    lst[bx + k][by + p], lst[bx + kan - 1 - p][by + k] = lst[bx + kan - 1 - p][by + k], lst[bx + k][by + p]

            gone = []
            for k in range(kan):
                for p in range(kan):
                    ct = 0
                    for w in range(4):
                        nx, ny = bx + k + dx[w], by + p + dy[w]
                        if 0 <= nx < 2 ** N and 0 <= ny < 2 ** N and lst[nx][ny]:
                            ct += 1
                    if ct < 3:
                        gone.append((k, p))
            print(i, j, gone)
            # for arg in gone:
            #     if lst[bx + arg[0]][by + arg[1]]:
            #         lst[bx + arg[0]][by + arg[1]] -= 1

 
                
for _ in L:
    magic(_)

print(*lst, sep= '\n')

    # 움직이는 애들의 칸

# i 번째 열을 n - i 번째 행으로 바꿔주기만 하면됨.




# 총 몇개니 ? 
# L이 1일때는 
