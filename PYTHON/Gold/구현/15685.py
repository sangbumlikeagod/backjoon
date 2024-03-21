import sys
sys.stdin = open('15685.txt','r')
import sys
st = sys.stdin.readline

N = int(st())

'''

0세대는 1칸 1세대
다음 회전점은 시작점을 이전 회전점 기준으로 회전시킨 것
끝점을 기준으로 왼쪽 한칸 ( x : -1 은 위로 한칸이 y : -1
위로 한칸은 오른쪽 x 한칸  x = 
오른쪽 한칸은 아래로 한칸 
x의 변화는 부호 그대로 y로 바뀌고
y의 변화는 부호가 바뀐채로 x에 더해진다

변화라는게
y가 증가하는 방향이면 x가 감소하고
y가 감소하는 방향이면 x가 증가함
x가 증가하는 방향이면 y가 감소함 
x가 감소하는 방향이면 y가 증가함  


'''

def dragoncurve(start, generation, t_type):
    growing_generation = 0
    if t_type == 0:
        end = (start[0], start[1] + 1)
    elif t_type == 1:
        end = (start[0] - 1, start[1]) 
    elif t_type == 2:
        end = (start[0] , start[1] - 1) 
    else:
        end = (start[0] + 1, start[1]) 

    def grow(pivot, remainder):
        # print(pivot, remainder)
        add_set = set()
        for arg in remainder:
            
            dx, dy = (pivot[0] - arg[0]), (pivot[1] - arg[1])
            # dx가 크면 피봇이 더 아래에 있다 dy가 0보다 크면 피봇이 더 오른쪽에 있다
            # if not dx:
            #     if dy > 0:
            #         new = (pivot[0] + dy, pivot[1])
            #     else:
            #         new = (pivot[0] + dy, pivot[1])
            # elif not dy:
            #     if dx > 0:
            if not dx or not dy:
                new = (pivot[0] - dy, pivot[1] + dx)

            else:
                if dx > 0 and dy > 0: # 피봇 2사분면
                    new =  (pivot[0] - abs(dy), pivot[1] + abs(dx))
                elif dy > 0 and dx < 0: # 피봇 1사분면
                    new =  (pivot[0] - abs(dy), pivot[1] - abs(dx))
                elif dx > 0 and dy < 0: # 피봇 3사분면
                    new =  (pivot[0] + abs(dy), pivot[1] + abs(dx))
                else: # 피봇 
                    new =  (pivot[0] + abs(dy), pivot[1] - abs(dx))
            # print(arg, 'to', new, 'by', pivot)
            if 0 <= new[0] <= 100 and 0 <= new[1] <= 100:
                if arg == start:
                    add_set.add(pivot)
                    new_pivot = new
                    continue
                add_set.add(new)
        remainder |= add_set
       
        return (new_pivot, remainder)

    
    remainder = {(start)}
    pivot = end    
    while growing_generation < generation:
        pivot, remainder = grow(pivot, remainder)
        growing_generation += 1
        # print('\t', remainder, pivot)
    
    remainder |= {pivot}
    return remainder



start_set = set()
lst = [[0] * 10 for _ in range(10)]

for _ in range(N):
    x, y, d, g = map(int, st().split())
    tmp =  dragoncurve((y, x), g, d)
    start_set |= tmp

square = 0
for point in start_set:
    if (point[0] + 1, point[1]) in start_set and\
    (point[0], point[1] + 1) in start_set and\
    (point[0] + 1, point[1] + 1) in start_set:
        square += 1
print(square)

