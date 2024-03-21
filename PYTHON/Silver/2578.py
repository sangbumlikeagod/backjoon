import sys


name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r')
sys.stdin = file
test_case = 1


# for num in range(test_case):
#     return_value = 1
#     bingo_dic = {}
#     for _ in range(5):
#         lst = list(map(int, input().split()))
#         for j in range(5):
#             bingo_dic[lst[j]] = (_, j)
#
#     print(bingo_dic)
#     order_num = []
#     for i in range(5):
#         order_num += list(map(int, input().split()))
#
#     dic_count = {}
#     count = 0
#
#     for arg in order_num:
#         dic_count[(bingo_dic[arg][0], 0)] = dic_count.get((bingo_dic[arg][0], 0), 0) + 1
#         if dic_count[(bingo_dic[arg][0], 0)] == 5:
#             count += 1
#         dic_count[(0, bingo_dic[arg][1])] = dic_count.get((0, bingo_dic[arg][1]), 0) + 1
#         if dic_count[(0, bingo_dic[arg][1])] == 5:
#             count += 1
#         if bingo_dic[arg][0] == bingo_dic[arg][1]:
#             dic_count['di'] = dic_count.get('di', 0) + 1
#             if dic_count['di'] == 5:
#                 count += 1
#         if bingo_dic[arg][0] + bingo_dic[arg][1] == 4:
#             dic_count['exdi'] = dic_count.get('exdi', 0) + 1
#             if dic_count['exdi'] == 5:
#                 count += 1
#         return_value += 1
#         if count == 3:
#             print(f'#{num + 1} {return_value}')
#             break



return_value = 0
bingo_dic = {}
for _ in range(5):
    lst = list(map(int, input().split()))
    for j in range(5):
        bingo_dic[lst[j]] = (_, j)


order_num = []
for i in range(5):
    order_num += list(map(int, input().split()))


dic_count = {}
count = 0

for arg in order_num:
    return_value += 1
    dic_count[(bingo_dic[arg][0], 0)] = dic_count.get((bingo_dic[arg][0], 0), 0) + 1
    if dic_count[(bingo_dic[arg][0], 0)] == 5:
        count += 1
    if count == 3:
        print(return_value)
        break
    dic_count[(-1, bingo_dic[arg][1])] = dic_count.get((-1, bingo_dic[arg][1]), 0) + 1
    if dic_count[(-1, bingo_dic[arg][1])] == 5:
        count += 1
    if count == 3:
        print(return_value)
        break
    if bingo_dic[arg][0] == bingo_dic[arg][1]:
        dic_count['di'] = dic_count.get('di', 0) + 1
        if dic_count['di'] == 5:
            count += 1
        if count == 3:
            print(return_value)
            break
    if bingo_dic[arg][0] + bingo_dic[arg][1] == 4:
        dic_count['exdi'] = dic_count.get('exdi', 0) + 1
        if dic_count['exdi'] == 5:
            count += 1
        if count == 3:
            print(return_value)
            break
    1
    if count == 3:
        print(return_value)
        break
print(dic_count)