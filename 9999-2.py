import sys


name = __file__.split('\\')[-1][:-5]
file = open(f'{name}.txt', 'r')
sys.stdin = file
test_case = int(input())
test_case = 20

from queue import Queue

for num in range(test_case):
    return_value = 0
    length = int(input())
    num_of_peek = int(input())
    Sum_with_blank: int = 0
    Sum_only_peek = 0
    idx = 0
    q = Queue()
    times = [list(map(int, input().split())) for i in range(num_of_peek)]
    # print(times)
    Max_time = 0
    for time in times:
        if Sum_with_blank + time[0] - idx <= length:
            Sum_with_blank += time[0] - idx
            q.put((time[0] - idx, 0))
            idx = time[0]
        else:
            left = (0, 0)
            if Max_time < Sum_only_peek:
                Max_time = Sum_only_peek
            while not q.empty() and Sum_with_blank + time[0] - idx >= length:
                left = q.get()
                Sum_with_blank -= left[0]
                if left[1]:
                    Sum_only_peek -= left[0]
            else:
                Sum_with_blank += time[0] - idx
                q.put((time[0] - idx, 0))
                idx = time[0]

        if Sum_with_blank + time[1] - idx <= length:
            Sum_with_blank += time[1] - idx
            Sum_only_peek += time[1] - idx

            q.put((time[1] - idx, 1))
            idx = time[1]
            # if Sum_with_blank < length and left[1]:
            #     if Max_time < Sum_only_peek + min(length - Sum_with_blank, left[0]):
            #         Max_time = Sum_only_peek + min(length - Sum_with_blank, left[0])
        else:
            left_2 = (0, 0)
            if time[1] - idx > length:
                Max_time = length
                break

            if Max_time < Sum_only_peek + length - Sum_with_blank:
                Max_time = Sum_only_peek + length - Sum_with_blank
            while not q.empty() and Sum_with_blank + time[1] - idx >= length:
                left_2 = q.get()
                Sum_with_blank -= left_2[0]
                if left_2[1]:
                    Sum_only_peek -= left_2[0]
            else:
                q.put((time[1] - idx, 1))
                Sum_with_blank += time[1] - idx
                Sum_only_peek += time[1] - idx
                idx = time[1]
    if Sum_with_blank < length and left[1]:
        print('마지막 경우를 챙김')
        Sum_only_peek += min(length - Sum_with_blank, left[0])
    if Sum_only_peek > Max_time:
        print('역전 돼서 바뀜')
        Max_time = Sum_only_peek

    print(Max_time)