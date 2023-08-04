
N, M, K = 3, 4, 6
lst = [[1, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1]]
count = 0
import time
# 부분집합의 크기를 구한다
for i in range(1, N + 1):
    for j in range(1, M + 1):
        if i * j * 50 < K:
            continue
        scopes = [ [ row, column ] for row in range(i) for column in range(j) ]
        scope_sum = row_change = column_change = sum([ lst[row][column] for row in range(i) for column in range(j) ])
        # 이동 범위에 대해서 
        for row_move in range(N - i + 1):
            '''
            여기서 row change를 만들어서 할때마다 행 합이 바뀐 상태로 만들어준다면? 
            매번 갱신해야 하기 떄문에 슬라이딩 윈도우인거지
            
            row_change는 0 ~ i - 1 개의 행들에 대해서 i 번쨰 행의 값들을 더하고 i - ( i - 1 ) - 1 번째 요소를 뺸다 
            row_change += [i - 1 + a(a = 1 : N - i + 1) ][0 : j] 
            '''
            row_change += sum([lst[ i - 1 + row_move][column] for column in range(j)])
            row_change -= sum([lst[row_move - 1][column] for column in range(j)])
            column_change = row_change
            # if row_change % K == 0:
            #     count += 1
            #     print(scopes)
            for column_move in range(M - j + 1):
                column_change += sum([lst[row + row_move][j - 1 + column_move] for row in range(0, i)])
                column_change -= sum([lst[row + row_move][column_move - 1] for row in range(0, i)])
                if column_change % K == 0:
                    count += 1
                    # print(scopes)
        

                # if sum([lst[row_move + scope[0]][column_move + scope[1]] for scope in scopes ]) % K == 0:
                #     # print([lst[row_move + scope[0]][column_move + scope[1]] for scope in scopes ])
                #     count += 1
                    
        # 합에 대해서만 따로 할 수 있게? 
print(count)
                