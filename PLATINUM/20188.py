import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

st = sys.stdin.readline

N = int(st())
dic = {}
lst = [0] * (N + 1)
lst[1] = {1}

for i in range(N - 1):
    a, b = map(int, st().split())
    dic[a] = dic.get(a, []) + [b]
    dic[b] = dic.get(b, []) + [a]
# print(dic)

from collections import deque
count = 0
que = deque()
que.append(1)

prev = 0
while que:
    next = que.popleft()
    
    for i in dic[next]:
        if not lst[i]:
            # print(next, i)
            que.append(i)
            lst[i] = lst[next] | {i}
            count += len(lst[i]) - 1
    prev = next
    # print(que)
# print(lst)
# print(count)

for i in range(2, N):
    for j in range(i + 1, N + 1):
        count += len(lst[i] | lst[j]) - 1
# print(dic)
print(count)
        
    