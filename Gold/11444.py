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
print(fibo(N) % 1000000007)
# print(dic)

def fibo_generic(num):
    if num == 1:
        return (0.5, 0.5)
    elif num % 2:
        tmp = fibo_generic(num - 1)
        return (0.5 * tmp[0] + 0.5 * tmp[1] * 5 , 0.5 * tmp[0] + 0.5 * tmp[1])
    else:
        tmp = fibo_generic(num // 2)
        return (tmp[0] ** 2 + tmp[1] ** 2 * 5, tmp[0] * tmp[1] * 2)

res = fibo_generic(3)
print(res)
print(4 * res[0] * res[1] % 1000000007)