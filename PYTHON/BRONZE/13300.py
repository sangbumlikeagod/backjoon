
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

dic_lst = [{}, {}]
N, M = map(int,input().split())
counter = [0] * 12
for i in range(N):
    stu = list(map(int,input().split()))

    counter[stu[0] * 6 + stu[1] - 1] += 1
    dic_lst[stu[0]][stu[1]] = dic_lst[stu[0]].get(stu[1], 1)
    if counter[stu[0] * 6 + stu[1] - 1] == M + 1:
        dic_lst[stu[0]][stu[1]] +=1
        counter[stu[0] * 6 + stu[1] - 1] = 1

retu = 0
# for i in counter:

for i in dic_lst:
    # print(i)
    for j in i:
        retu += i[j]

print(retu)

