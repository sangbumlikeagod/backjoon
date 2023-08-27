# 저 육각형을 모양에 따라 다르게 해야한다 
# 넓이를 구하는 문제는 좌표나 거리가 필요한데 어떤 좌표든 어떤 믿을놈이 못된다는 것 


import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(100000)


max_h = 0
min_h = 500
max_v = 0
min_v = 500
lst1 = [max_v, min_v]
lst2 = [max_h, min_h]
dic_max = {1 : lst1,
           2 : lst1,
           3 : lst2,
           4 : lst2}
lst = []
banana = int(input())
for test in range(6):
    dir, val = map(int, input().split())
    lst.append(((dir - 1) // 2, val))
max_v_idx = 0
max_v = 0
for i in range(0, 6):
    if not lst[i][0] and max_v < lst[i][1]:
        max_v = lst[i][1]
        max_v_idx = i
max_h_idx = 0
max_h = 0

for i in range(0, 6):
    if lst[i][0] and max_h < lst[i][1]:
        max_h = lst[i][1]
        max_h_idx = i

# print(lst, max_v_idx, max_h_idx)
min_v = (max_h_idx + 3) % 6
min_h = (max_v_idx + 3) % 6
# print(min_v, min_h)
print(banana * (lst[max_h_idx][1] * lst[max_v_idx][1] - lst[min_h][1] * lst[min_v][1])) 

        # print(min_max)
    # if dic_max[dir][0] < val:
    #     dic_max[dir][0] = val
    # elif dic_max[dir][1] > val:
    #     dic_max[dir][1] = val
# print(dic_max)
# print(banana * (dic_max[1][0] * dic_max[3][0] -  dic_max[1][1] * dic_max[3][1] ) )        

# 상대적인 위치로 알 수 있나 ? 아니오 
# 상대방의 상대적인 위치를 통해서 알 수 있음 
# 제일 큰놈 다음에 나오는 놈의 다음타자 
