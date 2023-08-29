import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
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
    # print(node, lst)
    overlap[node] = 1
    if node == N:
        return byfar


    if node in dic:
        for i in dic[node]:
            if lst[i[1]] > i[0] + lst[node]:
                if i[1] in byfar:
                    if not heap:
                        return -1
                    else: 
                        value, new_node, new_lst = heapq.heappop(heap)
                        result = search(new_node, new_lst)
                        
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