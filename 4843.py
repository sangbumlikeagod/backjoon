
# import sys
# file = open('4843.txt', 'r')
# sys.stdin = file 


test_case = 1

def selecting_sort(lst):
    print(lst)
    if len(lst) <= 1:
        return lst
    elif len(lst) == 2:
        if lst[0] < lst[1]:
            lst[0], lst[1] = lst[1], lst[0]
    
    
    min_idx = 0
    max_idx = 0
    for idx in range(len(lst)):
        if lst[idx] > lst[max_idx]:
            max_idx = idx
        if lst[idx] < lst[min_idx]:
            min_idx = idx
    lst[min_idx], lst[1] = lst[1], lst[min_idx]
    lst[max_idx], lst[0] = lst[0], lst[max_idx]
    print(lst)
    return lst[0:2] + selecting_sort(lst[2:])
    

for num in range(test_case):
    str_1 = '67 39 16 49 60 28 8 85 89 11'
    lst = list(map(int,str_1.split()))
    sorted_lst = selecting_sort(lst)[:10]
    print(" ".join(map(str, sorted_lst)))
    # print(f'#{num + 1} {" ".join(selecting_sort(lst)[:10])}')