import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
N, M = map(int,input().split())
lst = [0, 0] + [float('inf')] * (N - 1)


dic = {}
for i in range(M):
    a, b, c  = map(int, input().split())
    dic[a] = dic.get(a, []) + [(-c, b)]
import heapq


overlap = [0] * (N + 1)
heap = []


def search(node, byfar):
    # print(node, heap)
    overlap[node] = 1

    if node == N:
        if not heap:
            return byfar
        else: 
            value, new_node, new_lst = heapq.heappop(heap)
            result = search(new_node, new_lst)
            return result if result else byfar
                
            # result = search(new_node, new_lst)
            # return result
        
    if node in dic:
        for i in dic[node]:
            print(i)
            if lst[i[1]] > i[0] + lst[node]:
                if i[1] in byfar:
                    return -1
                lst[i[1]] = i[0] + lst[node]
                # 더 작은애들이 발견되면 바꿔주는 시스템과 바꾸려고하면 터지는 시스템이
                # 충돌을 빚고 있음 이걸 막기 위해선 분기를해서 다른 리스트를 줘야함 
                # 1000으로 계층을 주는 일 역시 리스트가 안바뀌는 결과를 낳음 
                overlap[i[1]] = 1
                heapq.heappush(heap, (lst[i[1]], i[1], byfar + [i[1]]))
        if heap:
            value, new_node, new_lst = heapq.heappop(heap)
            return search(new_node, new_lst)
            # result = search(new_node, new_lst)
            # return result if result != -1 else -1
    
    else:
        if not heap:
            return 
        else:
            value, new_node, new_lst = heapq.heappop(heap)
            return search(new_node, new_lst)
        

def search(node, byfar):
    overlap[node] = 1
    if node == N:
        if not heap:
            return byfar
        else: 
            value, new_node, new_lst = heapq.heappop(heap)
            result = search(new_node, new_lst)
            return result if result else byfar

    if node in dic:
        for i in dic[node]:
            print(i)
            if lst[i[1]] > i[0] + lst[node]:
                if i[1] in byfar:
                    return -1
                lst[i[1]] = i[0] + lst[node]
                overlap[i[1]] = 1
                heapq.heappush(heap, (lst[i[1]], i[1], byfar + [i[1]]))
        if heap:
            value, new_node, new_lst = heapq.heappop(heap)
            result = search(new_node, new_lst)
            return result if result else None
    else:
        if not heap:
            return 
        else:
            value, new_node, new_lst = heapq.heappop(heap)
            result = search(new_node, new_lst)
            return result if result else None


return_value = search(1, [1])
if return_value != -1:
    print(' '.join(map(str, return_value)))
else:
    print(-1)



    

