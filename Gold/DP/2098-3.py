import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
sys.setrecursionlimit(10000)