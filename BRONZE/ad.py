print(ord('a'))
print(ord('z') - ord('a'))


word = 'baekjoon'
lst = [-1] * 26

for i in range(len(word)):

    if lst[ord(word[i]) - 97] == -1:
        lst[ord(word[i]) - 97] = i

  
print(' '.join(map(str, lst)))


test_case = int(input())

def good(num):
    if num in dic:
        return dic[num]
    else:
        mt = 3
        local = 0
        while mt > 0:
            if num >= mt:
                local += good(num - mt)
            mt -= 1
        dic[num] = local
        return local    

dic = {0 : 1}     
for _ in range(test_case):
    N = int(input())
    print(good(N))


    