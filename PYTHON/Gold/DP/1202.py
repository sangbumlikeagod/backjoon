
import sys
import heapq

name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r')
sys.stdin = file

J, B = map(int, input().split())
lst = []
for _ in range(J):
    heapq.heappush(lst, list(map(int, sys.stdin.readline().split())))


total = 0
lst_bag = [int(sys.stdin.readline().split()) for j in range(B)]

lst_bag.sort()
idx = 0
heap_q = []
for i in lst_bag:
    print(len(heap_q))
    # max_idx = binary_search(i)
    while lst and lst[0][0] <= i:
        heapq.heappush(heap_q, -heapq.heappop(lst)[1])
        idx += 1
    if heap_q:
        total -= heapq.heappop(heap_q)


# 어떤 최소 구조를 쓴다해도 그게 의미가 있냐고
# 전부다 리스트 노드이고 정렬이 되어있다면 또 괜찮지만 그럼 조회 자체가 존나걸림
# 가격순으로 매번 정렬할 필요가 없잖아
# 한 번 만들면 매번 정렬된 상태로 유지해주는 힙이 있으니까
print(total)
print('st')




# 둘중에 하나라도 정렬하지 않아도 되는 애가 있는가
