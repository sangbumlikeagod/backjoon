import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(100000)

N = int(input())

lst = list(map(int, input().split()))
set_lst = set(range(1 , N + 1))

#구현해야하는 기능. 그래프의 루프를 구현 

dic = {}
section_lst = []
for i in range(1, N + 1):
    # set으로 최대 n개의 영역을 자유롭게 조절 
    tmp, *tmp_lst = map(int, input().split())
    
    local = set(tmp_lst)
    dic[i] = tmp_lst
    # for dis_sofar in range(len(section_lst)):
    #     if i in section_lst[dis_sofar]:
    #         # print(i, section_lst[dis_sofar])
    #         section_lst[dis_sofar] = section_lst[dis_sofar] | local
    #         break
    # else:
    #     section_lst.append(local)
        
#     for i in range(len(section_lst)):
#         for j in range(len(section_lst)):
#             if section_lst[i] & section_lst[j]:
#                 section_lst[i] = section_lst[j] = section_lst[i] | section_lst[j]
    
    
        
# # 이것 이외에 리스트를 통합하는 법이 없을까 더 쉽게 하는법 없을까

# print(section_lst)
#     # print(dic, section_lst)
# if len(section_lst) > 2 or len(section_lst) == 0:
#     print(-1)
# elif len(section_lst) == 2:
#     print(abs(sum(section_lst[0]) - sum(section_lst[1])))
# else:
    # print(dic)
    # bfs를 설정해서 유효한 분기라고 확인이되면 값을 구하는 방식으로
max_val = 2000
total = sum(lst)

def validity(sett):
    if len(sett) == 0:
        return False
    if len(sett) == 1:
        return True
    for check_every_number in sett:
        for only_one_possible in dic[check_every_number]:
            if only_one_possible in sett:
                break
        else:
            return False
    return True

def search(sett):
    if len(sett) == 0 or len(sett) == N:
        return False

    if len(sett) == 1:
        return True
    visited = [0] * N 
    start = sett.pop()
    que = [start]
    while que:
        next = que.pop(0)
        for i in dic[next]:
            if not visited[i - 1] and i in sett:
                visited[i - 1] = 1
                que.append(i)
    
    for i in sett:
        if not visited[i - 1]:
            return False
    return True 

visited = [0] * N
visited[0] = 1

# 크기가 1일 때는 두개의 구간으로 나눠야함 
# 부분집합을 만들기 위해서 어떻게 해야하는가  
for_subset = list(range(1, N + 1))
re = []
def subset(idx, locallst):
   
    global max_val
    # print(locallst)
    # print(locallst)
    if idx == N:
        if search(set(locallst)) and search(set_lst - set(locallst)):
            # print(locallst)
            local = 0
            for i in locallst:
                local += lst[i - 1]
            if abs(total - 2 * local) < max_val:
                max_val = abs(total - 2 * local)
        return
                
    locallst.append(for_subset[idx])
    subset(idx + 1, locallst)
    locallst.pop()
    subset(idx + 1, locallst)
    
# print(search({5, 6}), dic)
subset(1, [1])

if max_val == 2000:
    print(-1)
else:
    print(max_val)
    # print(validity({2,3,4,5}) and validity({1}))
    
    
    # def bfs(que, sett, idx):
    #     global max_val
    #     for next_go in dic[que[idx]]:
    #         if not visited[next_go - 1]:
    #             visited[next_go - 1] = 1
    #             que.append(next_go)
                
    #     if idx == len(que) - 1:
    #         if validity(set_lst - sett) and validity(sett):
    #             local = 0
    #             print(sett, que)
    #             for i in sett:
    #                 local += lst[i - 1]
    #             if max_val > abs(total - 2 * local):
    #                 max_val = abs(total - 2 * local)
    #         return
    #     idx += 1
    #     bfs(que, sett | {que[idx]}, idx)
    #     bfs(que, sett , idx)