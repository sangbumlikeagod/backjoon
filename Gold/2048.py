import sys

name = __file__.split('\\')[-1][:-3]
file = open(f'{name}.txt', 'r', encoding='utf-8')
sys.stdin = file

length = int(input())
board = [list(map(int, input().split())) for _ in range(length)]

# print(board)

'''

요구사항 

1. 남은 이동횟수를 알아야하고 이동횟수가 다됐으면 최대값을 리턴해야함.
    1.1. 최대값을 리턴하기 위해선 최대값을 알만한 값들을 매개변수로 제공해야함
    1.2 in-place로 문제를 해결하기 위해선 한 번 사용한 애들을 다시 돌려줘야한다. 
        하지만 어떤 열이 합쳐졌는지 아닌지를 기억해야 하기때문에 사실상 하나
        저장해놓는 급의 귀찮음이 생길 것
2. 이동을 하기 전에 상호작용이 일어나는지를 확인해서 가지수를 줄일려고 했으나 
0 0 0 0 
4 2 0 0 
2 0 0 0
0 0 0 0 
이 경우의 수가 최대는 8인것을 고려했을 때 ( 딱 5번이 아니라 더 주어지는걸 감안한다면 )
모든 경우의 수를 일단 다 탐색하는걸로

'''
def moving(direction, remain, new_array):
    array = [new_array[i][:] for i in range(length)]
    if not remain:
        max_val = 0

        for arr in array:
            if max(arr) > max_val:
                max_val = max(arr)
        return max_val
    
    # 앞으로 쫙 땡겨야한다는 뜻이었지
    # 1을 더한다는건 아래 오른쪽으로 이동한다는것 낮은쪽에서 높은쪽으로 간다는것 
    if sum(direction) == -1:
        que = []
        for row in range(length):
            for column in range(length):
                # 어느방향으로 움직일지는 dir이 알려준다 처음부터 쭉 움직인다.
                if array[row][column]: # 값이 있을때만 이동
                    row_copy = row
                    column_copy = column
                    while 0 <= row_copy + direction[0] < length and 0 <= column_copy + direction[1] < length and array[row_copy + direction[0]][column_copy + direction[1]] == 0:
                        array[row_copy + direction[0]][column_copy + direction[1]], array[row][column] = array[row][column], 0 
                        row_copy += direction[0]
                        column_copy += direction[1]
                    else:
                        # 종료조건은 0이 아니거나 바깥으로 나갔거나.
                        # 같은애를 만났을 시 합쳐준다
                        if 0 <= row_copy + direction[0] < length and 0 <= column_copy + direction[1] < length and \
                            array[row_copy + direction[0]][column_copy + direction[1]] == array[row][column]:
                            array[row][column] *= 2
                            array[row_copy + direction[0]][column_copy + direction[1]] = 0
                            que.append([row, column])
        for rorow, cocolumn in que:
            while 0 <= rorow + direction[0] < length and 0 <= cocolumn + direction[1] < length and array[rorow + direction[0]][cocolumn + direction[1]] == 0:
                        array[rorow + direction[0]][cocolumn + direction[1]], array[rorow][cocolumn] = array[row][column], 0 
                        rorow += direction[0]
                        cocolumn += direction[1]
        
    else:
        que = []
        for row in range(length - 1, -1 ,-1):
            for column in range(length - 1, -1 ,-1):
                if array[row][column]: # 값이 있을때만 이동
                    row_copy = row
                    column_copy = column
                    while 0 <= row_copy + direction[0] < length and 0 <= column_copy + direction[1] < length and array[row_copy + direction[0]][column_copy + direction[1]] == 0:
                        array[row_copy + direction[0]][column_copy + direction[1]], array[row][column] = array[row][column], 0 
                        row_copy += direction[0]
                        column_copy += direction[1]
                    else:
                        # 종료조건은 0이 아니거나 바깥으로 나갔거나.
                        # 같은애를 만났을 시 합쳐준다
                        if 0 <= row_copy + direction[0] < length and 0 <= column_copy + direction[1] < length and \
                            array[row_copy + direction[0]][column_copy + direction[1]] == array[row][column]:
                            array[row][column] *= 2
                            array[row_copy + direction[0]][column_copy + direction[1]] = 0
                            que.append([row, column])
        for rorow, cocolumn in que:
            while 0 <= rorow + direction[0] < length and 0 <= cocolumn + direction[1] < length and array[rorow + direction[0]][cocolumn + direction[1]] == 0:
                        array[rorow + direction[0]][cocolumn + direction[1]], array[rorow][cocolumn] = array[row][column], 0 
                        rorow += direction[0]
                        cocolumn += direction[1]
            
    ret_value = 0
    print( * array , sep=' \n ')
    # for i in [[-1,0], [1, 0], [0, -1], [0, 1]]:
    for i in [[0,-1]]:
        cand = moving(i, remain - 1, array)
        if cand > ret_value:
            ret_value = cand
    return ret_value
    
return_value = 0
for i in [[-1,0]]:
# for i in [[-1,0], [1, 0], [0, -1], [0, 1]]:
    cand = moving(i, 2, board)
    if cand > return_value:
        return_value = cand
    
print(return_value)


 

# 동서남북 전부다 구현했으면 다음 단계
# 움직이질 못하게 되네
