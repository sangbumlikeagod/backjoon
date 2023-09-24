import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(30000)
N = int(input())

dic = {
    0 : 0,
    1 : 1
}
def fibo(N):
    if N in dic:
        return dic[N]
    else:
        dic[N] = fibo(N - 1) + fibo(N - 2)
        dic.pop(N - 2)
    return dic[N]

# for i in range(1, 18):
    # print(fibo(i))

# for i in range(1, N + 1):
print(fibo(N) % 1000000007)
# print(dic)


dic = {
    0 : (0.5, 0.5)
    }

for i in range(1, N + 1):
    n = 0
    start = None
    while 1 << n <= i:
        if n not in dic:
            a, b = dic[n - 1]
            dic[n] = ((a ** 2 + 5 * b ** 2) % 1000000007, (2 * a * b) % 1000000007)
        if 1 << n & i:
            if not start:
                start = dic[n]
            else:
                start = ((start[0] * dic[n][0] + start[1] * dic[n][1] * 5)  % 1000000007, (dic[n][0] * start[1] + dic[n][1] * start[0]) % 1000000007 )
                    
        n += 1
    # print(int(start[1] * 2))
# print(dic)