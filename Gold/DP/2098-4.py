
import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
sys.setrecursionlimit(10000)
# 완전 똑같은데 시간의 문제
# 대칭적이지 않은데 비트 마스킹 가능 ?  12 -x-> 3 이라고 해서 마스킹 할 수는 없음
N = int(sys.stdin.readline())



NbyN = [list(map(int, sys.stdin.readline().split())) for i in range(N)]
import heapq

visited = [[0] * 2 ** (N - 1) for i in range(N)]

def search(intt, num):

    if not intt:
        if NbyN[num][N - 1]:
            visited[num][intt] = NbyN[num][N - 1]
            return  NbyN[num][N - 1]
        else:
            visited[num][intt] = NbyN[num][N - 1] = float('inf')
            return float('inf')
            
    lst = []
    if visited[num][intt]:
        return visited[num][intt]

    for i in range(N):
        if intt & 1 << i and NbyN[num][i]:
            heapq.heappush(lst,  search(intt - (1 << i), i) + NbyN[num][i])
    if not lst:
        visited[num][intt] = float('inf')
        return float('inf')
    visited[num][intt] = lst[0]
    # print(lst)
    return lst[0]

                
print(search(2 ** (N - 1) - 1, N - 1))
# print(visited)