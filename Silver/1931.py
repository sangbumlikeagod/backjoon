
import sys
f = open('1931.txt', 'r', encoding='utf-8')
sys.stdin = f

test_case = int(input())


def get_diclen(dic):
    length = 0
    for i in dic:
        length += len(dic[i])
    return length


def get_max_dic(dic):
    max = 0
    idx = 0
    for i in dic:
        if len(dic[i]) > max:
            max = len(dic[i])
            idx = i
    return idx
dic = {}

# 그러면 하나 할때마다 만들 수 있다는 건데요
# 

for num in range(test_case):
    
    tu = tuple(map(int,input().split()))
    dic[tu] = dic.get(tu, [])
    for arg in dic:
        if arg == tu:
            continue
        
        # print( arg[0] < tu[0] < arg[1],  tu[1] > arg[0], (tu[0] > arg[0] and tu[1] < arg[1]), (tu[0] < arg[0] and tu[1] > arg[1]))
        if arg[0]<= tu[0] < arg[1] or tu[1] > arg[0] >= tu[0] or (tu[0] > arg[0] and tu[1] < arg[1]) or (tu[0] < arg[0] and tu[1] > arg[1]):
            
            dic[arg] += [tu]
            dic[tu] += [arg]
            
    
while get_diclen(dic):
    max_key = get_max_dic(dic)
    
    for i in dic.get(max_key):
        
        dic[i].remove(max_key)
    dic.pop(max_key)

print(len(dic))







