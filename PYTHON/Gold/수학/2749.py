N = int(input())


def vector(a, b):

    int_a_x = int(a[0])
    int_a_y = int(a[1])
    
    int_b_x = int(b[0])
    int_b_y = int(b[1])
    
    # (a[0] , a[1]) * (b[0] , b[1]) 
    # (a[0] * b[0] + a[1] * b[1] * 5, a[1] * b[0] + b[1] * a[0])
    h1 = (int_a_x * int_b_x) % 1000000 \
        + (0.5 * 0.5)\
        + (int_a_x * 0.5) % 1000000 \
        + (int_b_x * 0.5) % 1000000
    h2 = ((int_a_y * int_b_y) % 1000000\
        + (0.5 * 0.5)\
        + (int_a_y * 0.5) % 1000000\
        + (int_b_y * 0.5) % 1000000) * 5
    h3 = (int_a_y * int_b_x) % 1000000\
        + (0.5 * int_a_y) % 1000000\
        + (int_b_x * 0.5) % 1000000\
        + (0.5 * 0.5)
    h4 = (int_b_y * int_a_x) % 1000000\
        + (0.5 * int_b_y) % 1000000\
        + (int_a_x * 0.5) % 1000000\
        + (0.5 * 0.5)
    return ((h1 + h2) % 1000000, (h3 + h4) % 1000000)


dic = {
    0 : (0.5, 0.5)
    }

n = 0
start = None
while 1 << n <= N:
    if n not in dic:
        dic[n] = vector(dic[n - 1], dic[n - 1])
    if 1 << n & N:
        # print(n)
        if not start:
            start = dic[n]
        else:
            start = vector(start, dic[n])
    n += 1
    
# print(start)
print(int(start[1] * 2) % 1000000)
print(dic)


N = int(input())


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
    h1 = (int_a_x * int_b_x) % 1000000 \
        + (flo_a_x * flo_b_x) % 1000000 \
        + (int_a_x * flo_b_x) % 1000000 \
        + (int_b_x * flo_a_x) % 1000000
    h2 = ((int_a_y * int_b_y) % 1000000\
        + (flo_a_y * flo_b_y) % 1000000\
        + (int_a_y * flo_b_y) % 1000000\
        + (int_b_y * flo_a_y) % 1000000) * 5
    h3 = (int_a_y * int_b_x) % 1000000\
        + (flo_b_x * int_a_y) % 1000000\
        + (int_b_x * flo_a_y) % 1000000\
        + (flo_a_y * flo_b_x) % 1000000
    h4 = (int_b_y * int_a_x) % 1000000\
        + (flo_a_x * int_b_y) % 1000000\
        + (int_a_x * flo_b_y) % 1000000\
        + (flo_b_y * flo_a_x) % 1000000
    return ((h1 + h2) % 1000000, (h3 + h4) % 1000000)


dic = {
    0 : (0.5, 0.5)
    }

n = 0
start = None
while 1 << n <= N:
    if n not in dic:
        dic[n] = vector(dic[n - 1], dic[n - 1])
    if 1 << n & N:
        # print(n)
        if not start:
            start = dic[n]
        else:
            start = vector(start, dic[n])
    n += 1
    
# print(start)
print(int(start[1] * 2) % 1000000)