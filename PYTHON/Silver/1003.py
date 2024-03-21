import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

testcase = int(st())
dic = {0 : (1, 0),
       1 : (0, 1)}

def dp(num):
    if num in dic:
        return dic[num]
    else:
        n1 = dp(num - 1)
        n2 = dp(num - 2)
        dic[num] = ((n1[0] + n2[0]), (n1[1] + n2[1]))
        return dic[num]
    
for _ in range(testcase):
    s = int(st())
    print(' '.join(map(str, dp(s))))