import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')

test_case = int(input())
test_case = 10
for num in range(test_case):
    # if num == 12:
    #     continue
    return_value = 0
    N, M = map(int, input().split())
    lst = set(input().strip().strip('0') for _ in range(N))
    # print(lst)
    dic = {
        13: 0,
        25: 1,
        19: 2,
        61: 3,
        35: 4,
        49: 5,
        47: 6,
        59: 7,
        55: 8,
        11: 9
    }
    lst -= {''}

    # 리스트들에 대해서 마지막을 잡고 이진수로 바꿈 
    for suspect in lst:
        print(suspect)

        step = 0
        not_find = True
        while not_find:
            step += 1
            tmp = len(suspect) - 1
            cond = True
            comp = 0
            word = ''
            while cond and tmp >= 0:
                # print(suspect)
                hexa = bin(int(suspect[tmp], base = 16))[2:].zfill(4)
                
                if tmp == len(suspect) - 1:
                    hexa = hexa.rstrip('0')
                # print(hexa)
                for i in range(len(hexa) - 1 + comp, -1, -step):
                    word = hexa[i] + word
                    if len(word) == 7:
                        cond = False
                        break
                else:
            # print('\t\t' , i, '\t' , step, comp)
            # if i != 0:
                    comp = i - step + 1
                    while abs(comp) >= 4:
                        tmp -= 1
                        comp += 4
                tmp -= 1
                # break
            if int(f'0b{word}' , base=0) in dic:
                            # print(dic[int(f'0b{word}' , base=0)])
                not_find = False
        print(word, step)
        
        suspect.zfill(step * 56 // 4 + 1)
        print(bin(int(suspect, base = 16))[2:])
        length = len(bin(int(suspect, base = 16))[2:])
        binnnn = bin(int(suspect, base = 16))[2:]
        local = ''
        true_code = []
        for i in range(length, -1, -step):

            local += binnnn[i]
            if len(local) == 7:
                true_code.append(dic[local])
                local == ''
        print(dic)
        print(suspect)
    print(f'#{num + 1} {return_value}')
            # break




        # # print(hexa, word, tmp)
        # for i in range(len(hexa) - 1 + comp, -1, -step):
        #     word = hexa[i] + word
        #     if len(word) == 7:
        #         print(word, end= ' \n\n')
        #         cond = False
        #         # print(word)
        #         true_code += str(dic[int(f'0b{word}' , base=0)])
        #         ttmp = i
        #         word = ''
        #         # if ttmp < 0:
        #         #     comp = -step + 1
        #         #     break
                
        #         while ttmp - step >= 0:
        #             ttmp -= step
        #             word = hexa[ttmp] + word
                
        #         # if ttmp < 0:
        #         #     comp = -step + 1
        #         #     break
        #         # word = hexa[:i:step]
        #         # word = ''
        #         comp = ttmp - step + 1
        #         while abs(comp) >= 4:
        #             for i in range(end, ro + 1):
        #                 lst[i][tmp] = '0'
        #             tmp -= 1
        #             comp += 4
        #         # print(word)
        #         # print(word, comp)
        #         break
        # else:
        #     comp = i - step + 1
        #     while abs(comp) >= 4:
        #             for i in range(end, ro + 1):
        #                 lst[i][tmp] = '0'
        #             tmp -= 1
        #             comp += 4
        # for i in range(end, ro + 1):
        #     lst[i][tmp] = '0'
        # tmp -= 1
        




# if not word:
#     hexa = hexa.rstrip('0')
# # print(hexa, word, tmp)
# for i in range(len(hexa) - 1 + comp, -1, -step):
# # for i in hexa:
#     word = hexa[i] + word
#     if len(word) == 7:
#         cond = False
#         break
# else:
#     # print('\t\t' , i, '\t' , step, comp)
#     # if i != 0:
#     comp = i - step + 1
#     while abs(comp) >= 4:
#         tmp -= 1
#         comp += 4
