
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')



def attach(lst1, lst2):
    
for i in range(4):
    rectangles = list(map(int, input().split()))
    v1 = [rectangles[0], rectangles[2]]
    v2 = [rectangles[4], rectangles[6]]
    h1 = [rectangles[1], rectangles[3]]
    h2 = [rectangles[5], rectangles[7]]
    

    