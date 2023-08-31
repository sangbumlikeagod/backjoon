import sys
import itertools
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
inning = int(sys.stdin.readline())
sett = itertools.permutations(range(1, 9))


inning_result = [list(map(int, sys.stdin.readline().split())) for _ in range(inning)]

max_result = 0
for tasuk in sett:
    tasuk = [tasuk[0], tasuk[1], tasuk[2], 0, tasuk[3], tasuk[4], tasuk[5], tasuk[6], tasuk[7]]
    # print(tasuk)
    score = 0
    next = 0
    
    # print(base)
    for num in range(inning):
        if max_result - (inning - num) * 24 > score:
            break
        b1, b2, b3 = 0, 0, 0
        out_count = 0
        while out_count < 3:
            # print(base, inning_result[num][tasuk[next]] )
            if inning_result[num][tasuk[next]] == 0:
                # print('꺅', base)
                out_count += 1
            elif inning_result[num][tasuk[next]] == 1:
                score += b3
                b1, b2, b3 = 1, b1, b2
                # base = [1, base[0], base[1]]
            elif inning_result[num][tasuk[next]] == 2:
                score += b3 + b2
                b1, b2, b3 = 0, 1, b1
            elif inning_result[num][tasuk[next]] == 3:
                score += b1 + b2 + b3
                b1, b2, b3 = 0, 0, 1
            else:
                score += b1 + b2 + b3 + 1
                b1, b2, b3 = 0, 0, 0
                
            next = (next + 1) % 9
    if score > max_result:
        max_result = score

print(max_result)
# print(a)

# new_game = game(tasuk)
# for num in range(inning):
#     new_game.inning(num)              

# 남은이닝에서 한 이닝당 득점할 최고점수 보다 낮으면
# 4 4 4 4 4 4 4 4 
# 8 1아웃 8 1아웃 8 1아웃 이게 최고임 
# 지금 점수가 남은 이닝 모두 24점씩 얻는 경우보다 낮으면 하지마 