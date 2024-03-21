
import sys
f = open('1931.txt', 'r', encoding='utf-8')
sys.stdin = f

test_case = int(input())

lst = []
for num in range(test_case):
    lst.append(tuple(map(int,input().split())))


lst.sort()
print(lst)
prev = lst[0]
count = 1
for i in range(1, len(lst)):
    print(lst[i], prev)
    if lst[i][0] < prev[1] and lst[i][1] < prev[1] :
        print('더 작은앨 선택')
        prev = lst[i] 
        continue
    elif lst[i][0] >= prev[1]:
        print('!')
        count += 1
        prev = lst[i]
    else:
        continue
print(count)


# 리스트를 시작점 작은순 & 끝점 작은순으로 정렬했다

'''
그 리스트를 돌면서 
이미 정렬된 첫번째 요소는 가져갔다고 생각 -> 끝점이 더 작은애가 나올시 변경 

'''