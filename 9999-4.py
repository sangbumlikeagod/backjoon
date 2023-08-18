import sys


name = __file__.split('\\')[-1][:-5]
file = open(f'{name}.txt', 'r')
sys.stdin = file
test_case = int(input())

from collections import deque

for num in range(test_case):
    length = int(input())
    limit = length
    num_of_peek = int(input())
    Sum_with_blank: int = 0
    Sum_only_peek = 0
    idx = 0
    q = deque()
    times = []
    for _ in range(num_of_peek):
        times += list(map(int, input().split()))
    # print(times)
    # 아님, 피크 ,아님, 피크, 아님 순으로 이어짐
    prev = 0
    i = 0
    Max_num = 0
    while i < num_of_peek * 2:
        while Sum_with_blank >= length:
            if q[0][1]:
                if Max_num < Sum_only_peek + min(length - Sum_with_blank, times[i]):
                    Max_num = Sum_only_peek + min(length - Sum_with_blank, times[i])
            left = q.popleft()
            if left[1]:
                Sum_only_peek -= left[0]
            Sum_with_blank -= left[0]
        else:
            if Sum_only_peek > Max_num:
                Max_num = Sum_only_peek
            if i % 2:
                if times[i] - prev >= length:
                    Max_num = length
                    break
                Sum_with_blank += times[i] - prev
                Sum_only_peek += times[i] - prev
                q.append((times[i] - prev, 1))
            else:
                # if times[i] - prev > length:
                #     q = deque()
                #     prev = times[i]
                #     i += 1
                #     Sum_only_peek = Sum_with_blank = 0
                #     continue
                Sum_with_blank += times[i] - prev
                q.append((times[i] - prev, 0))
            prev = times[i]
            i += 1
    if Sum_only_peek > Max_num:
        Max_num = Sum_only_peek
    print(f'#{num+1} {Max_num}')




