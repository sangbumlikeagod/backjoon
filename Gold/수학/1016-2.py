# 인터페이스 
# min의 제곱근보다 작은 소수 리스트를 전부 구한다.
# 
# min부터 max까지 제곱 ㄴㄴ 수인지 확인
#'제곱 ㄴㄴ 수인지 확인' => 해당 수의 제곱근 보다 작거나 같은 소수들에 대해서 이 수들의 제곱으로 
# 나누어 지지 않는지 확인 
# max 보다 작거나 같은 소수들에 대해서 
# 이 소수들의 제곱이 min 부터 max 까지의 숫자들에 대해서 나누어지는지를 파악해야한다.
# 제곱수임을 확인하는 것을 어떻게 할 수 있냐 

import sys

# lst = [2] 
# for i in range(3, int(max ** 0.5) + 1, 2):
#     # print(i)
#     for j in lst:
#         if not i % j:
#             break
#     else:
#         lst.append(i)


# sieve = [True] * max
# for i in range(2, int(max ** 0.5) + 1):
#     if sieve[i] == True:           # i가 소수인 경우
#         for j in range(i+i, max, i): # i이후 i의 배수들을 False 판정
#             sieve[j] = False
# lst = [i for i in range(2, max) if sieve[i] == True]

# 소수 목록 산출

# for num in range(min, max + 1):
#     for j in lst:
#         if num < j ** 2:
#             break
#         if  not num % j ** 2:
#             ans -= 1
#             break

# 모든 수에 대해서 조사할 
# 채라는 개념을 다시 이용해서 제곱수의 배수의 개수를 뺀 

# print(lst)
# def nosquare(min, max):
#     ans = max - min + 1
#     set_1 = set()
#     i = 2
#     while i ** 2 <= max:
        
#         comp = 1 if min % i ** 2 else 0
#         j = min // i ** 2 + comp
        
#         while j * i ** 2 <= max:
#             # print(j, i)
#             set_1.add(j * i ** 2 + comp)
#             j += 1
#         i += 1
#     # print(set_1)
#     return ans - len(set_1)

def nosquare(min, max):
    ans = max - min + 1
    set_1 = set()
    i = 2
    while i ** 2 <= max:
        comp = 1 if min % i ** 2 else 0
        j = min // i ** 2 + comp
        while j * i ** 2 <= max:
            set_1.add(j * i ** 2 + comp)
            j += 1
        i += 1
    return ans - len(set_1)

min, max = map(int, input().split())

print(nosquare(min, max))
# print(nosquare(max) - nosquare(min - 1))
            

