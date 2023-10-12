import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
import sys
st = sys.stdin.readline

# 가지수를 한가지로 줄인다?

# 브루트포스나 전부안됨

# 0번을 아예 안누를 거라면 0이 달라지면 

N = int(st())

# CURRENT = list(map(int, list(st().strip())))
# DESIRE =  list(map(int, list(st().strip())))
CURRENT = list(map(int, list(input())))
DESIRE =  list(map(int, list(input())))

CURRENT_0 = CURRENT[:]
CURRENT_0[0] = 1 - CURRENT_0[0]
CURRENT_0[1] = 1 - CURRENT_0[1]

def change(lst, pointer):
    lst[pointer] = 1 - lst[pointer]
    lst[pointer - 1] = 1 - lst[pointer - 1]
    if pointer != N - 1:
        lst[pointer + 1] = 1 - lst[pointer + 1]

def run(lst, ct):
    for i in range(1, N):
        if lst[i - 1] == DESIRE[i - 1]:
            continue
        ct += 1
        change(lst, i)
    return ct if lst == DESIRE else float('inf')
        
tmp1 = run(CURRENT, 0)
tmp2 = run(CURRENT_0, 1)

ans = min(tmp1, tmp2)

if ans != float('inf'):
    print(ans)
else:
    print(-1)