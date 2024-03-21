import sys
file = open('1009.txt', 'r')
sys.stdin = file
 
test_case = int(input())

for num in range(test_case):
    a, b = map(int, input().split())
    switch = 0
    idx = 1
    dic = {}
    while b > 0:
        # print(dic)
        remainder = a ** idx % 10
        for i in dic:
            if dic[i] == remainder:
                switch = 1
                continue
        else:
            if switch:
                break
        dic[idx] = remainder
        b -= 1
        idx += 1

    if b == 0:
        print(remainder)
        continue
    else:    
        length = len(dic)
        if b % length == 0:
            print(dic[length])
        else:
            print(dic[b % length])
