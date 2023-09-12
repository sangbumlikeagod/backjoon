



import sys


name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r')
sys.stdin = file

charmwae = int(input())

dic = {}
cord = [0, 0]
result = []
x_lst = []
y_lst = []
for _ in range(6):
    mode, distance = map(int, input().split())

    mode -= 1
    cord_co = cord[:]
    if mode % 2:
        distance *= -1
    cord_co[mode // 2] += distance
    result.append(cord_co)
    cord = cord_co
    if cord[0] not in x_lst:
        x_lst.append(cord[0])
    if cord[1] not in y_lst:
        y_lst.append(cord[1])
    x_lst.sort()
    y_lst.sort()





print(x_lst, y_lst)
bigone = 0
smallone = 0

#
# for i in result:
#


#
# for num in range(test_case):
#     return_value = 0




    #
    #
    # print(f'#{num + 1} {return_value}')

# 1 2 3 4 동 서 남 북
# 무조건 동북을 양으로 잡고 ( 나머지가 0 이어야 +  1이면 - )
# 몫이 같은게 같은 방향

# 너무 힙하게 풀려하지 마셈
# 6개의 좌표를 주면 그 사각형 넓이를 구할 수 있나 ?