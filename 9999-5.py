import sys


name = __file__.split('\\')[-1][:-5]
file = open(f'{name}.txt', 'r')
sys.stdin = file
test_case = int(input())


for num in range(test_case):
    length = int(input())
    limit = length
    num_of_peek = int(input())
    Sum_with_blank = 0
    Sum_only_peek = 0
    Max_num = 0
    times = []
    for _ in range(num_of_peek):
        times += list(map(int, input().split()))

    # 투 포인터를 할거다
    left, right = 0, 1

    while right < num_of_peek * 2:
        while Sum_with_blank >= length:
            if left % 2:
                if Max_num < Sum_only_peek + min(length - Sum_with_blank, times[left] - times[left - 1]):
                    Max_num = Sum_only_peek + min(length - Sum_with_blank, times[left] - times[left - 1])

            if left % 2:
                Sum_only_peek -= times[left] - times[max(left - 1, 0)]
            Sum_with_blank -= times[left] - times[max(left - 1, 0)]
            left += 1

        else:
            if Sum_only_peek > Max_num:
                Max_num = Sum_only_peek
            if right % 2:
                if times[right] - times[right - 1] > length:
                    Max_num = length
                    break
                Sum_with_blank += times[right] - times[right - 1]
                Sum_only_peek += times[right] - times[right - 1]
            else:
                Sum_with_blank += times[right] - times[right - 1]
            right += 1

    if Sum_only_peek > Max_num:
        Max_num = Sum_only_peek

    print(f'#{num+1} {Max_num}')
    #비싸면 오른쪽으로 한 칸 씩 이동해
