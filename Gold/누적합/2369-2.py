import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')

M, N, K = map(int, input().split())

'''

3 * 4 를 예로 들어보자 
1개의 줄에 
1111 222 33 4 이런 순으로 부분행렬이 나옴
그리고 저 1개당 3개의 줄에 대해서 반복됨
'''

# for i in range()