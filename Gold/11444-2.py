import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')


N = int(input())
dic = {
    0 : (0.5, 0.5)
    }

n = 0
start = None
while 1 << n <= N:
    if n not in dic:
        a, b = dic[n - 1]
        # print(a, b)
        # print((a ** 2 + 5 * b ** 2) , round((a ** 2 + 5 * b ** 2), 100), (round(a, 18) ** 2 + 5 * round(b, 18) ** 2 * 5 ))
        # print(round((round(a, 100) ** 2 + 5 * round(b, 18) ** 2),19) % 1000000007)
        # print(round((2 * round(a, 18) * round(b, 18)), 18) % 1000000007)
        dic[n] = (round((round(a, 100) ** 2 + 5 * round(b, 18) ** 2),19) % 1000000007, round((2 * round(a, 18) * round(b, 18)), 18) % 1000000007)
    if 1 << n & N:
        if not start:
            start = dic[n]
        else:
            start = ((round(start[0], 18) * round(dic[n][0], 18) + round(start[1], 18) * round(dic[n][1], 18) * 5) % 1000000007, (round(dic[n][0], 18) * round(start[1], 18) + round(dic[n][1], 18) * round(start[0], 18)) % 1000000007)
                
    n += 1
    
print(int(start[1] * 2) % 1000000007)

print(dic)


# def vector(lst):
#     start = dic[lst.pop()]
#     while lst:
#         # print(start)
#         tmp = dic[lst.pop()]
#         start = ((start[0] * tmp[0] + start[1] * tmp[1] * 5) % 1000000007, (start[1] * tmp[0] + start[0] * tmp[1]) % 1000000007)
#     return start

# a = 575165669.5
# b = 104891726.5
# print( (a ** 2 + 5 * b ** 2) , (a * b* 2) )
# print( ((round(a, 0) ** 2 + round(b, 0) ** 2 * 5) % 1000000007, (a * b* 2) % 1000000007))
# print( (round(a ** 2, 18) + round(5 * b ** 2, 18)) % 1000000007, (a * b* 2) % 1000000007)
# print( (a ** 2 + 5 * b ** 2) % 1000000007, (a * b* 2) % 1000000007)

# print(a, (a - int(a)) ** 2 % 1000000007 + int(a) ** 2 % 1000000007 + 2 * int(a) * (a - int(a)) % 1000000007)
# print(a ** 2 % 1000000007)
# print(round(a ** 2, 10) % 1000000007)


def vector(a, b):
    int_a_x = int(a[0])
    flo_a_x = a[0] - int_a_x
    int_a_y = int(a[1])
    flo_a_y = a[1] - int_a_y
    
    int_b_x = int(b[0])
    flo_b_x = b[0] - int_b_x
    int_b_y = int(b[1])
    flo_b_y = b[1] - int_b_y
    
    # (a[0] , a[1]) * (b[0] , b[1]) 
    # (a[0] * b[0] + a[1] * b[1] * 5, a[1] * b[0] + b[1] * a[0])
    h1 = (int_a_x * int_b_x) % 1000000007 \
        + (flo_a_x * flo_b_x) % 1000000007 \
        + (int_a_x * flo_b_x) % 1000000007 \
        + (int_b_x * flo_a_x) % 1000000007
    h2 = ((int_a_y * int_b_y) % 1000000007\
        + (flo_a_y * flo_b_y) % 1000000007\
        + (int_a_y * flo_b_y) % 1000000007\
        + (int_b_y * flo_a_y) % 1000000007) * 5
    h3 = (int_a_y * int_b_x) % 1000000007\
        + (flo_b_x * int_a_y) % 1000000007\
        + (int_b_x * flo_a_y) % 1000000007\
        + (flo_a_y * flo_b_x) % 1000000007
    h4 = (int_b_y * int_a_x) % 1000000007\
        + (flo_a_x * int_b_y) % 1000000007\
        + (int_a_x * flo_b_y) % 1000000007\
        + (flo_b_y * flo_a_x) % 1000000007
    return ((h1 + h2) % 1000000007, (h3 + h4) % 1000000007)


dic = {
    0 : (0.5, 0.5)
    }

n = 0
start = None
while 1 << n <= N:
    if n not in dic:
        dic[n] = vector(dic[n - 1], dic[n - 1])
    if 1 << n & N:
        print(n)
        if not start:
            start = dic[n]
        else:
            start = vector(start, dic[n])
    n += 1
    
print(start)
print(int(start[1] * 2) % 1000000007)
print(dic)