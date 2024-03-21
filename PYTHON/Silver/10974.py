import sys
sys.setrecursionlimit(10000)
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

N = int(input())

def permu(num, lst):
    if not num:
        print(' '.join(lst))

    for i in range(N):
        if num & 1 << i:
            permu(num - (1 << i), lst + [str(i + 1)])
    return 

permu(2 ** N - 1, [])
