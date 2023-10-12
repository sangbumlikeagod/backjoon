import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
from collections import deque
N = int(st())

CURRENT = list(map(int, st().strip()))
DESIRE = list(map(int, st().strip()))

is_testing = False
if is_testing:
    print(CURRENT)

ct = 0

def change(i):
    if i != 0:
        CURRENT[i - 1] = int(not CURRENT[i - 1])
    if i != N - 1:
        CURRENT[i + 1] = int(not CURRENT[i + 1])
    CURRENT[i] = int(not CURRENT[i])

past = -1
que = deque()

while CURRENT != DESIRE:
    # print(CURRENT)
    max_a, max_b = 1, 0
    max_i = -1
    for i in range(N):
        a, b = 0, 0
        if i != 0:
            a += 1
            if CURRENT[i - 1] != DESIRE[i - 1]:
                b += 1
        if i != N - 1:
            a += 1
            if CURRENT[i + 1] != DESIRE[i + 1]:
                b += 1
        a += 1
        if CURRENT[i] != DESIRE[i]:
            b += 1
        if b / a > max_b / max_a and i != past:
            max_a = a
            max_b = b
            max_i = i
            if b == 3:
                break
        elif  b / a == max_b / max_a and i != past:
            if a >= max_a:
                max_a = a
                max_b = b
                max_i = i
    change(max_i)
    print(max_i, past, CURRENT)
    past = max_i
    ct += 1

print(ct)