# inp1 = int('834')
# inp2 = '42 68 35 1 70 25 79 59 63 65 6 46 82 28 62 92 96 43 28 37 92 5 3 54 93 83 22 17 19 96 48 27 72 39 70 13 68 100 36 95 4 12 23 34 74 65 42 12 54 69 48 45 63 58 38 60 24 42 30 79 17 36 91 43 89 7 41 43 65 49 47 6 91 30 71 51 7 2 94 49 30 24 85 55 57 41 67 77 32 9 45 40 27 24 38 39 19 83 30 42'

import sys
f = open('../input.txt', 'r', encoding='utf-8')
test_case = 10
sys.stdin = f




for i in range(test_case):
    inp1 = int(input())
    inp2 = list(map(int, input().split()))
    dic = {}
    for element in inp2:
        dic[element] = dic.get(element, 0) + 1

    counts = [0] * 101
    for dic_ele in dic:
        counts[dic_ele] = dic[dic_ele]
    counts = [sum(counts[:i]) for i in range(1, len(counts) + 1)]
    # print(counts)
    sorted_inp2 = [0] * len(inp2)
    while inp2:
        arg = inp2.pop()
        position = counts[arg]
        sorted_inp2[position - 1] = arg
        counts[arg] -= 1

    while inp1 > 0:
        sorted_inp2[-1] -= 1
        sorted_inp2[0] += 1
        start = 0
        last = -1
        while sorted_inp2[start] > sorted_inp2[start + 1]:
            sorted_inp2[start], sorted_inp2[start + 1] = sorted_inp2[start + 1], sorted_inp2[start]
            start += 1
        while sorted_inp2[last] < sorted_inp2[last - 1]:
            sorted_inp2[last], sorted_inp2[last - 1] = sorted_inp2[last - 1], sorted_inp2[last]
            last -= 1
        inp1 -= 1
    print(f'#{i + 1} {sorted_inp2[-1] - sorted_inp2[0]}')





