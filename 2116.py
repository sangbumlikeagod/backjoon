
import sys
f = open('2116.txt', 'r', encoding='utf-8')
sys.stdin = f

import sys

sys.setrecursionlimit(300000)
dice_relation = {0: 5,
                 5: 0,
                 1: 3,
                 3: 1,
                 2: 4,
                 4: 2}

tower_of_dice = int(input())


# 주어진값 빼고 최대값 구하기


def section_sum(idx, lst):
    new_lst = [lst[i] for i in range(len(lst)) if i != idx and i != dice_relation[idx]]
    max_noon = 0
    for small_i in new_lst:
        if small_i > max_noon:
            max_noon = small_i
    return max_noon


dice_lst = []
for dice in range(tower_of_dice):
    dice_lst.append(list(map(int, input().split())))

first_case = dice_lst[0]


def dice_pile(top_of_former_dice, dice_idx):
    new_dic = {}

    for i in range(len(dice_lst[dice_idx])):
        new_dic[dice_lst[dice_idx][i]] = i

    new_dic.get(top_of_former_dice)

    banned_idx = dice_relation[new_dic.get(top_of_former_dice)]

    if dice_idx == tower_of_dice - 1:
        return section_sum(banned_idx, dice_lst[dice_idx])

    return section_sum(banned_idx, dice_lst[dice_idx]) + dice_pile(dice_lst[dice_idx][banned_idx], dice_idx + 1)


ans_list = []

for i in range(len(first_case)):
    ans_list.append(dice_pile(first_case[i], 1) + section_sum(i, first_case))

print(max(ans_list))