def solution(stones, k):
    answer = 0
    switch = True
    #스톤들을 계속 건넌다.
    while switch:
        switch = False
        maximum = k - 1
        for i in range(len(stones)):
            print(i)
            if stones[i]:
                maximum = k - 1
                stones[i] -= 1
            else:
                if maximum:
                    maximum -= 1
                    continue
                else:
                    break
        else:
            switch =True
            # 전부다 돌았을 때
            answer += 1

                # 0이 남아있으면
                # 이제 문제는 어떻게 문제가 없는지 확인할 것이냐는 것
    return answer

print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3))


import heapq

lst = []
def solution(stones, k):
    lst = []
    start = 0
    last = k

    answer = 200,000,000 
    for i in range(k, len(stones)):
        local = 0
        for j in range(start, last):
            if stones[j] > local:
                local = stones[j]
        if local < answer:
            answer = local

    return answer