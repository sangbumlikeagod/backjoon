import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

N = int(st())

dic = {
    1 : 1,
    0 : 1
}

def dp(n):
    if n in dic:
        pass
    else:
        dic[n] = dp(n - 1) +  dp(n - 2)
    return dic[n]

print(dp(N))