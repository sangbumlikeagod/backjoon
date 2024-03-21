import sys
sys.stdin = open('10989.txt','r')
st = sys.stdin.readline

N = int(st())
# print(N)
lst = [0] * 10001
for i in range(N):
    # a = int(st())
    lst[int(st())] += 1

# print(lst)
for p in range(1, 10001):
    for _ in range(lst[p]):
        print(p)

