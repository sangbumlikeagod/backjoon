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
# que.append((1, {}))
que.append((1, {}))
while que:
    print(que)
    next, popu = que.popleft()
    # 딕셔너리에서 받기
    popu = popu.copy()
    for i in popu:
        if i != next:
            popu[i] += 1
            count += popu[i]

    # 자식을 담은 딕셔너리 전달하기
    print(next, popu, count)

    for i in dic[next]:
        if i not in popu:
            popu[i] = 1
    popu[next] = 0

    for i in dic[next]:
        if not lst[i]:
            que.append((i, popu))
            lst[i] = 1
    prev = next
# while que:
#     next, ct = que.popleft()
    
#     for i in dic[next]:
#         if not lst[i]:
#             # print(next, i)
#             que.append((i, ct + 1))
#             lst[i] = (next, ct + 1)
#             count += ct + 1
#     prev = next

# print(lst, count)

# 발견하면 거기까지간 모든 애들 메모리제이션에 넣는것 생각해봄
# 문제는 이게 최대 레벨이 1일때는 상관이 없다는거 그래서 100점 맞을 수는 없어보임

# overlap = {}
# for i in range(2, N):
#     for j in range(i + 1, N + 1):
#         i_c, j_c = i, j
#         set_t = {1}
#         while True:
#             # print(i_c, j_c)
#             if (i_c,j_c) in overlap:
#                 print( (i_c,j_c), (i,j ))
#                 overlap[(i, j)] = overlap[(i_c, j_c)] + (lst[i][1] - lst[i_c][1]) +  (lst[j][1] - lst[j_c][1])
#                 count +=  overlap[(i, j)]
#                 break
            
#             if i_c != 1:
#                 if i_c in set_t:
#                     overlap[(i, j)] = lst[i][1] + lst[j][1] - lst[i_c][1]
#                     count += lst[i][1] + lst[j][1] - lst[i_c][1]
#                     break
#                 set_t.add(i_c)
#                 i_c = lst[i_c][0]

#             if (i_c, j_c) in overlap:
#                 print( (i_c,j_c), (i,j ))
#                 overlap[(i, j)] = overlap[(i_c, j_c)] + (lst[i][1] - lst[i_c][1]) +  (lst[j][1] - lst[j_c][1])
#                 count +=  overlap[(i, j)]
#                 break

#             if j_c != 1:
#                 if j_c in set_t:
#                     overlap[(i, j)] = lst[i][1] + lst[j][1] - lst[j_c][1]
#                     count += overlap[(i, j)] 
#                     break
#                 set_t.add(j_c)
#                 j_c = lst[j_c][0]

#             if i_c == 1 and j_c == 1:
#                 overlap[(i, j)] = lst[i][1] + lst[j][1]
#                 count += overlap[(i, j)]
#                 break

print(count)
print(overlap)
# print(dic)
# print(count)
        
    