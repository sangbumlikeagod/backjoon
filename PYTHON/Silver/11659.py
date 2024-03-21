import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
from itertools import accumulate
N, testcase = map(int, st().split())

num = list(accumulate(list(map(int, st().split()))))
# print(num)
for _ in range(testcase):
    fr, to = map(int, st().split())
    if fr - 2 >= 0:
        print(num[to - 1] - num[fr - 2])
    else:
        print(num[to - 1])