import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline

testcase = int(st())
for i in range(testcase):
    N, M, W = map(int, input().split())
