import sys

file = open('mathmatics.txt', 'r')
sys.stdin = file

test_case = int(input())
for num in range(test_case):
    long, short = map(int, input().split())
    lst = list(map(int, input().split()))

    max_sum = partial_sum = sum(lst[:short])
    for _ in range(long - short):
        partial_sum -= lst[_]
        partial_sum += lst[short + _ ]
        if partial_sum > max_sum:
            max_sum = partial_sum
    print(max_sum)
