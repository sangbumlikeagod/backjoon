import itertools
'''

입력값 : 이닝수 & 각 이닝별 각 타석의 결과
출력값 : 받을 수 있는 최대의 정수

가정 1 : 첫번째이닝엔 무조건 치는 사람들로만 구성해야 하나 X

타석 순으로
1회 : 4 0 0 0 0 0 0 0 0
2회 : 0 0 0 0 0 0 4 4 4

1회에 치는애들을 우선적으로 넣으면 
다음회에 어긋날 수 있음

일단 4만개에 이르는 배열이 너어어무 많다. 
'''
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')


inning = int(input())

'''

8개의 원소들 (2 ~ 9번)을 
지금 x - 1 

'''
itertools.permutations

def make_permutation(num):
    # print(num)
    if num == 0:
        return [{0 : 3}]
    ans = []
    for i in range( len(bin(num)) - 2):
        if (1 << i) & num:
            lst = make_permutation(num - (1 << i))
            for idx in range(len(lst)):
                if len(lst[idx]) < 3:
                    lst[idx][len(lst[idx])] = i
                else:
                    lst[idx][len(lst[idx])] = i
                ans.append(lst[idx])

    return ans

# print(len(make_permutation(2 ** 8 - 1)))

# tasuk = make_permutation(2 ** 8 - 1)
# tasuk_with_0 = []
# for i in tasuk:
#     tasuk_with_0 += [i[:3] + [0] + i[3:]]

tasuk_with_0 = (make_permutation(2 ** 9 - 1 - 2 ** 3))
# print(len(tasuk_with_0))
# print(tasuk_with_0)

# print(tasuk_with_0)

# 모든 타석 구현엔 성공했으니 각 타석별로 크기를 봅시다

inning_result = [list(map(int, input().split())) for _ in range(inning)]

class game:
    def __init__(self, tasuk) -> None:
        self.next = 0
        self.score = 0
        self.tasuk = tasuk
    def inning(self, num):
        out_count = 0
        record = []
        while out_count < 3:
            # print(inning_result[num][self.tasuk[self.next]])
            if inning_result[num][self.tasuk[self.next]] == 0:
                out_count += 1
            else:
                for i in range(len(record)):
                    # print('\t', i)
                    if record[i] < 4:
                        record[i] += inning_result[num][self.tasuk[self.next]]
                        # print(i)
                        
                record.append(inning_result[num][self.tasuk[self.next]])
            self.next = (self.next + 1) % 9
        for i in record:
            if i >= 4:
                self.score += 1
        # print(self.score, record)

max_result = 0
for tasuk in tasuk_with_0:
    new_game = game(tasuk)
    for num in range(inning):
        new_game.inning(num)
    if new_game.score > max_result:
        max_result = new_game.score
    # break

print(max_result)

                    

        

        








