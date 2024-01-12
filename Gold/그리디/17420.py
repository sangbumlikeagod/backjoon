import sys
sys.stdin = open('17420.txt','r')

N = int(input())
duration = list(map(int, input().split()))
will_use = list(map(int, input().split()))

schedule = [(will_use[i], duration[i]) for i in range(N)]
schedule.sort()

ans = 0
max_val = schedule[0][1]
max_duration = schedule[0][0]
prev_max_val = 0
prev_max_duration = 0

for i in range(N):
    if max_duration != schedule[i][0]:
        if schedule[i][1] < max_val or schedule[i][1] < schedule[i][0]:
            tmp_max = max(schedule[i][0], max_val)
            num = abs(schedule[i][1] - tmp_max) // 30 + bool(abs(schedule[i][1] - tmp_max) % 30)
            ans += num

            prev_max_val = max_val
            prev_max_duration = max_duration
            max_val = num * 30 + schedule[i][1]
            max_duration = schedule[i][0]
        else:
            max_val = max(max_val, schedule[i][1])
    else:
        if schedule[i][1] < prev_max_val or schedule[i][1] < schedule[i][0]:
            tmp_max = max(schedule[i][0], prev_max_val)
            num = abs(schedule[i][1] - tmp_max) // 30 + bool(abs(schedule[i][1] - tmp_max) % 30)
            ans += num
            max_val = max(num * 30 + schedule[i][1], max_val)

        max_val = max(max_val, schedule[i][1])

print(ans)

