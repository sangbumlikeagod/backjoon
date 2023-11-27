import sys


name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r')
sys.stdin = file
test_case = int(input())


for num in range(test_case):
    size = int(input())
    lst = list(map(int, input().split()))
    lst.sort()

    i = 0
    j = size - 1
    local = [0, size - 1]
    while i < j:
        if abs(lst[i] + lst[j]) <= abs(lst[local[0]] + lst[local[1]]):
            local = [i, j]

        if lst[i] + lst[j] == 0:
            local = [i, j]
            break
        elif lst[i] + lst[j] < 0:
            i += 1
            continue
        else:
            j -= 1


    print(f'{lst[local[0]]} {lst[local[1]]}')

