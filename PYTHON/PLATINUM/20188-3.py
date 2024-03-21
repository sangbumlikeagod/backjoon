import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
st = sys.stdin.readline

N = int(st())
dic = {}
lst = [0] * (N + 1)
lst[1] = (1, 0)

for i in range(N - 1):
    a, b = map(int, st().split())
    dic[a] = dic.get(a, []) + [b]
    dic[b] = dic.get(b, []) + [a]
# print(dic)

from collections import deque
count = 0
que = deque()
que.append((1, 0))


while que:
    next, ct = que.popleft()
    
    for i in dic[next]:
        if not lst[i]:
            # print(next, i)
            que.append((i, ct + 1))
            lst[i] = (next, ct + 1)
            count += ct + 1
    prev = next

# print(lst, count)
# 약;사 

for i in range(2, N):
    for j in range(i + 1, N + 1):
        i_c, j_c = i, j
        set_t = {1}
        while True:
            # print(i_c, j_c)
            if i_c != 1:
                if i_c in set_t:
                    count += lst[i][1] + lst[j][1] - lst[i_c][1]
                    break
                set_t.add(i_c)
                i_c = lst[i_c][0]
            if j_c != 1:
                if j_c in set_t:
                    count += lst[i][1] + lst[j][1] - lst[j_c][1]
                    break
                set_t.add(j_c)
                j_c = lst[j_c][0]
            if i_c == 1 and j_c == 1:
                count += lst[i][1] + lst[j][1]
                break
print(count)