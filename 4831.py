import sys

f = open('4831_input.txt', 'r', encoding='utf-8')
sys.stdin = f

test_case = int(input())

for num in range(test_case):
    fuel, road, station = map(int, input().split())
    station_position = list(map(int, input().split()))
    i = 0
    count = 0
    while i + fuel < road:
        local_max = 0
        for station in station_position:
            if i + fuel >= station > local_max:
                local_max = station
                # print(local_max)
        if local_max == i:
            count = 0
            break
        i = local_max
        # print(i)
        count += 1


    print(f'#{num + 1} {count}')
