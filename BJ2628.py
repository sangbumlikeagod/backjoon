

# 힙큐 어떻게 만드는 질 알고싶다
import sys
file = open('BJ2628.txt', 'r', encoding='utf-8')
sys.stdin = file


def sort_store(idx, lst, inp):
    if idx == len(lst):
        lst.append(inp)
        return lst
    if lst[idx] > inp:
        return lst[:idx] + [inp] + lst[idx:]
    else:
        return sort_store(idx + 1, lst, inp)


row, column = map(int, input().split())
row_lst = [0, row]
column_lst = [0, column]

num_of_cut = int(input())

for i in range(num_of_cut):
    is_column, div = map(int, input().split())
    if not is_column:
        column_lst = sort_store(0, column_lst, div)
    else:
        row_lst = sort_store(0, row_lst, div)
# print(column_lst, row_lst)
max_diff_column = 0
for i in range(len(column_lst) - 1):
    if max_diff_column < column_lst[i + 1] - column_lst[i]:
        max_diff_column = column_lst[i + 1] - column_lst[i]
max_diff_row = 0
for i in range(len(row_lst) - 1):
    if max_diff_row < row_lst[i + 1] - row_lst[i]:
        max_diff_row = row_lst[i + 1] - row_lst[i]

print(max_diff_row * max_diff_column)
