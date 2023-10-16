import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
import sys
st = sys.stdin.readline

desire = desire_digit = int(st())
M = int(st())
# error = set(map(int, st().split()))
error = set(st().split())
available = {'0', '1' ,'2', '3', '4', '5', '6', '7', '8', '9'} - error
# print(available)
basic = abs(desire - 100)
key = 0
num = float('inf')
while True:
    if key >= basic:
        # print(key)
        break 
    if desire - key >= 0 and set(list(str(desire - key))) <= available:
        num = key + len(str(desire - key))
        # print(key)
        break
    if set(list(str(desire + key))) <= available:
        num = key + len(str(desire + key))
        # print(key)
        break
    key += 1
print(min(basic, num))