import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

desire = desire_digit = int(st())
M = int(st())
error = list(map(int, st().split()))

now_watching = 100
available = list(range(10))
for i in error:
    available[i] = 0

digit_lst = []
while desire_digit > 0:
    digit_lst.append(desire_digit % 10)
    desire_digit //= 10

# 같으면 나머지는 가장 왼쪽에 있는 애들로 채움 


# 앞에서부터 차례대로 같은애가 있다면 무조건 걔로 가는게 맞아
# 아니라면 가장 오른쪽에 있는애랑 가장 왼쪽에 있는 애들중 하나로 가는게 맞아 
# 첫번쨰 요소일때와 아닐떄가 구분돼야함

gogo = []

def find_min(num_lst, num):
    left = -1
    while not available[num_lst[num + left]]:
        left -= 1
    if num + left < 0:
        return float('inf')
    
    maxx = num - 1
    while not available[maxx]:
        maxx -= 1
    [available[maxx]] * len(num_lst - 1) + [available[num_lst[num + left]]]
        



def find_max(num_lst, num):
    right = 1
    while not available[num_lst[num + right]]:
        right += 1
    if num + right >= len(num_lst):
        return float('inf')
    minn = 0
    while not available[minn]:
        minn += 1
    [available[minn] * len(num_lst - 1)] + [available[num_lst[num + right]]]

def LstToNum():
    return

while digit_lst:
    if available[digit_lst[-1]]:
        gogo.append(digit_lst.pop())
    else:
        pass
    break


