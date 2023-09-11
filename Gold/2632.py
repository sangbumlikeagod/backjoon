
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
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
def pizza_A_find():
    global count
    ss = sum(pizza_A)
    if ss <= C:
        count += pizza_B_find(C - ss)

        
    for i in range(A):
        # print(i, end=' ')
        local = pizza_A[i]
        two_pointer = (i + 1) % A
        while local < C:
            if local == ss:
                break
            if two_pointer == i:
                break
            # print(two_pointer, end=' ')
            if C - local in dic:
                count += dic[C - local]
            else:
                dic[C- local] = pizza_B_find(C - local)   
                count += dic[C - local]   
            local += pizza_A[two_pointer]
            two_pointer = (two_pointer + 1) % A
        if local == C:
            count += 1

            
def pizza_B_find(num):

    if num == 0:
        return 1
    elif sum(pizza_B) == num:
        return 1
    for i in range(B):
        local = pizza_B[i]
        two_pointer = (i + 1) % A
        while local < num:
            if two_pointer == i:
                break
            local += pizza_A[two_pointer]
            two_pointer = (two_pointer + 1) % A
        if local == num:
            return 1
    return 0
pizza_A_find()

# print(dic)
print(count)
            


# 1000개가 있을 때 확인해야하는 개수가 
# 1000 + 999 + 998 ~~~ 1001 * 500 인걸로 예상됨 그걸 총 두번 반복할 수 있음
# 그 이외에는 줄이는 방법에 대해서 생각해야함 아니지
# 빠지는게 1000개 짜리 가 가능하니까 가능성은 또 무궁무진함 
# 메모이 제이션으로 같은 값은 어느정도 방어하는 방법을 만들 수도 있음 