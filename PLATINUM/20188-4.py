import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
st = sys.stdin.readline
sys.setrecursionlimit(400000)
N = int(st())
dic = {}
for i in range(N - 1):
    a, b = map(int, st().split())
    dic[a] = dic.get(a, []) + [b]
    dic[b] = dic.get(b, []) + [a]


visited = [0] * (N + 1)

count = 0



count = 0 

def dfs(node, layer, valueofbro, numofbro): 
    global count
    # print(node, layer, valueofbro, numofbro)
    visited[node] = 1
    base_value = valueofbro 
    base_brother_num = numofbro
    count += base_value + base_brother_num
    # print(f'{node} \t {base_value + base_brother_num} 를 더함')
    layer_val = 0
    layer_bro = 0

    for i in dic[node]:
        if not visited[i]:
            if len(dic[i]) == 1: 
                # print('여긴 지나감')
                count += layer + 1 + base_value + base_brother_num + layer_val + base_brother_num + layer_bro
                layer_bro += 1
                layer_val += layer + 1
            else:
                forparent, forb = dfs(i, layer + 1, base_value + base_brother_num+ layer_val, base_brother_num + layer_bro)
                layer_bro += forb
                count += forparent
                layer_val += forparent
    return (layer_val, layer_bro + 1)



def dfs(node, layer, forbrother): 
    global count
    visited[node] = 1
    print(node, layer, forbrother)
    brother = 0
    for_return = 0
    for_this_brother = 0
    count += forbrother
    for i in dic[node]:
        if not visited[i]:
            forparent, forb = dfs(i, layer + 1, forbrother + for_this_brother)
            print('\t', forparent, forb)
            for_this_brother += forb - 1 + forparent + 2
            for_return += forparent + layer + 1
            brother += forb

    count += for_return
    print('\t\t',count, node)
    return (for_return , brother + 1)


def dfs(node, layer, valueofbro, numofbro): 
    global count
    # print(node, layer, valueofbro, numofbro)
    visited[node] = 1
    base_value = valueofbro 
    base_brother_num = numofbro
    count += base_value + base_brother_num
    # print(f'{node} \t {base_value + base_brother_num} 를 더함')
    layer_val = 0
    layer_bro = 0

    for i in dic[node]:
        if not visited[i]:
            if len(dic[i]) == 1: 
                # print('여긴 지나감')
                count += layer + 1 + base_value + base_brother_num + layer_val + base_brother_num + layer_bro
                layer_bro += 1
                layer_val += layer + 1
            else:
                forparent, forb = dfs(i, layer + 1, base_value + base_brother_num+ layer_val, base_brother_num + layer_bro)
                layer_bro += forb
                count += forparent
                layer_val += forparent
    return (layer_val + layer, layer_bro + 1)


dfs(1, 0, 0, 0)
print(count)

print(count)
