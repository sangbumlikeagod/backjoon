import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(100000)

import heapq
pro = 1
while True:
    N = int(input())
    if N == 0:
        break

    dongul = [list(map(int, input().split())) for _ in range(N)]
    visited = [[0] * N for _ in range(N)]
    visited[0][0] = 1
    heap = [(dongul[0][0],(0, 0))]
    # print(dongul, heap)
    # 중간확인 - 힙 형태는 (좌표까지 가는데 걸리는 값, ( 좌표 ))

    # 혹시모를 종료조건 확인 
    return_value = 0 
    not_end = True
    while not_end:
        ssum, idx = heapq.heappop(heap)

        # 제대로 출력되는지 확인 - 확인됨
        # print(sum, idx)
        for i in [[0, 1], [1, 0], [0, -1], [-1, 0]]:
            if 0 <= idx[0] + i[0] < N and \
                0 <= idx[1] + i[1] < N and \
                not visited[idx[0] + i[0]][idx[1] + i[1]]:
                if idx[0] + i[0] == N - 1 and idx[1] + i[1] == N - 1:
                    return_value =  ssum + dongul[N - 1][N - 1]
                    not_end = False
                    break
                visited[idx[0] + i[0]][idx[1] + i[1]] = 1
                heapq.heappush(heap, ((ssum + dongul[idx[0] + i[0]][idx[1] + i[1]], (idx[0] + i[0], idx[1] + i[1]))))
            # 이동경로들 제대로 나오는지 확인. 한 좌표의 이동 경로를 한번씩 만 
            # 추가하면 족한가? 아니면 돌아가지만 않게 해놔야 하나?
            # 어떤 최소경로와 fake 최소 경로가 겹친다고 가정 
            # 그러면 이후의 경로는 동일하다고 전제되는데 이말인 즉슨 이후의 값은 동일하다는 뜻이다
            # 그렇다면 이전까지 최소의 경로를 탐색하는 알고리즘의 특성상 항상 먼저 도달하는쪽이 최소 값이고
            # 먼저 도달한 경로가 항상 최소 경로일 것이다. 
            # 따라서 증명됨
        
        # [0, 0] 좌표에 대해서 필요한 좌표가 다 추가됐는지 확인 - 완료
        # print(heap)

    print(f'Problem {pro}: {return_value}')
    pro += 1



