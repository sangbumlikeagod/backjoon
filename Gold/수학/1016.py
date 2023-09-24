
min_i, max_i = 1, 1000

def prime(arg):

    for i in range(2, int(max_i**(1/2))+1):
        if i ** 2 > arg:
            return True
        else:
            if arg % i ** 2 == 0:
                return False
    return True

def nonosquare(min_i, max_i):
    ans = 0
    for i in range(min_i, max_i+1):
        ans += prime(i) * 1
        # print(ans, i)
        
    return ans

# print(nonosquare(1, 1000))