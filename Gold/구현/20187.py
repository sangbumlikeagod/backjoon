
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

'''

1짜리 에서 시작해서 반대로 슉슉 이동하면 될듯

3번 
L이면 R로 넣고 R이면 L로 넣고 
0 , 1 , 2, 3 이렇게 넣는다면 

첫 L이 나오면 반대가 되고 뒤에는 무조건 복붙을 하게된다.

비대칭인 경우가 처음 1번밖에없음 


'''

import sys
st = sys.stdin.readline
N = int(st())

order = input().split()

punch = int(input())
two_two = []
updown = True
leftright = True

dic = {
    0 : 1,
    1 : 0,
    2 : 3,
    3 : 2
    }
uddic = {
    1 : 3,
    3 : 1,
    0 : 2,
    2 : 0
    }

while updown or leftright:
    nex = order.pop()
    # print(nex)
    if leftright and nex == "R":
        # L로 이동한다 왼쪽에 뭐가 생긴다
        if not two_two:
            two_two.append([dic[punch], punch])
        else:
            for i in range(2):
                two_two[i] = [dic[two_two[i][0]]] + two_two[i]
        leftright = False   
    elif leftright and nex == "L":
        # 오른쪽에 뭐가 생긴다 
        if not two_two:
            two_two.append([punch, dic[punch]])
        else:
            for i in range(2):
                two_two[i] = two_two[i] + [dic[two_two[i][0]]] 
        leftright = False
        
    elif updown and nex == "U":
        # 아래에 뭐가 생긴다 
        if not two_two:
            two_two.append([punch])
            two_two.append([uddic[punch]])
        else:
            tmp = []
            for i in two_two[0]:
                tmp.append(uddic[i])
            two_two = [two_two[0]] + [tmp]
        updown = False
    elif updown and nex == "D":
        
        if not two_two:
            two_two.append([uddic[punch]])
            two_two.append([punch])
        else:
            tmp = []
            for i in two_two[0]:
                tmp.append(uddic[i])
            two_two = [tmp] + [two_two[0]]
        updown = False
        # 위쪽에 뭐가 생긴다


for i in range( 2 ** (N - 1)):
    for _ in two_two:
        print(' '.join(map(str, _ * 2 ** (N - 1))))
    
