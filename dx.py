
dic = {}
Data = [0,4,1,3,1,2,4,1]
for i in Data:
    dic[i] = dic.get(i,0) + 1

print(dic)
counts = [0]*len(dic)
for i in dic:
    counts[i] = dic[i]
print(counts)

counts = [sum(counts[:i+1]) for i in range(len(counts))]
print(counts)

size = len(Data)


def counting_sort(lst, count):
    print(lst, count)
    if not lst:
        return [0] * size
    a = lst.pop()
    state = count[a]
    count[a] -= 1
    tmp = counting_sort(lst, count)
    print(tmp)
    tmp[state-1] = a
    return tmp


print(counting_sort(Data, counts))

# given list
lst = [1,2,3,4,4,4]
size = len(lst)

lst2 = [1,2,3,4,5,6,7,7,8,7]

def isbabygin(ans,lst):
    ans.append(lst.pop())

    if len(ans) == 3:
        if ans[0] - ans[1] != ans[1] - ans[2]:
            return False
        else:
            ans = []

    if not lst:
        return not ans

    return isbabygin(ans, lst)


print(isbabygin([], lst))
print(isbabygin([], lst2))




