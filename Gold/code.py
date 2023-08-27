import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

test_case = int(input())
test_case = 10

dic = {
    int('0b1101' ,base= 0) : 0,
    int('0b11001' ,base = 0) : 1,
    int('0b10011' , base = 0) : 2,
    int('0b111101' , base = 0) : 3,
    int('0b100011' ,base = 0) : 4,
    int('0b110001' ,base = 0) : 5,
    int('0b101111' ,base = 0) : 6,
    int('0b111011' ,base = 0) : 7,
    int('0b110111',base = 0) : 8,
    int('0b1011' ,base = 0) : 9,
    }

for case in range(test_case):
    row, column = map(int,input().split())
    lst = [list(input().strip()) for _ in range(row)]
    
    # 리스트 구현
    # print(len(lst), len(lst[0]))
    
    # print(int('0b100', base=2 ))
    # print(dic)
    return_value = 0
    for col in range(column - 1, -1, -1):
        begin_lst = []
        for ro in range(row - 1, -1, -1):
            # print(ro, col)
            if lst[ro][col] != '0':
                end = ro - 1
                while end > 0 and lst[end][col] == lst[ro][col]:
                    end -= 1
            # 이제 여기서 첫 문자에 한해서만 처리를 하고 
                begin_lst.append([ro, end, col])
                not_find = True
                
                # 스텝의 간격을 찾는다.
                print(begin_lst)
                while begin_lst:
                    step = 0
                    ro, end, col = begin_lst.pop()
                    while not_find:
                        step += 1
                        word = ''
                        tmp = col
                        cond = True
                        comp = 0
                        while cond:
                            hexa = bin(int(lst[ro][tmp], base = 16))[2:].zfill(4)
                            if not word:
                                hexa = hexa.rstrip('0')
                            print(hexa, word)
                            for i in range(len(hexa) - 1 + comp, -1, -step):
                            # for i in hexa:
                                word = hexa[i] + word
                                if len(word) == 7:
                                    cond = False
                                    break
                            else:
                                print('\t\t' , i)
                                # if i != 0:
                                comp = i - step + 1
                                
                            tmp -= 1
                        
                        # print(word)
                        if int(f'0b{word}' , base=0) in dic:
                            print(dic[int(f'0b{word}' , base=0)])
                            not_find = False
                    print(step)
                    true_code = ''
                    
                    tmp = col
                    word = ''
                    comp = 0
                    while len(true_code) < 8:
                        print(comp)
                        cond = True
                        
                        while cond:
                            hexa = bin(int(lst[ro][tmp], base = 16))[2:].zfill(4)
                            if tmp == col:                                hexa = hexa.rstrip('0')
                            print(hexa, word)
                            for i in range(len(hexa) - 1 + comp, -1, -step):
                                word = hexa[i] + word
                                if len(word) == 7:
                                    print(word, end= ' \n\n')
                                    cond = False
                                    # print(word)
                                    true_code += str(dic[int(f'0b{word}' , base=0)])
                                    ttmp = i
                                    word = ''
                                    # if ttmp < 0:
                                    #     comp = -step + 1
                                    #     break
                                        
                                    while ttmp - step >= 0:
                                        ttmp -= step
                                        word = hexa[ttmp] + word
                                    
                                    # if ttmp < 0:
                                    #     comp = -step + 1
                                    #     break
                                    # word = hexa[:i:step]
                                    # word = ''
                                    comp = ttmp - step + 1
                                    # print(word)
                                    break
                            else:
                                comp = i - step + 1
                            for i in range(end, ro + 1):
                                lst[i][tmp] = '0'
                            tmp -= 1
                    new_lst = list(map(int, list(true_code)))
                    if not ((new_lst[0] + new_lst[2] + new_lst[4] + new_lst[6]) + 3 * (new_lst[1] + new_lst[3] + new_lst[5] + new_lst[7])) % 10:
                        return_value += sum(new_lst)
                    
                # print(true_code)
                # print(*lst, sep='\n')
                    

                
                
                
                

                        
    print(f'#{case + 1} {return_value}')
                    
                    # print(bin(int(lst[ro][col], base = 16))[2:].zfill(4))s
                    
                    # print(lst[ro][col])
                    # 첫번째 요소에 한해서 
                    
                    # not_find = False
                
    