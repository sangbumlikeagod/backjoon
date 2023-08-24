
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')



# def attach(lst1, lst2):
    
for i in range(4):
    ans = []
    rectangles = list(map(int, input().split()))
    v1 = [rectangles[0], rectangles[2]]
    v2 = [rectangles[4], rectangles[6]]
    h1 = [rectangles[1], rectangles[3]]
    h2 = [rectangles[5], rectangles[7]]
    if v2[0] < v1[0]:
        v1, v2, h1, h2 = v2, v1, h2, h1
    if v1[1] == v2[0]:
        ans.append('b')
    elif v2[0] < v1[1]:
        ans.append('a')
    else:
        ans.append('d')
    # print(v1, v2)
    # print(h1, h2)
    if h2[0] < h1[0]:
        v1, v2, h1, h2 = v2, v1, h2, h1
    if h1[1] == h2[0]:
        ans.append('b')
    elif h2[0] < h1[1]:
        ans.append('a')
    else:
        ans.append('d')
    # print(ans)
    if 'd' in ans:
        print('d')

    elif 'b' in ans:
        if ans.count('b') == 2:
            print('c')
        else:
            print('b')
    elif 'a' in ans:
        print('a')