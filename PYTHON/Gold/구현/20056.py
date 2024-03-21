import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

N, M, K = map(int, input().split())
# print(M)
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]

# 딕셔너리에 넣고 이동해 
dic = {}


# 테이블은 여러개를 받을 수 있게 해놔야함 
# 4개로 쪼개지면 여러개가 될거니까
# 새로운좌표들로 갱신한다음에 다 옮겨버릴거야 

total = 0
for i in range(M):
    x, y, m, s, d = map(int, input().split())
    dic[(x, y)] = dic.get((x, y), []) + [(m, s, d)]
    total += m

for _ in range(K):
    new_dic = {}
    overlap = set()
    # print(dic)
    for cord in dic:
        while dic[cord]:
            m, s, d = dic[cord].pop()
            nx, ny = (cord[0] + dx[d] * s) % N, (cord[1] + dy[d] * s) % N
            if (nx, ny) in new_dic:
                overlap.add((nx, ny))
            new_dic[(nx, ny)] = new_dic.get((nx, ny), []) + [(m, s, d)]
    # print(overlap, new_dic)
    for ov in overlap:
        ct = 0
        tmp = []
        t_m, t_l, n_d = 0, 0, 0
        while new_dic[ov]:
            m, s, d = new_dic[ov].pop()
            n_d += d % 2
            t_m += m
            t_l += s
            ct += 1

        total -= t_m
        t_m = t_m // 5
        total += t_m * 4
        t_l = t_l // ct
        if t_m:
            if n_d == 0 or n_d == ct: 
                tmp += [(t_m, t_l, 0), 
                        (t_m, t_l, 2),
                        (t_m, t_l, 4),
                        (t_m, t_l, 6)]
            else:
                tmp += [(t_m, t_l, 1), 
                        (t_m, t_l, 3),
                        (t_m, t_l, 5),
                        (t_m, t_l, 7)]
        new_dic[ov] = tmp
    dic = new_dic
            
# print(dic)
print(total)



