
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

case = int(input())
dic = {}
for num in range(case):
    sqr_now = list(map(int, input().split()))
    area = set([i * 1001 + j for i in range(sqr_now[0], sqr_now[0] + sqr_now[2]) for j in range(sqr_now[1], sqr_now[1] + sqr_now[3]) ])
    for i in dic:
        dic[i] = dic[i] - (dic[i] & area)
    dic[num + 1] = area

for key in dic:
    print(len(dic[key]))

