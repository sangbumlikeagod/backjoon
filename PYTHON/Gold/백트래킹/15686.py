import sys
sys.stdin = open(__file__.split('''\\''')[-1][:-3] + '.txt','r')
import sys
import itertools
st = sys.stdin.readline
sys.setrecursionlimit(100000)
is_testing = False

N, M = map(int, st().split())

houses = []
chicken = []
minn = 2 * N ** 2 * M

for i in range(N):
    row = list(map(int, st().split()))
    for j in range(N):
        if row[j] == 1:
            houses.append((i, j))
        elif row[j] == 2:
            chicken.append((i, j))

if is_testing:
    print(houses)
    print(chicken)

current_chicken = len(chicken)
if is_testing:
    print(current_chicken)


'''
최대 M개의 조합을 만든다.
'''

def combination(pointer, gaesu, sofar):
    if gaesu == 0:
        if is_testing:
            print(sofar)
        try:
            tmp = chicken_distance(sofar)
            if tmp:
                global minn
                minn = tmp
                if is_testing:
                    print(minn, sofar)
            return
        except:
            pass
    for i in range(pointer, current_chicken - gaesu + 1):
        sofar.append(i)
        combination(i + 1, gaesu - 1, sofar)
        sofar.pop()


def chicken_distance(comb):
    total_distance = 0
    for house in houses:
        local_minn = 2 * N
        for idx in comb:
            local_minn = min(local_minn, abs(house[0] - chicken[idx][0]) + abs(house[1] - chicken[idx][1]))
        total_distance += local_minn
        if total_distance >= minn:
            return False
    return total_distance 


# while M:
#     combination(0, M, [])
#     M -= 1

    
while M:
    # combination(0, M, [])
    for i in itertools.combinations(range(current_chicken), M):
        tmp = chicken_distance(i)
        if tmp:
            minn = tmp
    M -= 1

print(minn)