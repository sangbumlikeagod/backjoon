
# 입력값 N, K  총 물병의 개수, 가져갈 수 있는 물의 총합
# 사건분석 주어진 N을 k개로 만드는데 필요한 최소한의 물병구입개수를 구하라
# 물병 수를 압축한다는 것은 정확히 2의 거듭제곱으로만 나타낼 수 있다는걸 의미한다
# 요컨데 k 개의 2의 거듭제곱들로 나타낼 수 있다는 뜻이다.
# 상위 k 번째의 요소는 뒤의 요소들과 합쳐져 자리수를 하나 더할 것이다.
# 정답이 없을 경우 ? 한개도 못옮길 경우일 수는 있지 근데 k가 자연수라고 하는데
# 살수 있는 숫자에 따로 제약이 있는게 아닌데 어쨰서
import sys


name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r')
sys.stdin = file
# test_case = int(input())


def binaryfication(num):
    lst = []
    while num >= 1:
        lst.append(num % 2)
        num //= 2
    return lst


# 스택을 만든다.



N, K = map(int, input().split())
binary_num = binaryfication(N)

while binary_num and (K > 1 or binary_num[-1] == 0):
    # print(binary_num)
    if binary_num[-1] == 1:
        K -= 1
    binary_num.pop()
ans = 2 ** len(binary_num)


local = 0
for power, number in enumerate(binary_num):
    # print(number, power)
    local += number * 2 ** power

if local == ans // 2 :
    ans = 0

print(ans)

