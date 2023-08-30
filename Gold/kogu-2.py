import sys
import itertools
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
inning = int(sys.stdin.readline())
[1,2,3,4,5,6,7,8]
sett = itertools.permutations([1,2,3,4,5,6,7,8])


inning_result = [list(map(int, sys.stdin.readline().split())) for _ in range(inning)]

class game:
    def __init__(self, tasuk) -> None:
        self.next = 0
        self.score = 0
        self.tasuk = tasuk
    def inning(self, num):
        
        out_count = 0
        record = []
        while out_count < 3:
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
for tasuk in sett:
    tasuk = [tasuk[0], tasuk[1], tasuk[2], 0, tasuk[3], tasuk[4], tasuk[5], tasuk[6], tasuk[7]]
    print(tasuk)
    score = 0
    next = 0
    base = [0] * 3
    for num in range(inning):
        if max_result - (inning - (num + 1)) * 24 > score:
            continue
        out_count = 0
        while out_count < 3:
            # print(next)
            if inning_result[num][tasuk[next]] == 0:
                out_count += 1
            elif inning_result[num][tasuk[next]] == 1:
                score += base[2]
                base = [1, base[0], base[1]]
            elif inning_result[num][tasuk[next]] == 2:
                score += base[2] + base[1]
                base = [0, 1, base[1]]
            elif inning_result[num][tasuk[next]] == 3:
                score += sum(base)
                base = [0, 0, 0]
            else:
                score += sum(base) + 1
                base = [0, 0, 0]
            next = (next + 1) % 9
    if score > max_result:
        max_result = score




        # print(tasuk)


    # new_game = game([tasuk[0], tasuk[1], tasuk[2], 0, tasuk[3], tasuk[4], tasuk[5], tasuk[6], tasuk[7]])
    # for num in range(inning):
    #     if max_result - (inning - (num + 1)) * 24 > new_game.score:
    #         continue
    #     new_game.inning(num)
    # if new_game.score > max_result:
    #     max_result = new_game.score
    #     a = tasuk


print(max_result)
# print(a)
# new_game = game(tasuk)
# for num in range(inning):
#     new_game.inning(num)              

# 남은이닝에서 한 이닝당 득점할 최고점수 보다 낮으면
# 4 4 4 4 4 4 4 4 
# 8 1아웃 8 1아웃 8 1아웃 이게 최고임 
# 지금 점수가 남은 이닝 모두 24점씩 얻는 경우보다 낮으면 하지마 