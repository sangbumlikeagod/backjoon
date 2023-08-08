num_of_bulb = int(input())
bulb_array = list(map(int, input().split()))

student_num = int(input())

for _ in range(student_num):
    sex, num = map(int, input().split())
    if sex - 1:
        left = num - 2
        right = num
        bulb_array[num - 1] = int(not bulb_array[num - 1])
        while left >= 0 and right < num_of_bulb and bulb_array[left] == bulb_array[right]:
            bulb_array[left] = int(not bulb_array[left])
            bulb_array[right] = int(not bulb_array[right])
            left -= 1
            right += 1
        print(bulb_array)
    else:
        tmp = 0
        while num + tmp <= num_of_bulb:
            bulb_array[num + tmp - 1] = int(not bulb_array[num + tmp - 1])
            tmp += num
        print(bulb_array)
ans = []
idx = 0
while num_of_bulb >= idx:
    ans.append(bulb_array[idx:idx+20])
    idx += 20

for i in ans:
    print(' '.join(map(str, i)))




