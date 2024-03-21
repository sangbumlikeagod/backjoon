import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
from itertools import accumulate

N, M = map(int, st().split())


pann = []
for _ in range(N):

    # lst = list(accumulate(list(map(int, st().split()))))

    pann.append(list(accumulate(list(map(int, st().split())))))

# print(pann)
for _ in range(M):
    x1, y1, x2, y2 = map(int, st().split())
    x1 -= 1
    x2 -= 1
    y1 -= 1
    y2 -= 1

    ans = 0
    for i in range(x1, x2 + 1):
        if y1 - 1 >= 0:
            ans += pann[i][y2] - pann[i][y1 - 1]
        else:
            ans += pann[i][y2]
    print(ans)