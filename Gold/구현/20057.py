import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
st = sys.stdin.readline

N = int(st())
table = [list(map(int, st().split())) for _ in range(N)]
total = 0
for i in range(N):
    total += sum(table[i])

#좌, 하, 우, 상 순으로 2칸마다 크기가 커지게
[]
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
x = N // 2
y = N // 2
strength = 1
ct = 0
out = 0
spray_lst_x = [-1, -1, -1, -2,  0,  1, 1, 1, 2, 0]
spray_lst_y = [1,   0, -1,  0,  2, -1, 0, 1, 0, 1]
odd = [0.1, 0.07, 0.01, 0.02,  0.05, 0.01, 0.07, 0.1, 0.02, 1]
# print(sum(odd))
# 아래로 갈 경우에는 둘이 바꿔주면 됨

'''
x 를 기준으로 
-1 0 이 있으면 안되지

'''
while 0 <= y:
    # table[x][y] = '*'
    # print(x, y, strength)

    tmp = 1
    while tmp <= strength:
        # print()
        # print(*table, sep= '\n')
        # print()
        nx = x + dx[ct] * tmp
        ny = y + dy[ct] * tmp
        if 0 <= nx < N and 0 <= ny < N:
            # print(nx, ny)
            if table[nx][ny]:
                remain = table[nx][ny]
                if not dy[ct]:
                    spray_lst_x, spray_lst_y = spray_lst_y, spray_lst_x

                    for i in range(10):


                        vx = spray_lst_x[i]
                        vy = spray_lst_y[i]
                        if dx[ct] == -1:
                            vx *= -1
                            vy *= -1

                        bx, by = nx + vx, ny + vy
                        if 0 <= bx < N and 0 <= by < N:
                            if i == 9:
                                table[bx][by] += remain
                            else:
                                table[bx][by] += int(table[nx][ny] * odd[i])
                                remain -= int(table[nx][ny] * odd[i])
                        else:
                            remain -= int(table[nx][ny] * odd[i])
                    spray_lst_x, spray_lst_y = spray_lst_y, spray_lst_x
                else:
                    for i in range(10):
                        vx = spray_lst_x[i]
                        vy = spray_lst_y[i]
                        if dy[ct] == -1:
                            vx *= -1
                            vy *= -1
                        bx, by = nx + vx, ny + vy
                        if 0 <= bx < N and 0 <= by < N:
                            if i == 9:
                                table[bx][by] += remain
                            else:
                                table[bx][by] += int(table[nx][ny] * odd[i])
                                remain -= int(table[nx][ny] * odd[i])
                        else:
                            remain -= int(table[nx][ny] * odd[i])
        table[nx][ny] = 0
        tmp += 1
    # table[x][y] = 0
    x, y = nx, ny
    ct += 1
    if ct == 2 or ct == 4:
        strength += 1
    # if ct == 4:
    #     break
    ct %= 4
table[x][y] = 0

# print(total)
for i in range(N):
    total -= sum(table[i])
print(total)


# print(int(1.93))