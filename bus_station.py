import sys
f = open('../s_input.txt', 'r', encoding='utf-8'
         )
sys.stdin = f
test_case = int(input())

for num in range(test_case):

    num_of_bus = int(input())
    dic = {}
    for _ in range(num_of_bus):
        start, end = map(int, input().split())
        for i in range(start, end + 1):
            dic[i] = dic.get(i, 0) + 1
    num_of_station = int(input())

    ans = ''
    for station in range(num_of_station):
        inp = int(input())
        ans += str(f' {dic.get(inp, 0)}')

    print(f'#{num + 1}{ans}')

