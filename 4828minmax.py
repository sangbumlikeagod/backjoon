T = int(input()) # 테스트케이스 개수

for tc in range(1, T+1):
    N = int(input())
    arr = list(map(int, input().split()))
    max_v = 1
    min_v = 1000001
    for num in arr:
        if num > max_v:
            max_v = num
        if num < min_v:
            min_v = num

    print(f'#{tc} {max_v-min_v}')