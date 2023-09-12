
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

from itertools import accumulate
st = sys.stdin.readline
C = int(st())
A, B = map(int, st().split())
pizza_A = []
pizza_B = []
for _ in range(A):
    pizza_A += [int(st())]
    
for _ in range(B):
    pizza_B += [int(st())]
    
# print(pizza_A, pizza_B)
dic = {}
count = 0

pizza_A_AC = []
pizza_B_AC = []

for i in range(A):
    pizza_A_AC.append(list(accumulate(pizza_A[i:] + pizza_A[ : i])))
for i in range(B):
    pizza_B_AC.append(list(accumulate(pizza_B[i:] + pizza_B[ : i])))

print(pizza_A_AC)
print(pizza_B_AC)

def pizza_A_find():
    global count
    ss = sum(pizza_A)
    if ss <= C:
        count += pizza_B_find(C - ss)

        
    for i in range(A):
        for j in range(A - 1):
            if pizza_A_AC[i][j] > C:
                break
            elif pizza_A_AC[i][j] == C:
                count += 1
                break
            else:
                if C - pizza_A_AC[i][j] in dic:
                    count += dic[C - pizza_A_AC[i][j]]
                else:
                    dic[C - pizza_A_AC[i][j]] = pizza_B_find(C - pizza_A_AC[i][j])   
                    count += dic[C - pizza_A_AC[i][j]]

      
def pizza_B_find(num):
    if len(pizza_B) == 1:
        return num == pizza_B[0]
    for i in range(B):
        start = 0
        end = B - 1
        while start <= end:
            mid = (start + end) // 2
            if pizza_B_AC[i][mid] == num:
                return 1
            elif pizza_B_AC[i][mid] < num:
                start = mid + 1
            else:
                end = mid - 1
    return 0
pizza_A_find()
print(count)
            


# 1000개가 있을 때 확인해야하는 개수가 
# 1000 + 999 + 998 ~~~ 1001 * 500 인걸로 예상됨 그걸 총 두번 반복할 수 있음
# 그 이외에는 줄이는 방법에 대해서 생각해야함 아니지
# 빠지는게 1000개 짜리 가 가능하니까 가능성은 또 무궁무진함 
# 메모이 제이션으로 같은 값은 어느정도 방어하는 방법을 만들 수도 있음 

# 해봤자 슬라이딩 윈도우인데