import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')

T = int(input())
T = 3

#정리를 잘 못하는게 이런문제에서 큰 영향을 끼침 방식은 똑같아 

def hex_to_bin(arr):
    binarr = []
    binary = ''
    for hex in arr:
        if hex:
            for i in hex:
                binary += f'{int(i, base = 16):04b}'
            # number = int(hex, base = 16)
            binarr.append(binary)
    return binarr
def get_width(arr):
    widths = []
    count = 0
    before = 0 # 현재 값을 저장 
    change = 0 # 숫자가 0 -> 1 1-> 0 몇번 바뀌었는지 확인
    for row in range(len(arr)):
        count = 0
        change = 0
        before = '0'
        for col in range(len(arr[row])-1, -1, -1):
            print(arr[row][col], end= ' ')
            if before != arr[row][col]:
                # 숫자가 전환되는 횟수 
                if change == 4:
                    break
                change += 1
                before = arr[row][col]
            if arr[row][col] == '1':
                # 왼쪽에서 처음 만났다면
                if count == 0:
                    
                    end_point = col
                count += 1
            if count and arr[row][col] == '0':
                count += 1
        # 바뀌는 횟수 탁월했다.
        if change == 4:
            print(count)
            widths.append([count // 7, end_point]) # 리스트를 전체적으로 담아서 리턴하는게 맛이있네. 내가 마지막에 하려했던 방식과 비슷한데 4번 바뀌는 방식이란게 특이함

            
    return widths

def scanner(bin_arr, width_list):

    for row in range(len(bin_arr)):
        step, point = width_list[row]
        while bin_arr[row]:
            print(bin_arr[row])
            binary = bin_arr[row][point - 56 * step + 1 : point + 1]
            # print(binary)
            pw_lst = []
            for i in range(8):
                bitnumber = binary[i * 7: (i + 1) * 7]
                if bitnumber:
                    pw_lst.append(bitnumber)
                    print(bitnumber)
            bin_arr[row] = bin_arr[row][:point - 56 * step + 1].rstrip('0')


            

for tc in range(1, T + 1):
    N, M = map(int, input().split())
    lst = list(set(input().strip('0') for _ in range(N)))
    # print(lst)
    print(lst)
    arr = hex_to_bin(lst)
    width = get_width(arr)
    print(width)
    #그래 마지막 숫자정보를 통해서 7의 몇 배수인지를 확인, 
    scanner(arr,width)