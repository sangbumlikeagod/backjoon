T = int(input())

for tc in range(1, T+1):
    N, M = map(int, input().split())
    arr = list(map(int,input().split()))
    max_v = 0
    min_v = 1000000
    for i in range(N-M+1):
        res = 0
        for j in range(i,i+M):
            res += arr[j]
        if res > max_v:
            max_v = res
        if res < min_v:
            min_v = res

    print(f'#{tc} {max_v-min_v}')