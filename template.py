import sys

file = open('', 'r')
sys.stdin = file

long, short = map(int, input().split())
lst = list(map(int, input().split()))

max_sum = partial_sum = sum(lst[:short])
for _ in range(long - short):
    partial_sum -= lst[_]
    partial_sum += lst[short + _ ]
    if partial_sum > max_sum:
        max_sum = partial_sum
print(max_sum)
